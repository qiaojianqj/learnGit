package main

import (
	"./selfdefpack"
	"fmt"
)

func main() {
	//identifier only start with CapitalWord is exported, that can by ref out selfpack
	//var myname qjpack.qjName = qjpack.GetQjName()
	qjpack.SetMyName()
	fmt.Println("My Name is ", qjpack.GetMyName())
}
