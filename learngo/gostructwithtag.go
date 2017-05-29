package main

import (
	"fmt"
	"reflect"
)

type Run interface{
	RunCmd()
}

type Task struct{
	command string
}

func (t *Task)RunCmd(){
	fmt.Printf("exe the command: %s\n", t.command)
}

type Tag struct { // tags
	field1 bool   "An important answer"
	field2 string "The name of the thing"
	field3 int    "How much there are"
		   *Task  "Point to a Task"
}

func NewTag(b bool, s string, i int, t *Task) *Tag{
	return &Tag{b, s, i, t}
}

func main() {
	//tt := Tag{true, "Barak Obama", 1}
	task :=  new(Task)
	task.command = "inauguration"
	tt := NewTag(true, "Barak Obama", 1, task)
	fmt.Println("run tag's task's cmd")
	tt.RunCmd()

	for i := 0; i < 4; i++ {
		refTag(*tt, i)
	}
}

func refTag(tt Tag, ix int) {
	ttType := reflect.TypeOf(tt) //acquire struct type: main.Tag
	fmt.Printf("type: %v\n", ttType)
	ixField := ttType.Field(ix)  //index to struct field
	fmt.Printf("%v\n", ixField.Tag) //index to struct tag
}
