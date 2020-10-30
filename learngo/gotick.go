package main
import (
	"fmt"
	"time"
	"os"
)

func main(){
	tick := time.Tick(time.Second)
	abort := make(chan struct{})
	go func(){
		os.Stdin.Read(make([]byte, 1)) //monitor stdin return
		abort <- struct{}{}
	}()
	for countdown := 10; countdown > 0; countdown--{
		fmt.Println(countdown)
		select{
		case <-tick:
		case <- abort:
			fmt.Println("lanching abort!")
			return
		}
	}
	fmt.Println("lanching start!")

	ch := make(chan int, 1)
	var x int
	for i := 0; i < 10; i++{
		select{
		case x = <-ch:
				fmt.Printf("%d\t",x)
		case ch <- i:
		}
	}
}
