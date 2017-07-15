package main

import (
	"fmt"
	"time"
)

var currentId int
var todos Todos

func RepoCreateTodo(t Todo) Todo {
	currentId += 1
	t.Id = currentId
	todos = append(todos, t)
	return t
}

func RepoFindTodo(id int) Todo {
	for _, t := range todos {
		if t.Id == id {
			return t
		}
	}
	return Todo{}
}

func RepoDestroyTodo(id int) error {
	for i, t := range todos {
		if t.Id == id {
			todos = append(todos[:i], todos[i+i:]...)
			return nil
		}
	}
	return fmt.Errorf("Could not find Todo with id of %d to delete", id)
}

func init() {
	RepoCreateTodo(Todo{
		Name:      "write presentation",
		Completed: true,
		Due:       time.Now(),
	})

	RepoCreateTodo(Todo{
		Name:      "Host meetup",
		Completed: false,
		Due:       time.Now(),
	})
}
