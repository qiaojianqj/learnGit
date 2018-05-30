package main

import (
	"fmt"
)

//refer to https://www.cnblogs.com/snowInPluto/p/7477365.html
func main() {
    s := make([]int, 2)
    s[0] = 123
    s[1] = 456
    fmt.Println("before transfer slice as parameter in mdSlice1",s)
    mdSlice1(s)
    fmt.Println("after transfer slice as parameter in mdSlice1",s)

    s[0] = 123
    s[1] = 456
    fmt.Println("before transfer slice as parameter in mdSlice2",s)
    mdSlice2(s)
    fmt.Println("after transfer slice as parameter in mdSlice2",s)

    s[0] = 123
    s[1] = 456
    fmt.Println("before transfer slice as parameter in mdSlice3",s)
    mdSlice3(s)
    fmt.Println("after transfer slice as parameter in mdSlice3",s)

    s[0] = 123
    s[1] = 456
    fmt.Println("before transfer slice as parameter in mdSlice4",s)
    mdSlice4(&s)
    fmt.Println("after transfer slice as parameter in mdSlice4",s)
}

func mdSlice1(s []int) {
    s[0] = 1
    s[1] = 2
}

func mdSlice2(s []int) {
    s = make([]int, 2)
    s[0] = 1
    s[1] = 2
}

func mdSlice3(s []int) {
    s = append(s, 1)
    s = append(s, 2)
}

func mdSlice4(ps *[]int) {
    *ps = append(*ps, 1)
    *ps = append(*ps, 2)
}
