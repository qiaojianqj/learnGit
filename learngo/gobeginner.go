//go beginner need to know 6 quiz
//http://tonybai.com/2015/09/17/7-things-you-may-not-pay-attation-to-in-go/
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"reflect"
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

//http://www.grdtechs.com/2016/02/17/go-reflect-summarize/

type User struct {
	Id   int
	Name string
	Age  int
}

func (u User) String() {
	fmt.Println(u.Name, u.Id, u.Age)
}

func (u User) Set(id int, name string, age int) {
	u.Name = name
	u.Id = id
	u.Age = age
}

func (u User) Get() (int, string, int) {
	return u.Id, u.Name, u.Age
}

func Info(o interface{}) {
	t := reflect.TypeOf(o)           //获取接口的类型
	fmt.Println("  Type:", t.Name()) //t.Name() 获取接口的名称

	if t.Kind() != reflect.Struct {
		//通过Kind()来判断反射出的类型是否为需要的类型
		fmt.Printf("err: type %v invalid!\n", t.Kind())
		return
	}

	v := reflect.ValueOf(o) //获取接口的值类型
	fmt.Println("Fields:")

	for i := 0; i < t.NumField(); i++ { //NumField取出这个接口所有的字段数量
		f := t.Field(i)                                   //取得结构体的第i个字段
		val := v.Field(i).Interface()                     //取得字段的值
		fmt.Printf("%6s: %v = %v\n", f.Name, f.Type, val) //第i个字段的名称,类型,值
	}

	fmt.Println("Methods:")
	for i := 0; i < t.NumMethod(); i++ {
		m := t.Method(i)
		fmt.Printf("%6s: %v\n", m.Name, m.Type) //获取方法的名称和类型
	}
}

func SetInfo(o interface{}) {
	v := reflect.ValueOf(o)

	if v.Kind() == reflect.Ptr && !v.Elem().CanSet() { //判断是否为指针类型 元素是否可以修改
		fmt.Println("cannot set")
		return
	} else {
		v = v.Elem() //实际取得的对象
	}

	//判断字段是否存在
	f := v.FieldByName("Name")
	if !f.IsValid() {
		fmt.Println("invalid")
		return
	}

	//设置字段
	if f := v.FieldByName("Name"); f.Kind() == reflect.String {
		f.SetString("Leo")
	}
}

func GetInfo(u interface{}) {
	v := reflect.ValueOf(u)

	if v.Kind() != reflect.Struct {
		fmt.Println("type invalid")
		return
	}

	get := v.MethodByName("Get")
	if !get.IsValid() {
		fmt.Println("Func Get not exist")
	}
	res := get.Call([]reflect.Value{})
	fmt.Println("reflect Call Get", res[0], res[1], res[2])
}

func main() {
	if WhatIsThe == 0 {
		fmt.Println("It's all a lie.")
	}

	usr := User{
		Id:   123,
		Name: "QiaoJian",
		Age:  28,
	}
	Info(usr)
	SetInfo(&usr)
	fmt.Println("reflect Value Set", usr)
	GetInfo(usr)

	a := []int{1, 3, 5, 7, 9}
	sum("1+3+5+7+9=", a[:]...) // here must have the operator ...

	channelRange()
	arrayRange()
	sliceRange()
	iterVarRange()
	stringCompare()
	panicWithRecover()
}
