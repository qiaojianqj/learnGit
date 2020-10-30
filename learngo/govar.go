package main

import format "fmt"

const (
	_ = 1 << (10 * iota)
	KB
	MB
	GB
	TB
	PB
	EB
	ZB
	YB
)

func f() *int {
	i := 1
	return &i
}

func main() {
	format.Println(f())
	format.Println(f())
	format.Println(f() == f())

	var u uint8 = 255
	format.Println(u, u+1, u*u)
	var i int8 = 127
	format.Println(i, i+1, i*i)

	format.Println(len("Hello, 世界"))
	for i, r := range "Hello, 世界" {
		format.Printf("%d\t%q\t%d\n", i, r, r)
	}
	r := []rune{0x30d7, 0x30ed, 0x30b0, 0x30e9, 0x30e0}
	format.Println(string(r))
	format.Println(string(0x4eac))
	format.Println(string(0x1234567))

	str := "what_fuck_string"
	byteSlice := []byte(str)
	format.Println((byteSlice))
	str = str[5:9]
	format.Println(str)

	format.Println(PB / TB)

	months := [...]string{1: "Jan", 2: "Feb", 3: "Mar", 4: "Apr", 5: "May", 6: "Jun", 7: "Jul", 8: "Aug", 9: "Sep", 10: "Oct", 11: "Nov", 12: "Dec"}
	summer := months[6:9]
	format.Println(summer)
	longsummer := summer[:5]
	format.Println(longsummer)
	reverse(longsummer) // this will change the months array
	format.Println(months)

	s := []int{}
	format.Println(s == nil) // fasle
}

// reverse a slice of ints in place.
func reverse(s []string) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
