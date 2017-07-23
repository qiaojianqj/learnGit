package main

import (
	"fmt"
	"net/http"
)

//openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout key.pem -out cert.pem
//go run generate_cert.go to generate cert.pem and key.pem
//https://127.0.0.1:8081

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Hi http server and client")
	})
	http.ListenAndServeTLS(":8081", "cert.pem", "key.pem", nil)
}
