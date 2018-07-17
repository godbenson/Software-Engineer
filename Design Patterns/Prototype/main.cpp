#include "Prototype.h"
#include <stdio.h>
#include <cstdlib>

int main(){
	Prototype* pPrototype1 = new ConcretePrototype1();
	Prototype* pPrototype2 = pPrototype1->Clone();

	Prototype* pPrototype3 = new ConcretePrototype2();
	Prototype* pPrototype4 = pPrototype3->Clone();

	delete pPrototype1;
	delete pPrototype2;
	delete pPrototype3;
	delete pPrototype4;
	system("pause");
}