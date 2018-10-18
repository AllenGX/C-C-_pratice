// 1024. 科学计数法.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n=0, m=0, E=0;
	char a[200];
	int flag = 0;
	do
	{
		if (flag == 1)m++;
		scanf_s("%c", &a[n]);
		if (a[n] == '.')flag = 1;
		n++;
	} while (a[n-1]!='E');
	char s;
	scanf_s("%c", &s);
	scanf_s("%d", &E);
	if (s == '+') {
		if (E >= m-1) {
			for (int i = 0; i < n - 1; i++)
			{
				if (a[i] != '.'&&a[i]!='+') {
					printf("%c", a[i]);
				}
			}
			for (int i = n-1; i <=E+2; i++)
			{
				printf("0");
			}
		}
		else {
			if (a[0] != '+')printf("%c", a[0]);
			printf("%c", a[1]);
			int i;
			for (i = 3; i < 3+E; i++)
			{
				printf("%c", a[i]);
			}
			printf(".");
			for (;i < n-1; i++)
			{
				printf("%c", a[i]);
			}
		}
	}
	else {
		if (E >= 1) {
			if (a[0] != '+')printf("%c", a[0]);
			printf("0.");
			for (int i = 1; i < E; i++)
			{
				printf("0");
			}
			for (int i = 0; i < n - 1; i++)
			{
				if (a[i] != '.'&&a[i] != '+'&&a[i] != '-') {
					printf("%c", a[i]);
				}
			}
			
		}
		else {
			
			for (int i = 0; i < n - 1; i++)
			{
				if (a[i] != '+'&&a[i] != '-') {
					printf("%c", a[i]);
				}
			}
		}
	}
	system("pause");
    return 0;
}

