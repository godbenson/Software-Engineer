#include "Document.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//�洢�ⲿ״̬
	int ascent = 70;
	int descent = 0;
	int height = 100;
	int widht = 120;
	int pointSize = 10;

	string test = "AABCDDEFGHI";
	string::iterator it = test.begin();

	characterFactory* pcF = new characterFactory();
	for (; it != test.end(); it++) {
		pointSize++;
		char c = *it;
		//����һ��character����
		character*charc = pcF->GetCharacter(c);
		//Ӧ���ⲿ״̬
		charc->Display(widht, height, ascent, descent, pointSize);
	}

	vector<character*>::size_type sizeChar = pcF->GetCount();
	cout << "count:" << sizeChar << endl;
	system("pause");
	return 0;
}