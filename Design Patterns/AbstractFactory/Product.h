#ifndef _PRODUCT_H_
#define _PRODUCT_H_


//�������AbstractProductA,����A���Ʒ�ĳ���
class AbstractProductA{
public:
	virtual ~AbstractProductA() =0;
	virtual void operation()=0;
protected:
	AbstractProductA();//���ι��캯��
};

//������ProductA1,�̳���AbstractProductA,A���Ʒ��һ��ʵ��
class ProductA1 : public AbstractProductA{
public:
	ProductA1();
	virtual void operation();
	virtual ~ProductA1();
};

//������ProductA2,�̳���AbstractProductA,A���Ʒ����һ��ʵ��
class ProductA2 : public AbstractProductA{
public :
	ProductA2();
	virtual void operation();
	virtual ~ProductA2();
};

//�������AbstractProductB,����B���Ʒ�ĳ���
class AbstractProductB{
public:
	virtual ~AbstractProductB()=0;
	virtual void operation()=0;
protected:
	AbstractProductB();//���ι��캯��
};

//������ProductB1,�̳���AbstractProductB,B���Ʒ��һ��ʵ��
class ProductB1:public AbstractProductB{
public:
	ProductB1();
	virtual void operation();
	virtual ~ProductB1();
};

//������ProductB2,�̳���AbstractProductB,B���Ʒ����һ��ʵ��
class ProductB2:public AbstractProductB{
public:
	ProductB2();
	virtual void operation();
	virtual ~ProductB2();
};
#endif