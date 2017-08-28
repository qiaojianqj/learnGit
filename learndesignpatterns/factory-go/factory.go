package main

import "fmt"

type Pizza interface {
	prepare()
	bake()
	cut()
}

type NYStylePizza struct {
	Pizza
}

func (nyPizza NYStylePizza) prepare() {
	fmt.Println("prepare newyork style pizza")
}

func (nyPizza NYStylePizza) bake() {
	fmt.Println("bake newyork stype pizza")
}

func (nyPizza NYStylePizza) cut() {
	fmt.Println("cut newyork stype pizza")
}

type ChicagoStylePizza struct {
	Pizza
}

func (chiPizza ChicagoStylePizza) prepare() {
	fmt.Println("prepare chicago style pizza")
}

func (chiPizza ChicagoStylePizza) bake() {
	fmt.Println("bake chicago style pizza")
}

func (chiPizza ChicagoStylePizza) cut() {
	fmt.Println("cut chicago style pizza")
}

type PizzaStore interface {
	createPizza(pizzaType string) Pizza
	orderPizza(pizzaType string) Pizza
}

type NYPizzaStore struct {
}

func (ny NYPizzaStore) createPizza(pizzaType string) Pizza {
	var nyPizza NYStylePizza
	return nyPizza
}

func (ny NYPizzaStore) orderPizza(pizzaType string) Pizza {
	var nyPizza NYStylePizza
	return nyPizza
}

type ChicagoPizzaStore struct {
}

func (chi ChicagoPizzaStore) createPizza(pizzaType string) Pizza {
	var chiPizza ChicagoStylePizza
	return chiPizza
}

func (chi ChicagoPizzaStore) orderPizza(pizzaType string) Pizza {
	var chiPizza ChicagoStylePizza
	return chiPizza
}

func main() {

}
