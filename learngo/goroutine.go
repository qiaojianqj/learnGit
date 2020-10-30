package main

import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan string)
	go sendData(ch)
	go getData(ch)
	time.Sleep(1e9)
}

func sendData(ch chan string) {
	ch <- "Washington"
	ch <- "London"
	ch <- "Paris"
	ch <- "Tokyo"
	ch <- "Beijing"
	ch <- "\n"
}

func getData(ch chan string) {
	//time.Sleep(1e9)
	var buf string
	for {
		buf = <-ch
		fmt.Printf("%s ", buf)
	}
}
