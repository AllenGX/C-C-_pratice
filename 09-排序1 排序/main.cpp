// 09-排序1 排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>


//归并
void Sort(int *a, int *b, int left, int right) {
	int A = left;
	int C = (left + right) / 2;
	int B = C + 1;
	int i = left;
	while (A!=C+1&&B!=right+1)
	{
		if (a[A] < a[B]) {
			b[i++] = a[A];
			A++;
		}
		else {
			b[i++] = a[B];
			B ++;
		}
	}
	while (A!=C+1)
	{
		b[i++] = a[A];
		A++;
	}
	while (B!=right+1)
	{
		b[i++] = a[B];
		B++;
	}

	for (int i = left; i <= right; i++)
	{
		a[i] = b[i];
	}
}


//分治
void Apart(int *a, int *b, int left, int right) {
	int C = (left + right) / 2;
	if (left < right) {
		Apart(a, b, left, C);
		Apart(a, b, C + 1, right);
		Sort(a, b, left, right);
	}
}

//入口
void sorts(int *a, int left, int right) {
	int b[100000];
	if (right > left) {
		Apart(a, b, left, right);
	}
}


int main()
{
	int n, m;
	scanf_s("%d\n", &n);
	int a[100000];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}

	sorts(a, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	system("pause");
    return 0;
}

