// 1025. 反转链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
typedef int Elemetype;

typedef struct  node
{
	Elemetype head;
	Elemetype data;
	Elemetype end;
}Node;

int main()
{
	int start, number, k;
	scanf_s("%d %d %d", &start, &number, &k);
	Node *a=(Node *)malloc(sizeof(Node)*100000);
	for (int i = 0; i < number; i++)
	{
		int s, d, e;
		scanf_s("%d %d %d", &s, &d, &e);
		a[s].data = d;
		a[s].end = e;
		a[s].head = 0;
	}
	Node *b = (Node *)malloc(sizeof(Node)*number);
	int i=0;
	int m=start;
	for (m = start; a[m].end != -1; i++) {
		b[i].head = m;
		b[i].data = a[m].data;
		b[i].end = a[m].end;
		m = a[m].end;
	}
	b[i].head = m;
	b[i].data = a[m].data;
	b[i].end = a[m].end;
	int S = 0, E = k;
	while (i >= E-1) {
		
		for (int z = E-1; z >=S; z--)
		{
			if (z != S) {
				printf("%05d %d %05d\n", b[z].head, b[z].data, b[z - 1].head);
			}
			else {
				if (E + k - 1 <= i) {

					printf("%05d %d %05d\n", b[z].head, b[z].data, b[E+k - 1].head);
					
				}
				else {
					if (b[E - 1].end == -1) {
						printf("%05d %d %d\n", b[z].head, b[z].data, b[E - 1].end);
					}
					else {
						printf("%05d %d %05d\n", b[z].head, b[z].data, b[E - 1].end);
					}
				}
			}
		}
		S = E;
		E = E + k;
	}
	int j = S;
	for (; j <i; j++)
	{
		printf("%05d %d %05d\n", b[j].head, b[j].data, b[j].end);
	}
	if (j == i) {
		printf("%05d %d %d\n", b[i].head, b[i].data, b[i].end);
	}
	system("pause");
    return 0;
}

