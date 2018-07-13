#include "stdafx.h"
#include "FacadeStrategy.h"
#include <cstdlib>
int _tmain(int argc, _TCHAR* argv[])
{
	Facade * pFacade = new Facade;
	pFacade->OperationWrapper();
	system("pause");
	return 0;
}