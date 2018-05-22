package main

import "fmt"

type Vertex struct {
	Lat, Long float64
}

var m map[string] *Vertex

func main() {
	m = make(map[string] *Vertex)

	vertex := Vertex{
		40.68433, -74.39967,
	}
	m["Bell Labs"] = &vertex
	fmt.Println(m["Bell Labs"])
	vertex.Lat = 3
	vertex.Long = 4
	fmt.Println(m["Bell Labs"])

	var m2 map[string] int
	m2 = make(map[string] int)
	m2["first"] = 1
	m2["second"] = 2
	m2["third"] = 3
	m2["forth"] = 4
	for k, v := range m2 {
		fmt.Println("key: ", k, "value: ", v)
	}
}
