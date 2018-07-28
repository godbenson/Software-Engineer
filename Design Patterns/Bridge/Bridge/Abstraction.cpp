#include"Abstraction.h"
#include "AbstractionImplement.h"
#include <iostream>

using namespace std;

Abstraction::Abstraction()
{}

Abstraction::~Abstraction()
{}

RefinedAbstractionA::RefinedAbstractionA(AbstractionImplement* imp)
{
	this->_imp = imp;
}

RefinedAbstractionA::~RefinedAbstractionA()
{
	delete this->_imp;
	this->_imp = nullptr;
}

void RefinedAbstractionA::Operation()
{
	cout << "RefinedAbstractionA::Operation" << endl;
	this->_imp->Operation();
}

RefinedAbstractionB::RefinedAbstractionB(AbstractionImplement * imp)
{
	this->_imp = imp;
}

RefinedAbstractionB::~RefinedAbstractionB()
{
	delete this->_imp;
	this->_imp = nullptr;
}

void RefinedAbstractionB::Operation()
{
	cout << "RefinedAbstractionB::Operation" << endl;
	this->_imp->Operation();
}