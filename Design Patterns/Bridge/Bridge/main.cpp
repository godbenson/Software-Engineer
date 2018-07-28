#include "Abstraction.h"
#include "AbstractionImplement.h"
#include <iostream>

using namespace std;

int main()
{
	AbstractionImplement* imp = new ConcreteAbstractionImplementA();
	Abstraction* abs = new RefinedAbstractionA(imp);
	abs->Operation();

	cout << "____________________________________________" << endl;

	AbstractionImplement * imp1 = new ConcreteAbstractionImplementB();
	Abstraction * abs1 = new RefinedAbstractionA(imp1);
	abs1->Operation();

	cout << "____________________________________________" << endl;

	AbstractionImplement * imp2 = new ConcreteAbstractionImplementA();
	Abstraction * abs2 = new RefinedAbstractionB(imp2);
	abs2->Operation();

	cout << "____________________________________________" << endl;

	AbstractionImplement * imp3 = new ConcreteAbstractionImplementB();
	Abstraction * abs3 = new RefinedAbstractionB(imp3);
	abs3->Operation();

	cout << endl;

	system("pause");
	return 0;
}