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

type S1 struct {
	T
}

type S2 struct {
	*T
}

 // refer to https://blog.csdn.net/u013790019/article/details/45397287
//Pointer reciver default implements value reciver method
func main() {
	t1 := T{"t1"}

    fmt.Println("M1调用前：", t1.Name)
    t1.M1()
    fmt.Println("M1调用后：", t1.Name)

    fmt.Println("M2调用前：", t1.Name)
    t1.M2()
    fmt.Println("M2调用后：", t1.Name)

	fmt.Println("------------------")

	//T does not implement Intf (M2 method has pointer receiver)
	//var intf Intf = t1
	var intf Intf = &t1
	fmt.Println("M1调用前：", t1.Name)
	intf.M1()
	fmt.Println("M1调用后：", t1.Name)

	fmt.Println("M2调用前：", t1.Name)
	intf.M2()
	fmt.Println("M2调用后：", t1.Name)

	fmt.Println("------------------")

	t1 = T{"t1"}
	s1 := S1{t1}
	intf = &s1

	fmt.Println("M1调用前：", s1.Name)
	intf.M1()
	fmt.Println("M1调用后：", s1.Name)

	fmt.Println("M2调用前：", s1.Name)
	intf.M2()
	fmt.Println("M2调用后：", s1.Name)

	fmt.Println(t1.Name)

	s2 := S2{&t1}
	intf = s2

	fmt.Println("M1调用前：", s2.Name)
	intf.M1()
	fmt.Println("M1调用后：", s2.Name)

	fmt.Println("M2调用前：", s2.Name)
	intf.M2()
	fmt.Println("M2调用后：", s2.Name)

	fmt.Println(t1.Name)
}
