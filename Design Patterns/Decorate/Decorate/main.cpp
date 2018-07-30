#include "Beverage.h"
#include <iostream>

using namespace std;

void main()
{
	Beverage* pBeverage = new Espresso();
	cout << pBeverage->getDescription().c_str() << "$" << pBeverage->cost() << endl;

	Beverage* pBeverage2 = new Espresso();
	pBeverage2 = new Mocha(pBeverage2);

	pBeverage2 = new Mocha(pBeverage2);
	cout << pBeverage2->getDescription().c_str() << "$" << pBeverage2->cost() << endl;

	pBeverage2 = new Whip(pBeverage2);
	cout << pBeverage2->getDescription().c_str() << "$" << pBeverage2->cost() << endl;

	system("pause");
}