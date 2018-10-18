// A+B和C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf_s("%d\n", &n);
	long int a, b, c;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%ld %ld %ld", &a, &b, &c);
		if ((a + b) > c) {
			printf("Case #%d: true", i + 1);
		}
		else {
			printf("Case #%d: false", i + 1);
		}
		if (i != (n - 1)) { printf("\n"); }
	}
	system("pause");
	return 0;
}

