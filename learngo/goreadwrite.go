package main
import (
	"fmt"
	"bufio"
	"os"
	"strings"
)

var (
	firstName, lastName string
	f float32
	i int
	s string
	input = "56.12/5212/Go"
	format = "%f/%d/%s"
)

func main() {
	fmt.Println("Please enter your full name: ")
	//input from console
	fmt.Scanln(&firstName, &lastName)
	// fmt.Scanf("%s %s", &firstName, &lastName)
	fmt.Printf("Hi %s %s!\n", firstName, lastName) 
	//input from string
	fmt.Sscanf(input, format, &f, &i, &s)
	fmt.Println("From the string we read: ", f, i, s)
	//input from bufio
	inputReader := bufio.NewReader(os.Stdin)
	fmt.Println("Please enter something: ")
	inputBuf, err := inputReader.ReadString('\n')
	if err == nil{
		fmt.Printf("From inputBuf: %s\n", inputBuf)
	}
	who := "QiaoJian "
	if len(os.Args) > 1{
		who += strings.Join(os.Args[1:], " ")
	}
	fmt.Println("Good Morning", who)
}
