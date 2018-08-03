#include "Child.h"
#include <iostream>
using namespace std;
int main(int argc, char* * argv) {
	Child * child = new Child;
	Mother * mother = new Mother;
	Father* father = new Father;
	Grandmother * grandMother = new Grandmother;

	mother->setSuccessor(father);
	father->setSuccessor(grandMother);

	child->setHandler(mother);
	child->eatChocolate();

	system("pause");
	return 0;
}