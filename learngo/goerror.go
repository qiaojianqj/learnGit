package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

type ParseError struct {
	Index int
	Word  string
	Err   error
}

func (e *ParseError) String() string {
	return fmt.Sprintf("ParseError: error parsing %q as int", e.Word)
}

func fields2numbers(fields []string) (numbers []int) {
	if len(fields) == 0 {
		panic("no words to parse")
	}
	for index, field := range fields {
		num, err := strconv.Atoi(field)
		if err != nil {
			panic(&ParseError{index, field, err})
		}
		numbers = append(numbers, num)
	}
	return numbers
}

func Parse(input string) (numbers []int, err error) {
	defer func() {
		if r := recover(); r != nil {
			var ok bool
			err, ok = r.(error)
			if !ok {
				err = fmt.Errorf("Parse: %v", r)
			}
		}
	}()

	fields := strings.Fields(input)
	numbers = fields2numbers(fields)
	return numbers, err
}
func sqrt(f float64) (float64, error) {
	if f < 0 {
		return 0, fmt.Errorf("math- square root of negative number %g", f)
	} else {
		return math.Sqrt(f), nil
	}

}

func main() {
	if _, err := sqrt(-1); err != nil {
		fmt.Printf("Error: %s\n", err)
	}

	var unParsedStr = []string{
		"1 3 5 7 9",
		"2 4.0 6 8 10",
		"3 + 4 = 7",
		"2nd class",
		"",
	}
	for index, str := range unParsedStr {
		fmt.Printf("%d parsing %q:\n", index, str)
		nums, err := Parse(str)
		if err != nil {
			fmt.Println(err)
			continue
		}
		fmt.Println(nums)
	}
}
