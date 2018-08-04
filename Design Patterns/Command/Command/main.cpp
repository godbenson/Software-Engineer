#include "Command.h"
#include <iostream>

using namespace std;

int main() {
	//创建具体命令对象pCmd并设定它的接收者pRev
	Receiver* pRev = new Receiver();
	Command *pComd = new ConcreteCommand(pRev);
	//请求绑定命令
	Invoker* pInv = new Invoker(pComd);
	pInv->Invoke();

	system("pause");
	return 0;

}