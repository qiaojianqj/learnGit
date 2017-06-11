/*
 *OO基础：抽象，封装，继承，多态
 *OO原则：
 *	封装变化
 *	多用组合，少用继承
 *	针对接口编程，不针对实现编程
 *OO模式：
 *	策略模式：定义算法蔟，分别封装起来，让算法的变化独立于使用算法的客户
 */
#include "strategy.h"
#include <iostream>
/*
 * g++ teststrategy.cc strategy.cc -o teststrategy
 */
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
