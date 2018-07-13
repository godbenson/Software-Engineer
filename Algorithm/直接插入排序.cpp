// ConsoleApplication8.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#include <stdio.h>
#include "stdafx.h"
#include <stdarg.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int a[] = {5,9,7,6,3,8,4,1,2,0,1};

void quick_sort(int *a,int size) {
	for (int i = 1; i < size; i++) {
		int key = a[i];
		int j = i-1;
		while (a[j]>key && j>=0) {
			a[j + 1] = a[j];
			a[j] = key;
			j--;
		}

	}
}

int main() {
	quick_sort(a,sizeof(a)/sizeof(int));
	for (auto p : a) {
		cout << p << " ";
	}
	cin.get();
}