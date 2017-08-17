package main

import "fmt"

const (
	x = iota
	y
	z
)

const (
	a          = iota
	b          = 'B'
	c, d, e, f = iota, iota, iota, iota
	g          = iota
)

func SumAndProduct(A, B int) (add, Multiplied int) {
	add = A + B
	Multiplied = A * B
	return
}

func add(num *int) int {
	return *num + 1
}

func main() {
	fmt.Println(x, y, z)
	fmt.Println(a, b, c, d, e, f, g)
	fmt.Println(SumAndProduct(2, 4))
	num := 123
	fmt.Println(add(&num))
}
