package main

import "fmt"

func swap(p []int, i, j int) { p[i], p[j] = p[j], p[i] }

func main() {
	//pint := []int{1,2,3,4,5}
	var pint = []int{1, 2, 3, 4, 5}
	swap(pint, 2, 3)
	fmt.Println(pint)
}
