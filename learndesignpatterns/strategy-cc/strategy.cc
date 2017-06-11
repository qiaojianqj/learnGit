#include "strategy.h"
#include <iostream>

void FlyWithWing::fly()
{
	std::cout<<"fly with wing"<<std::endl;
}

void FlyNoWay::fly()
{
	std::cout<<"fly no way"<<std::endl;
}

void Quack::quack()
{
	std::cout<<"quack"<<std::endl;
}

void Squeak::quack()
{
	std::cout<<"squeak"<<std::endl;
}

Duck::Duck(): pflyBehavior(NULL), pquackBehavior(NULL)
{
}

Duck::~Duck()
{
	if(pflyBehavior){
		delete pflyBehavior;
		pflyBehavior = NULL;
	}

	if(pquackBehavior){
		delete pquackBehavior;
		pquackBehavior = NULL;
	}
}

void Duck::swim()
{
	std::cout<<"all duck can swim"<<std::endl;
}

void Duck::display()
{
	std::cout<<"duck display"<<std::endl;
}

void Duck::performQuack()
{
	pquackBehavior->quack();
}

void Duck::performFly()
{
	pflyBehavior->fly();
}

void Duck::setFlyBehavior(FlyBehavior *pflyBehav)
{
	pflyBehavior = pflyBehav;
}

void Duck::setQuackBehavior(QuackBehavior *pquackBehav)
{
	pquackBehavior = pquackBehav;
}

MallardDuck::MallardDuck()
{
	pflyBehavior = new FlyWithWing();
	pquackBehavior = new Quack();
}

MallardDuck::~MallardDuck()
{
	if(pflyBehavior){
		delete pflyBehavior;
		pflyBehavior = NULL;
	}

	if(pquackBehavior){
		delete pquackBehavior;	
		pquackBehavior = NULL;
	}
}

void MallardDuck::display()
{
	std::cout<<"mallard duck display"<<std::endl;
}

RubberDuck::RubberDuck()
{
	pflyBehavior = new FlyNoWay();
	pquackBehavior = new Squeak();
}

RubberDuck::~RubberDuck()
{
	if(pflyBehavior){
		delete pflyBehavior;
		pflyBehavior = NULL;
	}

	if(pquackBehavior){
		delete pquackBehavior;	
		pquackBehavior = NULL;
	}
	
}

void RubberDuck::display()
{
	std::cout<<"rubber duck display"<<std::endl;
}

DecoyDuck::DecoyDuck()
{
	pflyBehavior = new FlyWithWing();
	pquackBehavior = new Quack(); 
}

DecoyDuck::~DecoyDuck()
{
	if(pflyBehavior){
		delete pflyBehavior;
		pflyBehavior = NULL;
	}

	if(pquackBehavior){
		delete pquackBehavior;	
		pquackBehavior = NULL;
	}
}
void DecoyDuck::display()
{
	std::cout<<"decoy duck display"<<std::endl;
}

