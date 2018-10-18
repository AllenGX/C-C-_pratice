// 快速排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


template<typename T>
void exChange(T *a, int aa, int bb) {
	T s = a[aa];
	a[aa] = a[bb];
	a[bb] = s;
}

template <typename T>
void midd(T *A, int a, int b) {
	int c = (a + b) / 2;
	if (A[c] > A[a] && A[c] > A[b]) {
		exChange(A, c, a);
	}
	if (A[b] > A[a] && A[b] > A[c]) {
		exChange(A,b, a);
	}
}

template <typename T>
void Sorts(T *A, int left, int right) {
	if (left >= right) {
		return;
	}
	int lefts = left;
	int rights = right;
	midd(A, left, right);
	T key = A[left];
	while (lefts<rights)
	{
		while (lefts<rights&&key<=A[rights])
		{
			rights--;
		}
		A[lefts] = A[rights];
		while (lefts<rights&&key >= A[rights])
		{
			lefts++;
		}
		A[rights]= A[lefts];
	}
	A[lefts] = key;
	Sorts(A, left, lefts - 1);
	Sorts(A, lefts + 1, right);
}










void sorts(int *a, int left, int right)
{
	if (left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
	{
		return;
	}
	int i = left;
	int j = right;
	int key = a[left];

	while (i < j)                               /*控制在当组内寻找一遍*/
	{
		while (i < j && key <= a[j])
			/*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
			序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
		{
			j--;/*向前寻找*/
		}

		a[i] = a[j];
		/*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
		a[left]，那么就是给key）*/

		while (i < j && key >= a[i])
			/*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
			因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
		{
			i++;
		}

		a[j] = a[i];
	}

	a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
	sorts(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
	sorts(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
						  /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}




void QuickSort(int *a,int head,int end) {
	int temp,i=head,j=end;	//第一个元素为岗哨
	while (i<j) {
		while (a[head] > a[i]) {	//i指向比岗哨大的
			i++;
		}
		while (a[head] < a[j]) {	//j指向比岗哨小的
			j--;
		}
		if (i<j) {	//i和j交换
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i];	//i和j相遇后	岗哨 和 i 交换
	a[i] = a[head];
	a[head] = temp;
	temp = i;	//i表示岗哨的位置
	if (head < end) {	//递归执行岗哨左右
		QuickSort(a, head, i-1);
		QuickSort(a, i+1, end);
	}

}

int main()
{
	int a[] = { 2,3,4,6,7,1,8,9,5 };
	double b[] = { 2,3,4,6,7,1,8,9,5 };
	char d[]= { '2','3','4','6','7','1','8','9','5' };
	int *c = a;
	sorts(a, 0, 8);

	//泛型的快排
	Sorts<int>(c, 0, 8);
	Sorts<double>(b,0,8);
	Sorts<char>(d, 0, 8);





	for (int  i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 9; i++)
	{
		printf("%f ", b[i]);
	}
	printf("\n");
	for (int i = 0; i < 9; i++)
	{
		printf("%c ", d[i]);
	}

	system("pause");
    return 0;
}

