#pragma once
#include <vector>

using namespace std;

/*
Component������࣬Ϊ����еĶ��������ӿڣ��������๲�нӿڵ�ȱʡ��Ϊ���������Add,Remove,GetChild��������
����һ���ӿں������Է���Component�������
*/
class Component
{
public:
	virtual void Operation() = 0;
	
	virtual void Add(Component*);
	virtual void Remove(Component*);
	virtual Component* GetChild(int index);
	virtual ~Component();
protected:
	Component();
};

//Leaf��Ҷ�ӽ�㣬Ҳ���ǲ�����������Ľڵ��࣬���Բ���ʵ��Add,Remove,GetChild�ȷ���
class Leaf :public Component
{
public:
	//ֻʵ��Operation�ӿ�
	virtual void Operation();
	Leaf();
	~Leaf();
};

//Composite:�������������
class Composite :public Component
{
public:
	Composite();
	~Composite();
	//ʵ���½ӿ�
	void Operation();
	void Add(Component*);
	void Remove(Component*);
	Component* GetChild(int index);
private:
	//�������vector�����������
	vector<Component*> m_ComVec;

};