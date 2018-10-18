// 09-排序2 Insert or Merge.cpp: 定义控制台应用程序的入口点。
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

//归并
void sort(int *a, int *b, int left, int right,int center) {
	if (left < right) {
		int Center = center;
		int A = left;
		int B = Center + 1;
		int K = left;
		while (A != Center + 1 && B != right + 1)
		{
			if (a[A] < a[B]) {
				b[K++] = a[A++];
			}
			else {
				b[K++] = a[B++];
			}
		}
		while (A != Center + 1) {
			b[K++] = a[A++];
		}
		while (B != right + 1)
		{
			b[K++] = a[B++];
		}
		for (int i = left; i <= right; i++)
		{
			a[i] = b[i];
		}
	}
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
		aa[i] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &b[i]);
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
				for (z = i-1; z >= j; z--)
				{
					a[z + 1] = a[z];
				}
				a[j] = temp;
				break;
			}
		}
	}
	if (flag == 0) {
		int c[101];
		printf("Merge Sort\n");
		int length = 1;
		while (length<n)
		{
			int i = 0;
			if (isSame(aa, b, n)) {
				i = 0;
				length *= 2;
				for (i = 0; i + length - 1 < n;)
				{
					sort(aa, c, i, i + length - 1, (i + i + length - 1) / 2-1);
					i += length;
				}
				if (n - i > length / 2) {
					sort(aa, c, i, n - 1, i + length / 2);
				}
				for (int m = 0; m < n; m++)
				{
					printf("%d", aa[m]);
					if (m != n - 1) {
						printf(" ");
					}
				}
				break;
			}
			i = 0;
			length *= 2;
			for (i = 0; i + length - 1 < n;)
			{
				sort(aa, c, i, i + length - 1,(i+i+length-1)/2);
				i += length;
			}
			if (n - i > length / 2) {
				sort(aa, c, i, n-1,i+length/2-1);
			}
			if (isSame(aa, b, n)) {
				i = 0;
				length *= 2;
				for (i = 0; i + length - 1 < n;)
				{
					sort(aa, c, i, i + length - 1, (i + i + length - 1) / 2);
					i += length;
				}
				if (n - i > length / 2) {
					sort(aa, c, i, n - 1, i + length / 2-1);
				}
				for (int m = 0; m < n; m++)
				{
					printf("%d", aa[m]);
					if (m != n - 1) {
						printf(" ");
					}
				}
				break;
			}
		}
	}
	
	system("pause");
    return 0;
}

