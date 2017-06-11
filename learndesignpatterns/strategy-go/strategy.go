package main

import "fmt"

type FlyBehavior interface {
	fly()
}

type FlyWithWing struct {
}

func (fw *FlyWithWing) fly() {
	fmt.Println("FlyWithWing")
}

type FlyNoWay struct {
}

func (fnw *FlyNoWay) fly() {
	fmt.Println("FlyNoWay")
}

type QuackBehavior interface {
	quack()
}

type Quack struct {
}

func (q *Quack) quack() {
	fmt.Println("quack")
}

type Squeak struct {
}

func (s *Squeak) quack() {
	fmt.Println("squeak")
}

type Duck struct {
	flyBehavior   FlyBehavior
	quackBehavior QuackBehavior
}

func (d *Duck) setFlyBehavior(flyBehavior FlyBehavior) {
	d.flyBehavior = flyBehavior
}

func (d *Duck) setQuackBehavior(quackBehavior QuackBehavior) {
	d.quackBehavior = quackBehavior
}

func (d *Duck) performFly() {
	d.flyBehavior.fly()
}

func (d *Duck) performQuack() {
	d.quackBehavior.quack()
}

func (d *Duck) display() {
	fmt.Println("Duck display")
}

func main() {
	pd := new(Duck)
	pFly := new(FlyWithWing)
	pd.setFlyBehavior(pFly)
	pSqueak := new(Squeak)
	pd.setQuackBehavior(pSqueak)
	pd.display()
	pd.performFly()
	pd.performQuack()
}
