#pragma once
class AbstractionImplement
{
public:
	virtual void Operation() = 0;
	virtual ~AbstractionImplement();
protected:
	AbstractionImplement();
};

class ConcreteAbstractionImplementA : public AbstractionImplement
{
public:
	ConcreteAbstractionImplementA();
	void Operation();
	~ConcreteAbstractionImplementA();
};

class ConcreteAbstractionImplementB : public AbstractionImplement
{
public:
	ConcreteAbstractionImplementB();
	void Operation();
	~ConcreteAbstractionImplementB();
protected:
};