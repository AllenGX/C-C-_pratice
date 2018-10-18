
#include "stdafx.h"
#include<stdint.h>
#include<stdlib.h>

typedef int Elemetype;

//插入排序
void Insert_sort(int *a, int n) {
	for (int i = 1; i < n; i++)
	{
		int temp = a[i]; int j;
		for (j = i; j > 0 && a[j - 1]>temp; j--)
		{	//插入元素小于当前元素，当前元素后移
			a[j] = a[j - 1];
		}
		a[j] = temp;	//插入元素放入合适位置
	}
}



//顺序表的简单直接插入排序
void SortInsert_suzu(int *a,int length) {
	int j = 0;	
	for (int i = 1; i < length; i++) {
		a[0] = a[i];	//a[0]是岗哨
		for (j = i - 1; j > 0; j--) {
			if (a[0] >=a[j]) {
				break;
			}
			else {
				a[j + 1] = a[j];
			}
		}
		a[j + 1] = a[0];
	}
}


int main()
{
	int length=11;
	int a[] = {0,9,8,7,6,8,5,4,3,2,1};
	Insert_sort(a, length);
	for (int i = 1; i < length; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
    return 0;
}

