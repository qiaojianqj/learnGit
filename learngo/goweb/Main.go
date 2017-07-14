package main

import (
	"log"
	"net/http"
)

//goto goweb dir; then run: go build; at last, run exe: ./goweb
func main() {
	router := NewRouter()
	log.Fatal(http.ListenAndServe(":8080", router))
}
