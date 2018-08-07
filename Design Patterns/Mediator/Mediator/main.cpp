#include "Mediator.h"
#include <iostream>
using namespace std;
int main()
{
	ConcreteMediator * pMediator = new ConcreteMediator();

	Colleage* p1 = new ConcreteColleageA(pMediator);
	Colleage* p2 = new ConcreteColleageB(pMediator);

	pMediator->SetColleageA(p1);
	pMediator->SetColleageB(p2);

	p1->SendMsg("XXX");
	p2->SendMsg("OOO");
	system("pause");
	return 0;
}