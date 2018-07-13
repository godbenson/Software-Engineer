#include <stdio.h>
#include <windows.h>
#include <cstdlib>
int Max3(int a,int b,int c){
	int max = a>b?a:b;
	return max>c?max:c;
}
int MaxSubSum(const int A[],int Left, int Right){
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum,RightBorderSum;
	int Center, i;

	if(Left == Right)/*Base Case*/
	{
		if(A[Left] > 0)
			return A[Left];
		else
			return 0;
	}

	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center+1,Right);

	MaxLeftBorderSum = 0;
	LeftBorderSum =0;
	for(i = Center; i>=Left; i--)
	{
		LeftBorderSum += A[i];
		if(LeftBorderSum > MaxLeftBorderSum){
			MaxLeftBorderSum = LeftBorderSum;
		}
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for(i = Center + 1; i<=Right; i++){
		RightBorderSum += A[i];
		if(RightBorderSum > MaxRightBorderSum){
			MaxRightBorderSum = RightBorderSum;
		}
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubSequenceSum(const int A[],int N){
	return MaxSubSum(A,0,N-1);
}



int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd){
	int a[]={4,-3,5,-2,-1,2,6,-2};
	int maxSubSum = MaxSubSequenceSum(a,sizeof(a)/sizeof(int));
	printf("Max sub sum:%d",maxSubSum);
	system("pause");
	return 0;
}