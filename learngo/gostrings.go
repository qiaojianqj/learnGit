package main

import "fmt"

/*
Strings are built from bytes so indexing them yields bytes, not characters.

Go source code is always UTF-8.
A string holds arbitrary bytes.
A string literal, absent byte-level escapes, always holds valid UTF-8 sequences.
Those sequences represent Unicode code points, called runes.
No guarantee is made in Go that characters in strings are normalized.
*/

func main() {
	const sampleStr = "\xbd\xb2\x3d\xbc\x20\xe2\x8c\x98"

	sample := sampleStr[:]

	fmt.Println("Println:")
	fmt.Println(sample)

	fmt.Println("Byte loop with %x")
	for i := 0; i < len(sample); i++ {
		fmt.Printf("%x ", sample[i])
	}
	fmt.Printf("\n")

	fmt.Println("Byte loop with %q:")
	for i := 0; i < len(sample); i++ {
		fmt.Printf("%q ", sample[i])
	}
	fmt.Printf("\n")

	fmt.Println("Printf with %x:")
	fmt.Printf("%x\n", sample)

	fmt.Println("Printf with % x:")
	fmt.Printf("% x\n", sample)

	fmt.Println("Printf with %q:")
	fmt.Printf("%q\n", sample)

	fmt.Println("Printf with %+q:")
	fmt.Printf("%+q\n", sample)
}
