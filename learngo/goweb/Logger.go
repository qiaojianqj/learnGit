package main

import (
	"log"
	"net/http"
	"time"
)

/*
  type Handler interface {
  	ServeHTTP(ResponseWriter, *Request)
  }

  type HandlerFunc func(ResponseWriter, *Request)

  // ServeHTTP calls f(w, r).
  func (f HandlerFunc) ServeHTTP(w ResponseWriter, r *Request) {
  	f(w, r)
  }
*/
//Logger - return handler with log
func Logger(inner http.Handler, name string) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		start := time.Now()
		inner.ServeHTTP(w, r)
		log.Printf("%s\t%s\t%s\t%s", r.Method, r.RequestURI, name, time.Since(start))
	})
}
