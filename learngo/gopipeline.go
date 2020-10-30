package main

//https://studygolang.com/articles/9045

import (
	"fmt"
	"sync"
)

func gen(done <-chan interface{}, num ...int) <-chan int {
	out := make(chan int)
	go func() {
		defer close(out)
		for _, n := range num {
			select {
			case out <- n:
			case <-done:
				return
			}
		}
	}()
	return out
}

func sq(done chan interface{}, in <-chan int) <-chan int {
	out := make(chan int)
	go func() {
		defer close(out)
		for n := range in {
			select {
			case out <- n * n:
			case <-done:
				return
			}
		}
	}()
	return out
}

func merge(done chan interface{}, ches ...<-chan int) <-chan int {
	var wg sync.WaitGroup
	out := make(chan int, 0)

	output := func(ch <-chan int) {
		defer wg.Done()
		for n := range ch {
			select {
			case out <- n:
			case <-done:
				return
			}
		}
	}
	wg.Add(len(ches))
	for _, ch := range ches {
		go output(ch)
	}

	go func() {
		wg.Wait()
		close(out)
	}()

	return out
}

func main() {
	done := make(chan interface{})
	defer close(done)

	ch := gen(done, 2, 5)
	ch1 := sq(done, ch)
	ch2 := sq(done, ch)

	fmt.Println(<-merge(done, ch1, ch2))
}
