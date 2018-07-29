#pragma once
#include <vector>

using namespace std;

/*
Component抽象基类，为组合中的对象声明接口，声明了类共有接口的缺省行为（如这里的Add,Remove,GetChild函数），
声明一个接口函数可以访问Component的子组件
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

//Leaf是叶子结点，也就是不含有子组件的节点类，所以不用实现Add,Remove,GetChild等方法
class Leaf :public Component
{
public:
	//只实现Operation接口
	virtual void Operation();
	Leaf();
	~Leaf();
};

//Composite:含有子组件得类
class Composite :public Component
{
public:
	Composite();
	~Composite();
	//实现新接口
	void Operation();
	void Add(Component*);
	void Remove(Component*);
	Component* GetChild(int index);
private:
	//这里采用vector来保存子组件
	vector<Component*> m_ComVec;

};