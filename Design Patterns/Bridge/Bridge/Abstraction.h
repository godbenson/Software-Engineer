#pragma once
class AbstractionImplement;

class Abstraction
{
public:
	virtual void Operation() = 0;//定义接口，表示该类所支持的操作
	virtual ~Abstraction();
protected:
	Abstraction();
};

class RefinedAbstractionA : public Abstraction
{
public:
	RefinedAbstractionA(AbstractionImplement * imp);
	virtual void Operation();
	virtual ~RefinedAbstractionA();
private:
	AbstractionImplement * _imp;
};

class RefinedAbstractionB : public Abstraction
{
public:
	RefinedAbstractionB(AbstractionImplement * imp);
	virtual void Operation();
	virtual ~RefinedAbstractionB();
private:
	AbstractionImplement * _imp;
};
