// 归并排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

//归并简化							right可以取到
void sort(int *a, int *b, int left, int right) {
	int center = left + (right - left) / 2;
	int A = left;
	int B = center+1;
	int K = left;
	while (A!=center+1&&B!=right+1)
	{
		if (a[A] > a[B]) {
			b[K++] = a[A++];
		}
		else {
			b[K++] = a[B++];
		}
	}
	while (A!=center+1)
	{
		b[K++] = a[A++];
	}
	while (B!=right+1)
	{
		b[K++] = a[B++];
	}
	//printf("%d", b[7]);
	for (int i = left; i <= right; i++)
	{
		a[i] = b[i];
	}
}

//分治
void apart(int *a, int *b, int left, int right) {
	int center = (right - left) / 2 + left;
	if (left < right) {
		apart(a, b, left, center);
		apart(a, b, center + 1, right);
		sort(a, b, left, right);
	}
}

//分治出口
void fenzhi_sort(int *a,int length) {
	int *b = (int *)malloc(sizeof(int)*(length));
	//printf("%d",b[7]);
	if (b != NULL) {
		apart(a, b, 0, length - 1);		//0到length-1个数
		free(b);
	}
	else {
		printf("空间不足");
	}

}

//分治非递归
void Merge(int *a, int *b, int left, int right) {
	int center = left + (right - left) / 2;
	int A = left;
	int B = center + 1;
	int K = left;
	while (A != center + 1 && B != right + 1)
	{
		if (a[A] > a[B]) {
			b[K++] = a[A++];
		}
		else {
			b[K++] = a[B++];
		}
	}
	while (A != center + 1)
	{
		b[K++] = a[A++];
	}
	while (B != right + 1)
	{
		b[K++] = a[B++];
	}
}

void Merge_pass(int *a, int *b, int length, int tep) {
	int i;
	for (i = 0; i+2*tep <= length; i+=2*tep)
	{
		Merge(a, b, i, i + 2 * tep - 1);
	}
	if (i + tep < length-1) {
		Merge(a, b, i,length - 1);
	}
	else {
		for (int j = i; j < length; j++)
		{
			b[j] = a[j];
		}
	}
}

void Merge_sort(int *a, int length) {
	int *b = (int *)malloc(sizeof(int)*length);
	int tep = 1;
	while (tep<length)
	{
		Merge_pass(a, b, length, tep);		//把数据归并在b中
		tep *= 2;	
		Merge_pass(b, a, length, tep);		//报数据归并回a中
		tep *= 2;
	}
	free(b);
}

int main()
{
	int length = 8;
	int a[8] = { 1,2,3,4,5,6,7,8 };
	Merge_sort(a, 8);

	for (int i = 0; i < 8; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
    return 0;
}

