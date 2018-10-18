// 简单选择排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


void swap(int *a, int A, int B) {
	int temp = a[A];
	a[A] = a[B];
	a[B] = temp;
}

int min(int *a, int start, int end) {		//注：找最小数可以采用堆排序进行改进
	int min = 100000, flag = -1;
	for (int i =start; i < end; i++)
	{
		if (a[i] < min) {
			min = a[i];
			flag = i;
		}
	}
	return flag;
}


void Easy_sort(int *a, int length) {
	int mi = 0;
	for (int i = 0; i < length; i++)	
	{
		if ((mi=min(a, i, length)) != -1) {	//从前i到length中找到一个最小的数和i交换位置
			swap(a, mi, i);
		}
	}
}


void EasyInsert_sort(int *a, int length) {
	int temp,min;
	for (int i = 0; i < length; i++) {
		min = i;
		for (int j = i+1; j < length; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		if (min != i) {
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

int main()
{
	int a[] = {9,8,7,6,5,4,3,2,1};
	int length = 9;
	Easy_sort(a, length);
	for (int i = 0; i < length; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
    return 0;
}

