package main

import (
	"fmt"
	"sync"
)

func race() {
	var wg sync.WaitGroup
	wg.Add(5)
	for i := 0; i < 5; i++ {
		go func() {
			fmt.Println(i)
			wg.Done()
		}()
	}
	wg.Wait()
	fmt.Println()
}

func norace() {
	var wg sync.WaitGroup
	wg.Add(5)
	for i := 0; i < 5; i++ {
		n := i
		go func() {
			fmt.Println(n)
			wg.Done()
		}()
	}
	wg.Wait()
	fmt.Println()
}
func main() {
	//	race()
	norace()
}
