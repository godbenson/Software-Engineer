#ifndef STACK_H
#define STACK_H
#include <string>
#include <iostream>
using namespace std;

template <class T>
class Stack{
public:
	Stack();
	Stack(int max);
	~Stack();
	void Push(T const &x);
	void Pop();
	const T Top() const;
	size_t Size()const {return count;}
	bool IsEmpty() const {return count==0;}
	
private:
	struct Node{
		T data;
		Node *next;
	};

	typedef Node node;//类型别名
	node *top;
	size_t count;
	int max;
};

template <class T>
Stack<T>::Stack():top(nullptr),count(0),max(-1){
	cout << "init, come on!" << endl;
	cout << "at the first, count = " << count << endl;
}

template <class T>
Stack<T>::Stack(int max):top(nullptr),count(0){
	this->max = max;
	cout << "max =" << max << endl;
}

template <class T>
Stack<T>::~Stack(){
	node * current =top;
	while(current != nullptr){
		node* next = current->next;
		delete current;
		current = next;
	}
	top = nullptr;
}

template<class T>
void Stack<T>::Push(const T& x)
{
	if (count == max){
		cout << "Stack is full.Can't push."<<endl;
		return void();
	}
	
	node * newTop = new node;
	newTop->data = x;

	if(top == nullptr){
		newTop->next = nullptr;
	}else{
		newTop->next = top;
	}

	top = newTop;
	count++;
	cout << "push data: " << top->data << endl;
}

template <class T>
void Stack<T>::Pop(){
	if(top == nullptr || count == 0){
		cout << "There have no data.Pop fail."<<endl;
		return void();
	}

	node *delNode = top;
	top = top->next;
	count--;
	cout << "pop data: " << delNode->data << endl;
	delete delNode;
}

template<class T>
const T Stack<T>::Top() const {
	if(top == nullptr || count ==0){
		cout << "There have no data, can't top." << endl;
		return 0;
	}
	return top->data;
}

#endif /*STACK_H*/