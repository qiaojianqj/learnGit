package main

import (
	"fmt"
	"reflect"
)

//refer to https://www.jianshu.com/p/94710d8ab691
func TestArgs(first int, args ...interface{}) {
	fmt.Println("type of args", reflect.TypeOf(args))
	fmt.Printf("address of args: %p\n", args)
	fmt.Println(first, args)
}

func main() {
	num1 := []int{1, 3, 5, 7, 9}
	fmt.Println("type of num1", reflect.TypeOf(num1))
	fmt.Printf("address of num1: %p\n", num1)
	TestArgs(0, num1)
	fmt.Println("------------")
	num2 := []interface{}{2, 4, 6, 8, 10}
	fmt.Println("type of num2", reflect.TypeOf(num2))
	fmt.Printf("address of num2: %p\n", num2)
	TestArgs(0, num2...)
}
