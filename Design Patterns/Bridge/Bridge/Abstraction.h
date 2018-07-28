#pragma once
class AbstractionImplement;

class Abstraction
{
public:
	virtual void Operation() = 0;//����ӿڣ���ʾ������֧�ֵĲ���
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
