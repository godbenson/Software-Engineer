#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <string>
#include <vector>

using namespace std;

//��Ʒ��
class Product
{
private:
	string m_partA;
	string m_partB;
	string m_partC;
public:
	void setPartA(const string& s);
	void setPartB(const string& s);
	void setPartC(const string& s);
	Product();
	~Product();
};

//����Builder���࣬���岻ͬ���ֵĴ����ӿ�
class Builder
{
public:
	virtual void BuildPartA()=0;
	virtual void BuildPartB()=0;
	virtual void BuildPartC()=0;
	virtual Product* GetProduct()=0;
	Builder();
	virtual ~Builder();
};

// Builder�������࣬ʵ��BuilderPartA��BuilderPartB��BuilderPartC�ӿں���
class ConcreteBuilder1:public Builder
{
public:
	ConcreteBuilder1();
	~ConcreteBuilder1();
	virtual void BuildPartA();
	virtual void BuildPartB();
	virtual void BuildPartC();
	virtual Product* GetProduct();
private:
	Product* m_pProduct;
};

//Builder�������࣬ʵ��BuilderPartA��BuilderPartB��BuilderPartC�ӿں���
class ConcreteBuilder2:public Builder
{
public:
	ConcreteBuilder2();
	~ConcreteBuilder2();
	virtual void BuildPartA();
	virtual void BuildPartB();
	virtual void BuildPartC();
	virtual Product* GetProduct();
private:
	Product* m_pProduct;
};

//ConcreteBuilder1��ConcreteBuilder2��Builder�����������࣬����ʵ�����ֲ�ͬ�Ľ���ϸ��

//ʹ��Builder������Ʒ��������Ʒ�Ĺ��̶�һ�£����ǲ�ͬ��builder�в�ͬ��ʵ��
//�����ͬ��ʵ��ͨ����ͬ��Builder��������ʵ�֣�����һ��Builder��ָ�룬ͨ�������ʵ�ֶ�̬����

class Director
{
public:
	Director(Builder* pBuilder);
	~Director();

	//Construct��������һ������������������̣���ͬ�Ĳ���֮���װ�䷽ʽ����һ�µģ�
	//���ȹ���PartA�����PartB,ֻ�Ǹ��ݲ�ͬ�Ĺ����߻��в�ͬ�ı�ʾ
	void Construct();
private:
	Builder* m_pPBuilder;
};

#endif