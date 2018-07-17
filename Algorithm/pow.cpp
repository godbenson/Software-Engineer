#include <windows.h>
#include <iostream>

using namespace std;

bool IsEven(unsigned int x){
	return x%2==0?true:false;
}

long int Pow(long int X, unsigned int N){
	if(N == 0)
		return 1;
	if(IsEven(N))
		return Pow(X * X, N/2);
	else
		return Pow(X * X,N/2)*X;
} 

int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd){
	int size = sizeof(long int);
	long int value = Pow(2,8);
}

