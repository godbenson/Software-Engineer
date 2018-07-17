#ifndef PROTOTYPE_H
#define PROTOTYPE_H
// ������࣬����ԭ�͵Ļ��࣬�ṩClone�ӿں���
class Prototype
{
public:
	Prototype(){}
	virtual ~Prototype(){}
	virtual Prototype * Clone() =0;
};

//������Prototype��ʵ��Clone����
class ConcretePrototype1:public Prototype
{
public:
	ConcretePrototype1();
	ConcretePrototype1(const ConcretePrototype1&);
	virtual ~ConcretePrototype1();

	virtual Prototype* Clone();
};


//������Prorotype,ʵ��Clone����
class ConcretePrototype2:public Prototype
{
public:
	ConcretePrototype2();
	ConcretePrototype2(const ConcretePrototype2&);
	virtual ~ConcretePrototype2();

	virtual Prototype*Clone();
};

#endif