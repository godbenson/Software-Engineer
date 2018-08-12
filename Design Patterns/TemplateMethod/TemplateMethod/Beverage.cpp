#include "Beverage.h"

void CaffeineBeverage::prepareRecipe() {
	boilWater();
	brew();
	pourInCup();
	if (customerWantsCondiments()) {
		addCondiments();
	}
}

void CaffeineBeverage::boilWater()
{
	printf("把水煮沸\n");
}

void CaffeineBeverage::pourInCup()
{
	printf("倒入杯子中\n");
}

bool CaffeineBeverage::customerWantsCondiments()
{
	return true;
}

void Coffee::brew()
{
	printf("用沸水冲泡咖啡粉\n");
}

void Coffee::addCondiments()
{
	printf("加糖和牛奶\n");
}

bool Coffee::customerWantsCondiments()
{
	char zAnswer;
	printf("您的咖啡中是否需要牛奶和糖:");
	fflush(stdin);
	zAnswer = getchar();
	zAnswer = toupper(zAnswer);
	if ('Y' == zAnswer)
	{
		return true;
	}
	else if ('N' == zAnswer)
	{
		return false;
	}
	else {
		printf("输入错误，默认不加调料\n");
		return false;
	}
}

void Tea::brew()
{
	printf("用沸水浸泡茶叶\n");
}

void Tea::addCondiments()
{
	printf("加柠檬\n");
}

bool Tea::customerWantsCondiments()
{
	char zAnswer;
	printf("您的茶中是否需要柠檬:");
	fflush(stdin);
	zAnswer = getchar();
	zAnswer = toupper(zAnswer);
	if ('Y' == zAnswer)
	{
		return true;
	}
	else if ('N' == zAnswer)
	{
		return false;
	}
	else {
		printf("输入错误，默认不加调料\n");
		return false;
	}
}