#pragma once
#include <iostream>
using namespace std;
class Play
{
public:
	virtual void Play1() = 0;
	virtual void Play2() = 0;
	virtual void Play3() = 0;
};

class Player :public Play
{
public:
	void Play1() {
		cout << "战役" << endl;
	}

	void Play2() {
		cout << "军团" << endl;
	}

	void Play3() {
		cout << "神器" << endl;
	}
};

class ProxyPlayerVip0 : Play
{
public:
	ProxyPlayerVip0()
	{
		mPlayer = new Player;
	}
	void Play1() {
		mPlayer->Play1();
	}

	void Play2() {
		cout << "没有权限" << endl;
	}

	void Play3() {
		cout << "没有权限" << endl;
	}
private:
	Play * mPlayer;
};

class ProxyPlayerVip1 :Play
{
public:
	ProxyPlayerVip1() {
		mPlayer = new Player;
	}
	void Play1()
	{
		mPlayer->Play1();
	}

	void Play2()
	{
		mPlayer->Play2();
	}

	void Play3() {
		cout << "没有权限" << endl;
	}
private:
	Player* mPlayer;
};