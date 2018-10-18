// 10-排序4 统计工龄.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[51] = { 0 };
	int n;
	scanf_s("%d\n", &n);
	int data;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &data);
		a[data]++;
	}

	for (int i = 0; i < 52; i++)
	{
		if (a[i] != 0) {
			printf("%d:%d\n", i, a[i]);
		}
	}
	system("pause");
    return 0;
}

