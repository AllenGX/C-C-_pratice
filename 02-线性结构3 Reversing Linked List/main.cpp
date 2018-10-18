// 02-线性结构3 Reversing Linked List.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100000

typedef struct node {
	int data;
	int next;
}Node;
typedef struct list {
	Node a[MAXSIZE];
}List, *qList;
int Reversing(int k, qList q1, qList *q2, int count);
int main()
{
	int upaddress = 0, count = 0, startNumber = 0;
	scanf_s("%d %d %d", &upaddress, &count, &startNumber);
	qList q1 = (List *)malloc(sizeof(List));
	qList q2 = (List *)malloc(sizeof(List));
	int f = 0, d = 0, r = 0;
	for (int i = 0; i < count; i++) {
		scanf_s("%d %d %d", &f, &d, &r);
		q1->a[f].data = d;
		q1->a[f].next = r;
	}
	int m = Reversing(upaddress, q1, &q2, startNumber);
	int start = m;
	while (m != -1)
	{
		m = Reversing(m, q1, &q2, startNumber);
	}
	int a = upaddress;
	int c = upaddress, w = 0;
	while (q1->a[a].next != -1)
	{

		w++;
		if (w == startNumber - 1) {
			c = q1->a[a].next;
		}
		a = q1->a[a].next;
	}

	w++;
	if (w < startNumber) {
		c = upaddress;
	}

	while (q2->a[c].next != -1) {
		printf("%05d %d %05d\n", c, q2->a[c].data, q2->a[c].next);
		c = q2->a[c].next;
	}
	printf("%05d %d %d", c, q2->a[c].data, q2->a[c].next);
	free(q1);
	system("pause");
	return 0;
}

int Reversing(int k, qList q1, qList *q2, int count) {
	int n = 0, flag = 0, m = k, z = k, s;
	while (q1->a[k].next != -1) {
		n++;
		k = q1->a[k].next;
		if (n == count - 1) {
			flag = 1;
			break;
		}
	}
	if (flag == 1 && count != 1) {
		while (n != 0)
		{
			(*q2)->a[m].data = q1->a[m].data;
			(*q2)->a[q1->a[m].next].next = m;
			m = q1->a[m].next;
			n--;
		}
		(*q2)->a[m].data = q1->a[m].data;
		s = m;
		int f = 0;
		while (count != f) {
			if (q1->a[s].next != -1) {
				f++;
				s = q1->a[s].next;
			}
			else {
				break;
			}
		}
		if (f == count) {
			(*q2)->a[z].next = s;
		}
		else {
			(*q2)->a[z].next = q1->a[m].next;
		}
		k = q1->a[k].next;
		return k;
	}
	else {
		while (n != -1)
		{
			(*q2)->a[m].data = q1->a[m].data;
			(*q2)->a[m].next = q1->a[m].next;
			m = q1->a[m].next;
			n--;
		}
		return -1;
	}
}



