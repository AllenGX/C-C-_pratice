// 09-排序3 Insertion or Heap Sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<stdlib.h>
#include<stdio.h>

int isSame(int *a, int *b, int length) {
	int m = 0;
	for (int i = 0; i < length; i++)
	{
		if (a[i] != b[i]) {
			m = 1;
		}
	}
	if (!m) {
		return 1;
	}
	else {
		return 0;
	}
}

int Max(int a, int b,int *q) {
	return q[a] > q[b] ? a : b;
}

int main()
{
	int n, m;
	scanf_s("%d\n", &n);
	int flag = 0;
	int a[101];
	int aa[101];
	int b[101];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
		//aa[i] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &b[i]);
		aa[i + 1] = b[i];
	}
	int temp;

	for (int i = 0; i < n; i++)
	{
		if (isSame(a, b, n)) {
			flag = 1;
			printf("Insertion Sort\n");
			int L;
			if (i == 0) {
				L = 2;
			}
			else {
				L = i;
			}
			if (L < n) {
				temp = a[L];
				for (int j = 0; j < L; j++)
				{
					if (a[j] > a[L]) {
						int z;
						for (z = L - 1; z >= j; z--)
						{
							a[z + 1] = a[z];
						}
						a[j] = temp;
						break;
					}
				}
			}
			for (int m = 0; m < n; m++)
			{
				printf("%d", a[m]);
				if (m != n - 1) {
					printf(" ");
				}
			}
			break;
		}
		temp = a[i];
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[i]) {
				int z;
				for (z = i - 1; z >= j; z--)
				{
					a[z + 1] = a[z];
				}
				a[j] = temp;
				break;
			}
		}
	}
	if (flag == 0) {
		printf("Heap Sort\n");
		int i;
		for ( i = n; i >0; i--)
		{
			if (aa[i] < aa[1]) {
				int temp = aa[i];
				aa[i] = aa[1];
				aa[1] = temp;
				break;
			}
		}
		for (int j = 1; j < i;)
		{
			if ((2 * j + 1) < i && (aa[j] < aa[j * 2] || aa[j] < aa[j * 2 + 1])) {
				int k = Max(2 * j, 2 * j + 1, aa);
				int temp = aa[k];
				aa[k] = aa[j];
				aa[j] = temp;
				j = k;
			}
			else if ((2 * j) ==i-1 && (aa[j] < aa[j * 2])){
				int k = 2 * j;
				int temp = aa[k];
				aa[k] = aa[j];
				aa[j] = temp;
				j = k;
			}
			else {
				break;
			}
		}
		for (int m = 1; m <= n; m++)
		{
			printf("%d", aa[m]);
			if (m != n) {
				printf(" ");
			}
		}

	}
	system("pause");
	return 0;
}


