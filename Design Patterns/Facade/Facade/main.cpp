#include "Facade.h"
#include <iostream>
int main()
{
	Facade * pFacade = new Facade();
	pFacade->OperationWrapper();
	system("pause");
	return 0;
}