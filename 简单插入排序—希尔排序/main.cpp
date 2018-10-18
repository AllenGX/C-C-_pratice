// 简单插入排序—希尔排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdint.h>
#include<stdlib.h>

void Insert_sort(int *a, int n, int tep) {
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j;
		for (j = i;j-tep>=0&&a[j-tep]>temp;j-=tep)
		{
			a[j] = a[j-tep];
		}
		a[j] = temp;
	}
}

void SortInsert_suzu(int *a, int length,int d) {
	int j=0;
	for (int i = 1; i < length;i++) {
		a[0] = a[i];
		for (j = i - d; j > 0;) {
			if (a[0] >= a[j]) {
				break;
			}
			else
			{
				a[j + d] = a[j];
			}
			j -= d;
		}
		a[j + d] = a[0];
	}
}

void SortXiEr(int *a, int length) {
	for (int  i = 5; i > 0; )
	{
		Insert_sort(a, length, i);
		i -= 2;
	}
}

int main()
{
	int a[] = { 0,49,38,65,97,76,13,27,48,55,4 };
	SortXiEr(a, 11);

	for (int i = 1; i < 11; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
    return 0;
}

