package main

/*
缓冲channel:异步传输
非缓冲channel:同步传输,在进行针对非缓冲channel的发送操作时，runtime os会检查是否有针对同一个channel的接收操作正在进行，如果有，那么该接收操作必定正被阻塞，这时，上述发送操作会唤醒第一个为此而被阻塞的接收操作，并与之配合完成一次元素值的传输动作。反之亦然。
*/
import (
	"fmt"
	"time"
)

type Person struct {
	city     string
	district string
}

func main() {
	names := []string{"eric", "mark", "leo", "michael"}
	for _, name := range names {
		go func(who string) {
			fmt.Printf("%s\n", who)
		}(name)
	}
	time.Sleep(time.Second)

	ch := make(chan Person, 1)
	p := Person{"beijing", "tongzhou"}
	ch <- p
	fmt.Println(p)
	p.district = "haidian"
	fmt.Println(p)
	fmt.Println(<-ch)

	select {
	case getch(0) <- getnum(1):
		fmt.Println("1st case selected")
	case getch(1) <- getnum(2):
		fmt.Println("2nd case selected")
		//实现select－case通道处理超时机制
	case ok := <-func() chan bool {
		timeout := make(chan bool, 0)
		go func() {
			time.Sleep(time.Second)
			timeout <- false
		}()
		return timeout
	}():
		if !ok {
			fmt.Println("timeout")
		}
		/*	default:
			fmt.Println("default") */
	}

	unbuf := make(chan bool, 0)
	go func() {
		fmt.Println("Sleep One Second")
		time.Sleep(time.Second)
		fmt.Println("send true to channel")
		unbuf <- true
	}()
	b := <-unbuf
	fmt.Printf("received %v from channel\n", b)
}

var ch2 chan int
var ch3 chan int
var chs = []chan int{ch2, ch3}
var nums = []int{0, 1, 2, 3}

func getch(i int) chan int {
	fmt.Printf("getch(%d)\n", i)
	return chs[i]
}

func getnum(i int) int {
	fmt.Printf("getnum(%d)\n", i)
	return nums[i]
}
