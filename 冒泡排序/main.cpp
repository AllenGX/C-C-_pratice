// 冒泡排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


void SortPao(int *a, int length) {
	int len = length,temp,flag;
	for (int i = 0; i < length; i++)
	{
		flag = 0;		//如果后面都是有序的就结束
		for (int j = 1; j < len; j++)
		{
			if (a[j - 1] > a[j]) {
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				flag++;
				temp = j;	//保留最后一个进行交换的位置
			}
		}
		len = temp;		//改进算法  len值为最后一个进行交换的位置	既该位置和后面的都是有序的
		if (flag == 0) {		//一次都没有交换结束排序
			break;
		}
	}
}

int main()
{
	int a[] = {9,8,7,6,5,4,3,2,1 };
	SortPao(a, 9);
	for (int  i = 0; i < 9; i++)
	{
		printf("%d ",a[i]);
	}
	system("pause");
    return 0;
}

