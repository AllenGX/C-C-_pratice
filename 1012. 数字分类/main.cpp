// 1012. 数字分类.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A0[1000] = { 0 };
	int A1[1000] = { 0 };
	int A2[1000] = { 0 };
	int A3[1000] = { 0 };
	int A4[1000] = { 0 };
	int A5[1000] = { 0 };

	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf_s(" %d", &A0[i]);
		if (A0[i] % 5 == 0) {
			A1[i] = A0[i];
		}
		if (A0[i] % 5 == 1) {
			A2[i] = A0[i];
		}
		if (A0[i] % 5 == 2) {
			A3[i] = A0[i];
		}
		if (A0[i] % 5 == 3) {
			A4[i] = A0[i];
		}
		if (A0[i] % 5 == 4) {
			A5[i] = A0[i];
		}
	}
	int max = 0;
	int count = 0;
	int count1 = 0;
	long int midd = 0;
	long int num1 = 0;
	long int num2 = 0;
	int flag = 0;
	int j = -1;
	int k
		= 1;
	for (int i = 0; i < n; i++)
	{

		if (A1[i] != 0 && A1[i] % 2 == 0) {
			num1 += A1[i];
		}
		if (A2[i] != 0) {
			flag = 1;
			num2 += k * A2[i];
			k = k * j;
		}
		if (A3[i] != 0) {
			count++;
		}
		if (A4[i] != 0) {
			midd += A4[i];
			count1++;
		}
		if (A5[i] != 0) {
			if (A5[i] > max) {
				max = A5[i];
			}
		}

	}
	if (num1 == 0) {
		printf("N");
	}
	else {
		printf("%ld", num1);
	}
	if (flag == 0) {
		printf(" N");
	}
	else {
		printf(" %ld", num2);
	}
	if (count == 0) {
		printf(" N");
	}
	else {
		printf(" %d", count);
	}
	if (midd == 0) {
		printf(" N");
	}
	else {
		printf(" %.1lf", midd / (count1*1.0));
	}
	if (max == 0) {
		printf(" N");
	}
	else {
		printf(" %d", max);
	}

	
	system("pause");
	return 0;
}

