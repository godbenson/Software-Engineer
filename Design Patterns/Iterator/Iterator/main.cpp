#include "Iterator.h"
#include <iostream>
using namespace std;

int main() {
	Aggregate<int> *aggr = new ConcreteAggregate<int>();
	Iterator<int> * it = aggr->createIterator();

	for (it->first(); !it->isDone(); it->next())
	{
		cout << *(it->currentItem()) << endl;
	}

	delete it;
	delete aggr;
	system("pause");
	return 0;
}