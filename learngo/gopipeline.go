package main

import (
	"fmt"
	"sync"
)

func gen(done <-chan interface{}, num ...int) <-chan int {
	out := make(chan int)
	go func() {
		for _, n := range num {
			select {
			case out <- n:
			case <-done:
				return
			}
		}
		close(out)
	}()
	return out
}

func sq(done chan interface{}, in <-chan int) <-chan int {
	out := make(chan int)
	go func() {
		for n := range in {
			select {
			case out <- n * n:
			case <-done:
				return
			}
		}
		close(out)
	}()
	return out
}

func merge(done chan interface{}, ches ...<-chan int) <-chan int {
	var wg sync.WaitGroup
	out := make(chan int, 0)

	output := func(ch <-chan int) {
		for n := range ch {
			select {
			case out <- n:
			case <-done:
				return
			}
		}
		wg.Done()
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
