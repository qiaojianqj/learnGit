//use channel to implement sem
package main

import (
	"fmt"
)

func main() {
	s := []int{12, 4, 69, 23, 19, 7, 53}
	done := make(chan bool)
	doPrint := func(s []int) {
		fmt.Println(s)
		done <- true
	}
	go doPrint(s[:3])
	go doPrint(s[3:])

	<-done
	<-done
}

//use no buf channel to implement parallel for loop
/*
for i, v := range data {
	go func (i int, v float64) {
		doSomething(i, v)
		...
	} (i, v)
}
*/

//use buf channel to implement semaphore
/*
type Empty interface {}
type semaphore chan Empty

// acquire n resources
func (s semaphore) P(n int) {
	e := new(Empty)
	for i := 0; i < n; i++ {
		s <- e
	}
}

// release n resouces
func (s semaphore) V(n int) {
	for i:= 0; i < n; i++{
		<- s
	}
}

//mutexes
func (s semaphore) Lock() {
	s.P(1)
}

func (s semaphore) Unlock(){
	s.V(1)
}

// signal-wait
func (s semaphore) Wait(n int) {
	s.P(n)
}

func (s semaphore) Signal() {
	s.V(1)
}
*/
