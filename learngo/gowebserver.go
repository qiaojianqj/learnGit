/*
//first: go run gowebserver.go
//then:open the link: localhost:8080 in browser
//besides:open the link: localhost:8080/something in browser, will print something
package main

import (
	"fmt"
	"log"
	"net/http"
)

func HelloServer(w http.ResponseWriter, req *http.Request) {
	fmt.Println("Inside HelloServer handler")
  fmt.Fprintf(w, "<head><title>Welcome QJ</title><body>Welcome to the go web learning;</body></head>")
	fmt.Fprintf(w, "Hello,"+req.URL.Path[1:])
}

func main() {
	http.HandleFunc("/", HelloServer)
	err := http.ListenAndServe("localhost:8080", nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err.Error())
	}
}
*/

//first: go run gowebserver.go
//then:open the link: localhost:8088/test1(2) in browser
package main

import (
	"fmt"
	"io"
	"net/http"
	"strings"
)

const form = `
	<html><body>
		<form action="#" method="post" name="bar">
			<input type="text" name="in" />
			<input type="submit" value="submit"/>
		</form>
	</body></html>
`

var times = 0

/* handle a simple get request */
func SimpleServer(w http.ResponseWriter, r *http.Request) {
	times++
	fmt.Printf("test1 get times: %d\n", times)
	fmt.Fprintf(w, "<h1>hello, world! GET times: %d</h1>", times)
	r.ParseForm()
	fmt.Println(r.Form)
	fmt.Println("path:", r.URL.Path)
	fmt.Println("scheme:", r.URL.Scheme)
	//http://localhost:8088/?url_long=111&url_long=222
	fmt.Println(r.Form["url_long"])
	for k, v := range r.Form {
		fmt.Println("key:", k)
		fmt.Println("val:", strings.Join(v, ""))
	}
}

func FormServer(w http.ResponseWriter, request *http.Request) {
	w.Header().Set("Content-Type", "text/html")
	switch request.Method {
	case "GET":
		/* display the form to the user */
		fmt.Printf("test2 get\n")
		io.WriteString(w, form)
	case "POST":
		/* handle the form data, note that ParseForm must
		   be called before we can extract form data */
		//request.ParseForm();
		//io.WriteString(w, request.Form["in"][0])
		fmt.Printf("test2 post\n")
		io.WriteString(w, request.FormValue("in"))
	}
}

func main() {
	http.HandleFunc("/", SimpleServer)
	http.HandleFunc("/test2", FormServer)
	if err := http.ListenAndServe(":8088", nil); err != nil {
		panic(err)
	}
}
