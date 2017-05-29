package main
import format "fmt"

type Foo map[string]string
type Bar struct {
    thingOne string
    thingTwo int
}

func main() {
    // OK
    y := new(Bar)
    (*y).thingOne = "hello"
    (*y).thingTwo = 1
/*
    // NOT OK - make a struct will occur compile error
    z := make(Bar) // 编译错误：cannot make type Bar
    (*z).thingOne = "hello"
    (*z).thingTwo = 1
*/
    // OK
    x := make(Foo)
    x["x"] = "goodbye"
    x["y"] = "world"
/*
    // NOT OK - new a map  will return a nil type ptr, can't be assignment, so make it first
    u := new(Foo)
    (*u)["x"] = "goodbye" // 运行时错误!! panic: assignment to entry in nil map
    (*u)["y"] = "world"
*/
	format.Println("make a struct will occur compile error")
	format.Println("new a map will return a nil type ptr, can't be assignment, so make it first")
}

