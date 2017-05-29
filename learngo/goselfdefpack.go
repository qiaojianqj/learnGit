package main
import (
	"fmt"
	"./selfdefpack"
)

func main() {
	//identifier only start with CapitalWord is exported, that can by ref out selfpack
	//var myname qjpack1.qjName = qjpack1.GetQjName()
	//fmt.Println("My Name is ",myname.chineseName, myname.englishName)
	fmt.Println("My Name is ", qjpack1.GetQjName())
}
