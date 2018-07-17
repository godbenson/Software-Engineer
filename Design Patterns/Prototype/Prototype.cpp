#include "Prototype.h"
#include <iostream>

using namespace std;
ConcretePrototype1::ConcretePrototype1(){
	cout<< "Construction of ConcretePrototype1\n";
}

ConcretePrototype1::~ConcretePrototype1(){
	cout << "Deconstruction of ConcretePrototype1\n";
}

ConcretePrototype1::ConcretePrototype1(const ConcretePrototype1 &)
{
	cout << "Copy construction of ConcretePrototype1\n";
}

Prototype* ConcretePrototype1::Clone()
{
	return new ConcretePrototype1(*this);
}

ConcretePrototype2::ConcretePrototype2()
{
	cout << "Construction of concretePrototype2\n";
}

ConcretePrototype2::~ConcretePrototype2(){
	cout << "Destruction of ConcretePrototype2\n";
}

ConcretePrototype2::ConcretePrototype2(const ConcretePrototype2&){
	cout << "copy construction of ConcretePrototype2\n";
}

Prototype* ConcretePrototype2::Clone()
{
	return new ConcretePrototype2(*this);
}