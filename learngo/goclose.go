package main

import (
	"fmt"
	"time"
)

func Publish(text string, delay time.Duration) <-chan struct{} {
	ch := make(chan struct{})
	go func() {
		time.Sleep(delay)
		fmt.Println("Breaking News: ", text)
		/*
		   close will send a nil value to channel
		   comment the close call, will lead to a deadlock
		*/
		close(ch)
	}()
	return ch
}

func main() {
	wait := Publish("goroutines communicate", 3*time.Second)
	fmt.Println("Waiting for the news")
	<-wait
	fmt.Println("The news is out")
}
