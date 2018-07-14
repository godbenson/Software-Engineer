#include <cstdlib>
#include <iostream>
#define NOT_FOUND -1
using namespace std;

template<class T>
int BinarySearch(const T A[], T X, int N){
	int Low, Mid, High;
	
	Low = 0; High = N-1;
	while(Low <= High){
		Mid = ( Low + High ) / 2;
		if( A[Mid] < X)
			Low = Mid + 1;
		else if( A[Mid] > X )
			High = Mid - 1;
		else
			return Mid;
	}
	return NOT_FOUND;
}
void main(){
	int a[] = {1,2,3,4,5,6,7,8};
	cout<<"search index is:" << BinarySearch<int>(a,5,sizeof(a)/sizeof(int));
	system("pause");
}