// 1016. 部分A+B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char pa[100], pb[100];
	int a,b;
	scanf_s("%s", pa,100);
	scanf_s("%d", &a);

	scanf_s("%s", pb,100);
	scanf_s("%d", &b);
	int i = 0;
	int numbera = 0;
	while (pa[i]!='\0')
	{
		if (pa[i] == (a + '0')) {
			numbera++;
		}
		i++;
	}
	i = 0;
	int numberb = 0;
	while (pb[i] != '\0')
	{
		if (pb[i] == (b + '0')) {
			numberb++;
		}
		i++;
	}
	int PA = 0, PB = 0;
	for (int i = 0; i < numbera; i++)
	{
		PA = PA * 10 + a;
	}
	for (int i = 0; i < numberb; i++)
	{
		PB = PB * 10 + b;
	}
	printf("%d", PA + PB);
	system("pause");
    return 0;
}

