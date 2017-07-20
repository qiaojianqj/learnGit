//go beginner need to know 6 quiz
//http://tonybai.com/2015/09/17/7-things-you-may-not-pay-attation-to-in-go/
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
	"time"
)

//in a package, globle variable initialize firstly, then execute the init function, at last execute the main function
var WhatIsThe = AnswerToLife()

func AnswerToLife() int {
	return 42
}

func init() {
	if WhatIsThe == 42 {
		WhatIsThe = 0
	}
}

func main() {
	if WhatIsThe == 0 {
		fmt.Println("It's all a lie.")
	}
	a := []int{1, 3, 5, 7, 9}
	sum("1+3+5+7+9=", a[:]...) // here must have the operator ...
	channelRange()
	arrayRange()
	sliceRange()
	iterVarRange()
	stringCompare()
	panicWithRecover()
}

func sum(s string, args ...int) {
	var x int
	for _, v := range args {
		x += v
	}
	fmt.Println(s, x)
}

//range a', where a' is a replica of a

func channelRange() {
	var c = make(chan int, 0)
	go func() {
		time.Sleep(time.Second * 1)
		c <- 1
		c <- 2
		c <- 3
		close(c)
	}()

	for v := range c {
		fmt.Println(v)
	}
}
func iterVarRange() {
	var m = [...]int{1, 2, 3, 4, 5}
	for i, v := range m {
		go func(i, v int) {
			time.Sleep(time.Second * 1)
			fmt.Println(i, v)
		}(i, v)
	}
}

func arrayRange() {
	var a = [5]int{1, 2, 3, 4, 5}
	var r = make([]int, 0)

	fmt.Println("a = ", a)

	for i, v := range &a {
		if i == 0 {
			a[1] = 12
			a[2] = 13
		}

		r = append(r, v)
	}

	fmt.Println("r = ", r)
	fmt.Println("a = ", a)

}

func sliceRange() {
	var a = []int{1, 2, 3, 4, 5}
	var r = make([]int, 0)

	fmt.Println("a = ", a)

	for i, v := range a[:] {
		if i == 0 {
			a = append(a, 6, 7)
		}

		r = append(r, v)
	}

	fmt.Println("r = ", r)
	fmt.Println("a = ", a)
}

func stringCompare() {
	var isLetter bool
	fmt.Println("Enter a letter")
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	if strings.TrimRight(input, "\n") >= "a" &&
		strings.TrimRight(input, "\n") <= "z" {
		isLetter = true
	} else {
		isLetter = false
	}

	fmt.Println("You have entered", input)
	fmt.Println("Is it a letter?", isLetter)
}

//panic and recover in defer func
func foo() {
	defer func() {
		fmt.Println("foo defer func invoked")
	}()
	fmt.Println("foo invoked")

	bar()
	fmt.Println("do something after bar in foo")
}

func bar() {
	defer func() {
		fmt.Println("bar defer func invoked")
	}()
	fmt.Println("bar invoked")

	zoo()
	fmt.Println("do something after zoo in bar")
}

func zoo() {
	defer func() {
		fmt.Println("zoo defer func1 invoked")
	}()

	defer func() {
		if x := recover(); x != nil {
			log.Printf("recover panic: %v in zoo recover defer func", x)
		}
	}()

	defer func() {
		fmt.Println("zoo defer func2 invoked")
	}()

	fmt.Println("zoo invoked")
	panic("runtime exception")
}

func panicWithRecover() {
	foo()
}
