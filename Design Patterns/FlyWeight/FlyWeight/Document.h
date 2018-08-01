#pragma once
#include <string>
#include <vector>

using namespace std;
//The 'Flyweight' abstract class
class character
{
public:
	//��������
	virtual ~character();
	//Ӧ���ⲿ״̬
	virtual void Display(int width, int height, int ascent, int descent, int pointSize) = 0;
	//��ȡ�ڲ�״̬
	virtual char GetSymbol() = 0;

protected:
	/*------�ڲ�״̬------*/
	char symbol;
	/*-----------------------*/

	/*--------�ⲿ״̬----------*/
	int width;
	int height;
	int ascent;
	int descent;
	int pointSize;
	/*--------------------------*/

	//���캯��
	character(char c);
};

//A 'ConcreteFlyweight' class
class characterA : public character
{
public:
	characterA(char c);
	~characterA();
	virtual void Display(int width, int height, int ascent, int descent, int pointSize);
	virtual char GetSymbol();
protected:

private:

};

//B 'ConcreteFlyweight' class
class characterB : public character
{
public :
	characterB(char c);
	~characterB();
	virtual void Display(int width, int height, int ascent, int descent, int pointSize);
protected:
private:
	
};

class characterC : public character
{
public:
	characterC(char c);
	~characterC();
	virtual void Display(int width, int height, int ascent, int descent, int pointSize);
protected:
private:
};

class characterD :public character
{
public:
	characterD(char c);
	~characterD();
	virtual void Display(int width, int height, int ascent, int descent, int pointSize);
protected:
private:
};

//The 'FlyweightFactory' class
class characterFactory
{
public:
	characterFactory();
	~characterFactory();
	//����һ��character����
	character* GetCharacter(char);
	//��ȡ�洢��character*����
	vector<character*>::size_type GetCount();
private:
	//����character*�����������Ի���List����������
	vector<character*> m_vecCharacter;
};