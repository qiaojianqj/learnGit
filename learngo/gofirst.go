package main
import (
	format "fmt" //alias of package
	"math"
	"runtime"
)

var v1 int = 1
var v2 int
var v4, str = 4, "str" //global var can declared but not used
var (
	v5 float32
	v6 complex64
)
const PI = 3.1415926
const (
	i = 1 << iota
	j = 2 << iota
	k
)
func main(){
	v2, v5 = 2, 5.0
	_, v6 = "anyvalue", 6 //_ used to discard some value

	v3 := 3 //only can lay in func, local var must be used after be declared
	println("Hello, World!")
	println(v1, v2, v3, v4, v5, v6)
	diameter := 7.0
	format.Printf("Area is %f\n", PI * diameter)
	format.Printf("i = %d\nj = %d\nk = %d\n", i, j, k)

	var a bool = true
	b := false
	format.Println(a||b)

	var c int = 321
	var ptr *int
	ptr = &c
	format.Printf("c: %d\n", c)
	format.Printf("ptr: %p\n", ptr)
	format.Printf("*ptr: %d\n", *ptr)

	var d interface{}
	switch e := d.(type){
		case nil:
			format.Printf("type of d: %T\n", e)
		default :
			format.Printf("Unknown type\n")
	}

	num := [5] int {1,3,5}
	for index, value := range num{
		format.Printf("num[%d] = %d\n", index, value)
	}

	format.Println(swapbyvalue("first", "second"))

	swapbyref(&v1, &v3)
	format.Printf("v1: %d, v3: %d\n", v1, v3)

	//func used by value
	getSquareRoot := func (x float64) float64 {
		return math.Sqrt(x)
	}
	format.Printf("getSquareroot of 16: %f\n", getSquareRoot(16))

	//func used by closure(anonymous func)
	incNum := getInc() //incNum is a func
	format.Println(incNum())
	format.Println(incNum())
	format.Println(incNum())

	incNum2 := getInc() // incNum2 is a func
	format.Println(incNum2())
	format.Println(incNum2())
	format.Println(incNum2())

	var circle Circle
	circle.radius = 3.0
	format.Println("Area of Circle(circle) is: ", circle.getArea())

	var arr1 = []float64 {1.0, -2.3, 4.7, 9.8}
	format.Println("arr1[1]: ", arr1[1])
	format.Printf("Average of arr1: %f\n", getAverage(arr1,4))

	var ptrArr1 [4] *float64
	for i := 0; i < 4; i++{
		ptrArr1[i] = &arr1[i]
	}
	for i := 0; i < 4; i++{
		format.Printf("arr1[%d] = %f\n", i ,*ptrArr1[i])
	}

	arr2 := [3][4]int{
		{0, 1, 2, 3},    /*  第一行索引为 0 */
		{4, 5, 6, 7},   /*  第二行索引为 1 */
		{8, 9, 10, 11}}   /*  第三行索引为 2 */
	for i := 0; i < 3; i++{
		for j := 0; j < 4; j++{
			format.Printf("arr2[%d][%d]: %d\n", i, j, arr2[i][j])
		}
	}

	var ptr1 *int
	format.Printf("uninitialized ptr: %x\n", ptr1)

	var  numSlice1 []int
	if(numSlice1 == nil){
		printSlice(numSlice1)
	}
	numSlice1 =  append(numSlice1, 2, 5, 8, 10, 12)
	printSlice(numSlice1)
	numSlice2 := make([]int, len(numSlice1), cap(numSlice1)*2)
	copy(numSlice2, numSlice1)
	printSlice(numSlice2)
	format.Printf("numSlice2[:3] : %v\n", numSlice2[:3])
	format.Printf("numSlice2[:] : %v\n", numSlice2[:])

	for index, value:= range "fuck"{
		format.Println(index, value)
	}

	var countryCapitalMap map[string] string  //this declaration will create a nil map
	//can't use a nil map so make it
	countryCapitalMap = make(map[string] string)
	countryCapitalMap["China"] = "Beijing"
	countryCapitalMap["America"] = "Washington"
	for key, value := range countryCapitalMap{
		format.Printf("country: %s, capital: %s\n", key, value)
	}
	capital, ok := countryCapitalMap["British"]
	if(!ok){
		format.Println("no record British Capital ", capital)
	}

	format.Println(fibonaci(10))

	round1 :=  Round{2.0}
	var round2  =  round1
	//var round3 Circle = round1 //complile error: type Round and type Circle can't convert
	format.Println("round: ", round2)

	var m runtime.MemStats
	runtime.ReadMemStats(&m)
	format.Printf("%d Kb\n", m.Alloc / 1024)
}

func swapbyvalue(x, y string) (string, string){
	return y, x
}

func swapbyref(x, y *int){
	var tmp int
	tmp = *x
	*x = *y
	*y = tmp
}

func getInc() func () int {
	x := 0
	return func () int {
		x++
		return x
	}
}

//go struct definition
type Circle struct {
	radius float64
}
//this func belong to type Cirle's object's method 
func (circle Circle) getArea () float64 {
	return PI * circle.radius * circle.radius
}

//array used by func parameters
func getAverage (arr []float64, size int) float64{
	var i int
	var avg, sum float64
	for i = 0; i < size; i++{
		sum += arr[i]
	}
	avg = sum / float64(size)
	return avg
}

//go Slice is a abtract array
func printSlice(x []int){
	format.Printf("len = %d, cap = %d, slice = %v\n", len(x), cap(x), x)
}

//recursive func
func fibonaci(n int) int{
	if n < 2{
		return n
	}
	return fibonaci(n-2) + fibonaci(n-1)
}

type  Round Circle //alias type
