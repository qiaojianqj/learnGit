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

func (sq *Square) Area() float32 {
	return sq.side * sq.side
}

func main() {
	sq1 := new(Square)
	sq1.side = 5

	//error:cannot use sq1 (type *Square) as type Shaper in assignment
	//var areaIntf Shaper
	//areaIntf = sq1

	//error:cannot convert sq1 (type *Square) to type Shaper
	//areaIntf := Shaper(sq1)

	areaIntf := sq1
	fmt.Printf("The type of areaIntf: %T\n", areaIntf)
	fmt.Printf("The square has area: %f\n", areaIntf.Area())
}
