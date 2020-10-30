package main

import "fmt"

//all method must be realized
type Shaper interface {
	Area() float32
	parameter() float32
}

type Square struct {
	side float32
}

func (sq Square) Area() float32 {
	return sq.side * sq.side
}

func (sq Square) parameter() float32 {
	return sq.side * 4
}



func main() {
	sq1 := new(Square)
	sq1.side = 5

	var interf Shaper
	//when Type(not *Type) implements interface, 
	//assign *sq1 and sq1 to interf both ok 
	//interf = *sq1
	interf = sq1
	fmt.Printf("interf value: %v,  type: %T\n",interf , interf)
	fmt.Printf("The square has area: %f\n", interf.Area())
	fmt.Printf("The square has area: %f\n", interf.parameter())
}
