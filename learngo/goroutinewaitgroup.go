package main

import (
	"fmt"
	"sync"
	"io"
	"bufio"
	"log"
	"os"
)

func filesizecount(filenames []string) int64 {
	sizes := make(chan int64)
	var wg sync.WaitGroup
	for _, f := range filenames {
		wg.Add(1)
		go func(f string) {
			defer wg.Done()
			info, _ := os.Stat(f)
			sizes <- info.Size()
		}(f)
	}
	go func() {
		wg.Wait()
		close(sizes)
	}()
	var total int64
	for size := range sizes {
		total += size
	}
	return total/1024
}

func main() {
	files, err := os.Open("filename")
	if err != nil {
		log.Print(err)
	}
	in := bufio.NewReader(files)
	var filenames []string
	for {
		r, _, err := in.ReadLine()
		if err == io.EOF {
			break
		}
		//fmt.Printf("%s\t",string(r))
		filenames = append(filenames, string(r))
	}
	fmt.Printf("%d KB\n", filesizecount(filenames))

}
