package main

import (
	"fmt"
)

type Intf interface {
	M1()
	M2()
}

type T struct {
	Name string
}

func (t T) M1() {
	t.Name = "name1"
}

func (t *T) M2() {
	t.Name = "name2"
}

//Pointer reciver default implements value reciver method
func main() {
	t1 := T{"t1"}
	//T does not implement Intf (M2 method has pointer receiver)
	//var intf Intf = t1
	var intf Intf = &t1
	fmt.Println("M1调用前：", t1.Name)
	intf.M1()
	fmt.Println("M1调用后：", t1.Name)

	fmt.Println("M2调用前：", t1.Name)
	intf.M2()
	fmt.Println("M2调用后：", t1.Name)
}
