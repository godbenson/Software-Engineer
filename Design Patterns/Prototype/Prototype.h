#ifndef PROTOTYPE_H
#define PROTOTYPE_H
// 虚拟基类，所有原型的基类，提供Clone接口函数
class Prototype
{
public:
	Prototype(){}
	virtual ~Prototype(){}
	virtual Prototype * Clone() =0;
};

//派生自Prototype，实现Clone方法
class ConcretePrototype1:public Prototype
{
public:
	ConcretePrototype1();
	ConcretePrototype1(const ConcretePrototype1&);
	virtual ~ConcretePrototype1();

	virtual Prototype* Clone();
};


//派生自Prorotype,实现Clone方法
class ConcretePrototype2:public Prototype
{
public:
	ConcretePrototype2();
	ConcretePrototype2(const ConcretePrototype2&);
	virtual ~ConcretePrototype2();

	virtual Prototype*Clone();
};

#endif