// 1017. A除以B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>


int main()
{
	char a[1001];
	int b;
	int i = 0;
	
	scanf_s("%s", a, 1001);
	scanf_s("%d", &b);
	int A = 0, P, d = 0, flag = 1, yu = 0;
	for (int i = 0; i < strlen(a); i++)
	{
		yu = yu*10 + a[i]-'0';
		if (yu / b > 0) {
			flag = 0;
		}
		if (flag == 0) {
			printf("%d", yu / b);
		}
		yu = yu % b;
	}
	printf(" %d",yu);
	system("pause");
    return 0;
}

