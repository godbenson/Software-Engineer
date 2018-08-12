#pragma once
#include <iostream>
using namespace std;

class CaffeineBeverage
{
public:
	void prepareRecipe();
private:
	virtual void brew() = 0;
	virtual void addCondiments() = 0;
	void boilWater();
	void pourInCup();
	virtual bool customerWantsCondiments();//¹³×Ó
};

class Coffee : public CaffeineBeverage
{
private:
	void brew();
	void addCondiments();
	bool customerWantsCondiments();
};

class Tea : public CaffeineBeverage
{
private:
	void brew();
	void addCondiments();
	bool customerWantsCondiments();
};
