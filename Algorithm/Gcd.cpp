#include <iostream>
#include <windows.h>
using namespace std;

unsigned int Gcd( unsigned int M, unsigned int N ){
	unsigned int Rem;

	while( N > 0 ){
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}

int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd){
	int gcd = Gcd(1989,1590);
	cout << gcd << endl;
	system("pause");
 	return 0;
}