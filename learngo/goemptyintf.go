package main
import (
	"fmt"
)

//can assignment any type value to empty interface type var
type Any interface{}

//use empty interface to construct a common array that can contain any type var
type Vector struct{
	arr []Any
}

func (pV *Vector)At(i int) Any{
	return pV.arr[i]
}

func (pV *Vector)Set(i int, v Any){
	pV.arr[i] = v
}

func TypeSwitch(){
	testFunc := func(any interface{}){
		switch v := any.(type){
			case int:
				fmt.Printf("any %v is type of %T\n", v, v)
			default:
				fmt.Printf("unknown type\n");
		}
	}
	tmp := 123
	testFunc(tmp)
}
func main(){
	TypeSwitch()

	var pV *Vector = new(Vector)
	pV.arr = []Any{123, 3.14, "fuck life"}
	for i := 0; i < 3; i++{
		fmt.Printf("pV.arr[%d], type %T, value %v\n",i ,pV.arr[i] ,pV.arr[i])
	}
}
