package main

import (
	"fmt"
)

//Operation interface
type Operation interface {
	getResult() float64
	setNumA(float64)
	setNumB(float64)
}

//BaseOperation interface
type BaseOperation struct {
	numberA float64
	numberB float64
}

func (operation *BaseOperation) setNumA(numA float64) {
	operation.numberA = numA
}

func (operation *BaseOperation) setNumB(numB float64) {
	operation.numberB = numB
}

//OperationAdd struct
type OperationAdd struct {
	BaseOperation
}

func (operAdd *OperationAdd) getResult() float64 {
	return operAdd.numberA + operAdd.numberB
}

//OperationSub struct
type OperationSub struct {
	BaseOperation
}

func (operSub *OperationSub) getResult() float64 {
	return operSub.numberA - operSub.numberB
}

//OperationMul struct
type OperationMul struct {
	BaseOperation
}

func (operMul *OperationMul) getResult() float64 {
	return operMul.numberA * operMul.numberB
}

//OperationDiv struct
type OperationDiv struct {
	BaseOperation
}

func (operDiv *OperationDiv) getResult() float64 {
	if operDiv.numberB == 0 {
		panic("被除数不能为0")
	}
	return operDiv.numberA / operDiv.numberB
}

//OperationFactory struct
type OperationFactory struct {
}

func (operFact *OperationFactory) createOperation(operator string) (operation Operation) {
	switch operator {
	case "+":
		operation = new(OperationAdd)
	case "-":
		operation = new(OperationSub)
	case "/":
		operation = new(OperationDiv)
	case "*":
		operation = new(OperationMul)
	default:
		panic("运算符号错误！")
	}
	return
}

func main() {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println(err)
		}
	}()
	var fac OperationFactory
	oper := fac.createOperation("/")
	oper.setNumA(3.0)
	oper.setNumB(2.0)
	fmt.Println(oper.getResult())
}
