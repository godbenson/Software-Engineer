#ifndef _FACADE_H_
#define _FACADE_H_
#include "stdafx.h"
class SubSystemA{
public :
		void Operation();
};

class SubSystemB{
public :
		void Operation();
};

class Facade{
public :
	Facade();
	~Facade();
	void OperationWrapper();
private :
	SubSystemA * _subsysA;
	SubSystemB * _subsysB;
};
#endif