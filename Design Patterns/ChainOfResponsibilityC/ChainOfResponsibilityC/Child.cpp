#include "Child.h"
#include <iostream>
using namespace std;
void Child::eatChocolate() {
	if (m_pHandler->canIEatChocolate()) {
		cout << "yes !";
	}
	else {
		cout << "no";
	}
}

void Child::setHandler(Handler * handler) {
	m_pHandler = handler;
}



bool Mother::canIEatChocolate() {
	if (successor()) {
		return successor()->canIEatChocolate();
	}
	else {
		return false;
	}
}

bool Father::canIEatChocolate() {
	if (successor()) {
		return successor()->canIEatChocolate();
	}
	else {
		return false;
	}
}


bool Grandmother::canIEatChocolate() {
	if (successor()) {
		return successor()->canIEatChocolate();
	}
	else {
		return true;
	}
}