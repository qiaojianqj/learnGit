//using no buf channel to communicate among goroutines
//no buf channel will lead to block

//ch := make(chan type, value) will create a channell
//The difference between them is as bellow:
/*
value == 0 -> synchronous, unbuffered (阻塞）
value > 0 -> asynchronous, buffered（非阻塞）
*/

package main

import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan int, 10)
	go push(ch)
	go pull(ch)
	time.Sleep(1e6)
}

func push(ch chan int) {
	var i int = 0
	for {
		ch <- i
		i++
	}
}

func pull(ch chan int) {
	for {
		fmt.Printf("%d ", <-ch)
	}
}
