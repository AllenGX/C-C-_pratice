// 堆排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>

void swap(int *a, int A, int B) {
	int temp = a[A];
	a[A] = a[B];
	a[B] = temp;
}

//方法一

int max(int *a, int A, int B,int length) {
	if (B<length) {
		return a[A] > a[B] ? A : B;
	}
	else if (A < length) {
		return A;
	}
	else {
		return -1;
	}
}

void bulid(int *a, int n,int length) {
	int temp = a[n];	//保存当前元素
	while (1)
	{
		int mx = max(a, n * 2 + 1, n * 2 + 2, length);	//如果当前元素的子节点存在
		if (mx != -1&& temp<a[mx]) {	//且子节点大于父节点
			a[n] = a[mx];	//子节点上移
			n = mx;	//下标指向子节点，继续比较
		}	
		else {
			a[n] = temp;
			break;
		}
	}
}
void Dui_sort(int *a, int length) {
	for (int i = length / 2; i >= 0; i--)		//注意都需要从后往前遍历
	{
		bulid(a, i, length);	
	}

	for (int i = length - 1; i >= 0; i--)
	{
		swap(a, 0, i);	//交换堆顶和最后一个元素			按照升序排列堆顶应该为最大元素所以放在最后
		bulid(a, 0, i);
	}
}



//方法二	


//注：方法二不是正规的构建最大堆，原因是下标从0开始

//构建最大堆
void bulidHeap(int *a, int length) {
	for (int j = length - 1; j >0; j--)
	{
		int i; int temp = a[j];
		for (i = j; i != 0 && temp > a[i / 2]; i /= 2)
		{
			a[i] = a[i / 2];
		}
		a[i] = temp;
	}
}

//堆排序
void dui_sort(int *a, int length) {
	
	for (int i = 0; i < length; length--)
	{
		bulidHeap(a, length);	//前length个元素建立最大堆
		swap(a, 0,length - 1);	//交换堆顶和最后一个元素			按照升序排列堆顶应该为最大元素所以放在最后
	}
}




int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	int length = 9;

	
	Dui_sort(a, length);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}

	system("pause");
    return 0;
}

