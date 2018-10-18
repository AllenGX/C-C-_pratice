// KMP算法简单版.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int isSame(char *a, char *b) {
	while (*a != '\0'&&*a++ == *b++)
		;
	return *a - *b;
}


int main()
{
	char a[10000];
	char b[10000];

	//scanf_s("%s", a,10000);
	gets_s(a, 10000);
	//scanf_s("%s", b,10000);
	gets_s(b, 10000);
	const char *p = b;
	int flag = 0;
	while ((p= strstr(p, a)))
	{
		printf("%d ", p - b);
		p=p + 1;
		flag = 1;
	}
	if (flag == 0) {
		printf("-1 ");
	}
	system("pause");
    return 0;
}

