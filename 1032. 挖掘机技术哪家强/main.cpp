// 1032. 挖掘机技术哪家强.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main() {
	int a[100001] = { 0 };

	int n;
	cin >> n;
	int number, grade;
	for (int i = 1; i <= n; i++) {
		cin >> number >> grade;
		a[number] += grade;
	}
	int max = 0, traget = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]>max) {
			max = a[i];
			traget = i;
		}
	}
	cout << traget << " " << max;
	return 0;
}
