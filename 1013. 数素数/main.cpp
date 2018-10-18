// 1013. 数素数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{

	int a[10002];
	for (int i = 2; i < 10002; i++)
	{
		a[i] = 1;
	}
	for (int i = 2; i < 10002; i++)
	{
		if (a[i] == 1) {
			for (int j = 2*i; j < 10002; )
			{
				a[j] = 0;
				j += i;
			}
		}
	}
	int n, m;
	scanf_s("%d %d", &n, &m); 
	int z = 0,count=1,count2=1;
	for (int i = 2; i < 10002; i++)
	{
		if (a[i] == 1) {
			if (count >= n && count <= m) {
				if (z == 9||count2==(m-n+1)) {
					printf("%d", i);
					z++;
					count2++;
				}
				else {
					printf("%d ", i);
					z++;
					count2++;
				}
				if (z == 10) {
					z = z - 10;
					printf("\n");
				}
			}
			count++;
		}
	}
	system("pause");
    return 0;
}

