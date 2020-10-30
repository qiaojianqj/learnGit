package main

import (
	"fmt"
	"net/http"
	"os"
	"reflect"
	"strings"

	"github.com/bouk/monkey"
)

func main() {
	monkey.Patch(fmt.Println, func(a ...interface{}) (n int, err error) {
		s := make([]interface{}, len(a))
		for i, v := range a {
			s[i] = strings.Replace(fmt.Sprint(v), "fuck", "*hell*", -1)
		}
		return fmt.Fprintln(os.Stdout, s...)
	})
	fmt.Println("what fuck is the monkeypatching")
	monkey.Unpatch(fmt.Println)
	fmt.Println("what fuck is the monkeypatching")

	var guard *monkey.PatchGuard
	guard = monkey.PatchInstanceMethod(reflect.TypeOf(http.DefaultClient), "Get", func(c *http.Client, url string) (*http.Response, error) {
		guard.Unpatch()
		defer guard.Restore()
		if !strings.HasPrefix(url, "https://") {
			return nil, fmt.Errorf("only https requests allowed")
		}
		return c.Get(url)
	})

	_, err := http.Get("http://www.baidu.com")
	fmt.Println(err)
	resp, err := http.Get("https://www.baidu.com")
	fmt.Println(resp.Status, err)
}
