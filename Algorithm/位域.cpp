// ConsoleApplication8.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "stdafx.h"
#include <stdarg.h>
#include <initializer_list>
#include <iostream>

#include <string>
#include <iterator>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <memory.h>


using namespace std;
struct A {
	int a : 5;
	int b : 3;
};
int main(int argc, char** argv)
{
	struct BF2
	{
		char f1 : 3;
		short f2 : 4;
		char f3 : 5;
	};
	printf("sizeof(len2)=%dn", sizeof(BF2));

	//std::vector<double>::iterator outputIterator = vdouble.begin();
	//std::copy(darray,darray+10,outputIterator);
	//while (outputIterator != vdouble.end()) {
	//	std::cout << *outputIterator << std::endl;
	//	outputIterator++;
	//}
	//int * a = new int(1);
	//int b = 2;
	//double * c = new double(1.0);
	//double d = 2.0;
	//char * e = new char('e');
	//char f = 'f';
	//char g[5] = "abcd";
	//int *h[] = {a,&b};
	//printf("sizeof int *:%d\n",sizeof(a));
	//printf("sizeof int:%d\n",sizeof(b));
	//printf("sizeof double *:%d\n", sizeof(c));
	//printf("sizeof double:%d\n", sizeof(d));
	//printf("sizeof char *:%d\n", sizeof(e));
	//printf("sizeof char:%d\n", sizeof(f));
	//printf("sizeof char[]:%d\n", sizeof(g));
	//printf("sizeof int*[]:%d\n", sizeof(h));
	//printf("sizeof struct:%d\n",sizeof(j));


	std::cin.get();
	return 0;
}