#ifndef _FACTORY_H_
#define _FACTORY_H_
//AbstractFactory,����������࣬��������A����B���Ʒ�Ľӿ�
class AbstractProductA;
class AbstractProductB;
class AbstractFactory{
public:
	virtual ~AbstractFactory()=0;
	virtual AbstractProductA* CreateProductA()=0;
	virtual AbstractProductB* CreateProductB()=0;
protected:
	AbstractFactory();
};

//ConcreteFactory1,�����࣬�̳�AbstractFactory
//ʵ�ּ̳еĽӿڣ�������ƷA��B��һ��ʵ��
class ConcreteFactory1:public AbstractFactory
{
public:
	ConcreteFactory1();
	~ConcreteFactory1();
	virtual AbstractProductA* CreateProductA();
	virtual AbstractProductB* CreateProductB();
};

//ConcreteFactory2,������,�̳���AbstractFactory
//ʵ�ּ̳еĽӿڣ�������ƷA��B����һ��ʵ��
class ConcreteFactory2:public AbstractFactory
{
public:
	ConcreteFactory2();
	~ConcreteFactory2();
	virtual AbstractProductA* CreateProductA();
	virtual AbstractProductB* CreateProductB();
};
#endif