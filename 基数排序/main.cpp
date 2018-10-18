// 基数排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>

typedef struct node {
	int data;
	int next;
}Node;

typedef struct q {
	int head;
	int end;
}Q;

void SortJ(Node *a,Q *q,int length) {
	int ten = 0,number=1;
	while (number!=0)
	{
		for (int i = 0; i < length; i++)
		{
			number = a[i].data;
			for (int j = 0; j < ten; j++)
			{
				number = number / 10;
			}
			if (number == 0) {
				break;
			}
			switch (number % 10)
			{
			case 0:
				if (q[0].head == -1) {
					q[0].head = i;
					q[0].end = i;
				}
				else {
					a[q[0].end].next = i;
					q[0].end = i;
				}
				break;
			case 1:
				if (q[1].head == -1) {
					q[1].head = i;
					q[1].end = i;
				}
				else {
					a[q[1].end].next = i;
					q[1].end = i;
				}
				break;
			case 2:
				if (q[2].head == -1) {
					q[2].head = i;
					q[2].end = i;
				}
				else {
					a[q[2].end].next = i;
					q[2].end = i;
				}
				break;
			case 3:
				if (q[3].head == -1) {
					q[3].head = i;
					q[3].end = i;
				}
				else {
					a[q[3].end].next = i;
					q[3].end = i;
				}
				break;
			case 4:
				if (q[4].head == -1) {
					q[4].head = i;
					q[4].end = i;
				}
				else {
					a[q[4].end].next = i;
					q[4].end = i;
				}
				break;
			case 5:
				if (q[5].head == -1) {
					q[5].head = i;
					q[5].end = i;
				}
				else {
					a[q[5].end].next = i;
					q[5].end = i;
				}
				break;
			case 6:
				if (q[6].head == -1) {
					q[6].head = i;
					q[6].end = i;
				}
				else {
					a[q[6].end].next = i;
					q[6].end = i;
				}
				break;
			case 7:
				if (q[7].head == -1) {
					q[7].head = i;
					q[7].end = i;
				}
				else {
					a[q[7].end].next = i;
					q[7].end = i;
				}
				break;
			case 8:
				if (q[8].head == -1) {
					q[8].head = i;
					q[8].end = i;
				}
				else {
					a[q[8].end].next = i;
					q[8].end = i;
				}
				break;
			case 9:
				if (q[9].head == -1) {
					q[9].head = i;
					q[9].end = i;
				}
				else {
					a[q[9].end].next = i;
					q[9].end = i;
				}
				break;
			default:
				break;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (q[i].head != -1) {
				a[q[i].end].next = q[i + 1].head;
			}
		}
		ten++;
	}
}

int main()
{
	Node *a;
	a = (struct node *)malloc(sizeof(node) * 9);
	for (int i = 0; i < 9; i++) {
		a[i].data = (9-i);
		a[i].next = i+1;
	}

	Q *q;
	q = (Q *)malloc(sizeof(Q) * 9);
	for (int i = 0; i <= 9; i++)
	{
		q[i].end = -1;
		q[i].head = -1;
	}

	SortJ(a, q, 9);
	int n;
	for (int i = 0; i < 9; i++)
	{
		if (q[i].head != -1) {
			n = q[i].head;
			break;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		printf("%d ",a[n].data);
		n = a[n].next;
	}

	system("pause");
    return 0;
}

