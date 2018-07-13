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

void bubble_sort(int *a,int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i-1; j++) {
			if (a[j] > a[j+1]) {
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}

int main() {
	bubble_sort(a,sizeof(a)/sizeof(int));
	for (auto p : a) {
		cout << p << " ";
	}
	cin.get();
}