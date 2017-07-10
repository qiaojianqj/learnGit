package main

import (
	"fmt"
	"os"
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
}
