#include "strategy.h"
#include <iostream>

int main(int argc, char *argv[])
{
	Duck *pduck = new MallardDuck();
	
	pduck->performQuack();
	pduck->performFly();

	pduck->setFlyBehavior(new FlyNoWay());
	pduck->setQuackBehavior(new Squeak());

	pduck->performQuack();
	pduck->performFly();

	return 0;
}
