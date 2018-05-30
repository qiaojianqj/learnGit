package main

import (
	"fmt"
)

//refer to https://www.cnblogs.com/snowInPluto/p/7477365.html
func main() {
    m := make(map[int]int)
	m[1] = 123
	m[2] = 456
	fmt.Println("before transfer map as parameter in mdMap1: ", m)
    mdMap1(m)
	fmt.Println("after transfer map as parameter in mdMap1: ", m)
	m[1] = 123
	m[2] = 456
	fmt.Println("before transfer map as parameter in mdMap2: ", m)
    mdMap2(m)
	fmt.Println("after transfer map as parameter in mdMap2: ", m)

}

func mdMap1(m map[int]int) {
    m[1] = 100
    m[2] = 200
}

func mdMap2(m map[int]int) {
	m = make(map[int]int)
    m[1] = 100
    m[2] = 200
}
