#include "Command.h"
#include <iostream>

using namespace std;

int main() {
	//���������������pCmd���趨���Ľ�����pRev
	Receiver* pRev = new Receiver();
	Command *pComd = new ConcreteCommand(pRev);
	//���������
	Invoker* pInv = new Invoker(pComd);
	pInv->Invoke();

	system("pause");
	return 0;

}