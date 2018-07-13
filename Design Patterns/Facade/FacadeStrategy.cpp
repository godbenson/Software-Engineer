// FacadeStrategy.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "FacadeStrategy.h"
#include <iostream>

using namespace std;
void SubSystemA::Operation(){
	cout << "SubsystemA::Operation" << endl;
}

void SubSystemB::Operation(){
	cout << "SubsystemB::Operation" << endl;
}

Facade::Facade(){
	this->_subsysA = new SubSystemA();
	this->_subsysB = new SubSystemB();
}
Facade::~Facade(){
	delete this->_subsysA;
	delete this->_subsysB;
	this->_subsysA = NULL;
	this->_subsysB = NULL;
}

void Facade::OperationWrapper(){
	this->_subsysA->Operation();
	this->_subsysB->Operation();
}


