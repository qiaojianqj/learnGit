#ifndef __STRATEGY_H__
#define __STRATEGY_H__
/*
 *策略模式：定义算法族，分别封装起来，让算法到变化独立于使用算法到客户
 */
class FlyBehavior{
public:
	virtual void fly() = 0;
};

class QuackBehavior{
public:
	virtual void quack() = 0;
};

class FlyWithWing: public FlyBehavior{
public:
	void fly();
};

class FlyNoWay: public FlyBehavior{
public:
	void fly();
};

class Quack: public QuackBehavior{
public:
	void quack();
};

class Squeak: public QuackBehavior{
public:
	void quack();
};

class Duck{
public:
	Duck();
	~Duck();
	void swim();
	virtual	void display();
	void performQuack();
	void performFly();
	void setFlyBehavior(FlyBehavior *pflyBehav);
	void setQuackBehavior(QuackBehavior *pquackBehav);

	FlyBehavior *pflyBehavior;
	QuackBehavior *pquackBehavior;
};

class MallardDuck: public Duck{
public:
	MallardDuck();
	~MallardDuck();
	void display();
};

class RubberDuck: public Duck{
public:
	RubberDuck();
	~RubberDuck();
	void display();
};

class DecoyDuck: public Duck{
public:
	DecoyDuck();
	~DecoyDuck();
	void display();
};

#endif
