#include "Context.h"
#include <iostream>

using namespace std;

void main() {
	//a-b+c

	Context context;
	context.addValue("a",7);
	context.addValue("b", 8);
	context.addValue("c", 2);

	SubtractNonterminalExpression *substractValue = new SubtractNonterminalExpression(new TerminalExpression(
		context.getValue("a")), new TerminalExpression(context.getValue("b")));
	AddNonterminalExpression *addValue = new AddNonterminalExpression(substractValue, new TerminalExpression(
	context.getValue("c")));

	cout << addValue->interpreter(context);

	system("pause");
	return;
}
