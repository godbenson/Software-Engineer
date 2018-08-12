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
	printf("��ˮ���\n");
}

void CaffeineBeverage::pourInCup()
{
	printf("���뱭����\n");
}

bool CaffeineBeverage::customerWantsCondiments()
{
	return true;
}

void Coffee::brew()
{
	printf("�÷�ˮ���ݿ��ȷ�\n");
}

void Coffee::addCondiments()
{
	printf("���Ǻ�ţ��\n");
}

bool Coffee::customerWantsCondiments()
{
	char zAnswer;
	printf("���Ŀ������Ƿ���Ҫţ�̺���:");
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
		printf("�������Ĭ�ϲ��ӵ���\n");
		return false;
	}
}

void Tea::brew()
{
	printf("�÷�ˮ���ݲ�Ҷ\n");
}

void Tea::addCondiments()
{
	printf("������\n");
}

bool Tea::customerWantsCondiments()
{
	char zAnswer;
	printf("���Ĳ����Ƿ���Ҫ����:");
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
		printf("�������Ĭ�ϲ��ӵ���\n");
		return false;
	}
}