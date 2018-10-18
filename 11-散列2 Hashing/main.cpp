// 11-散列2 Hashing.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>


int insert(int *b, int number,int n) {
	int ns = number % n;
	if (b[ns] == -1) {
		b[ns] = number;
		return ns;
	}
	else {
		int i = 1;
		int j = 1;
		ns += j;
		while (b[ns] != -1&&ns<n)
		{
			ns -= j;
			i++;
			j = i * i;
			ns += j;
		}
		if (ns >= n || b[ns] != -1) {
			return -1;
		}
		else {
			b[ns] = number;
			return ns;
		}
	}
}


int main()
{
	int a[100000] = { 0 };
	//构造素数表
	a[0] = 1, a[1] = 1;
	for (int i = 2; i < 100000; i++)
	{
		if (a[i] == 0) {
			int j = 2 * i;
			while (j<100000)
			{
				a[j] = 1;
				j += i;
			}
		}
	}
	int n,cnt;
	scanf_s("%d %d", &n,&cnt);
	while (a[n]==1)
	{
		n++;
	}
	//int size = n;
	int *b = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		b[i] = -1;
	}
	int numbers;
	for (int i = 0; i < cnt; i++)
	{
		scanf_s("%d", &numbers);
		int tep;
		tep = insert(b, numbers, n);
		if (i < cnt - 1) {
			if (tep != -1) {
				printf("%d ", tep);
			}
			else {
				printf("- ");
			}
		}
		else {
			if (tep != -1) {
				printf("%d", tep);
			}
			else {
				printf("-");
			}
		}
	}
	system("pause");
    return 0;
}

