#pragma once
#include <iostream>

using namespace std;

class Beverage
{
public:
	Beverage(string str = "Unknow Beverage")
		:description(str) {}
	virtual string getDescription()
	{
		return description;
	}

	virtual double cost() { return 0; }
private:
	string description;
};

class CondimentDecorator : public Beverage
{
public:
	string getDescription() { return ""; }
};


class Espresso : public Beverage
{
public:
	Espresso() :Beverage("Espresso") {}

	double cost()
	{
		return 1.99;
	}
};

class HouseBlend : public Beverage
{
public:
	HouseBlend() :Beverage("HouseBlend Coffee") {}

	double cost()
	{
		return 0.89;
	}
};

class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage * beve)
	{
		beverage = beve;
	}

	string getDescription()
	{
		return beverage->getDescription() + ", Mocha";
	}

	double cost()
	{
		return 0.20 + beverage->cost();
	}
private:
	Beverage * beverage;
};

class Whip : public CondimentDecorator
{
public:
	Whip(Beverage * beve)
	{
		beverage = beve;
	}

	string getDescription()
	{
		return beverage->getDescription() + ", Whip";
	}

	double cost()
	{
		return 0.15 + beverage->cost();
	}
private:
	Beverage* beverage;
};
