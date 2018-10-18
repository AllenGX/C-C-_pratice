// 11-散列4 Hashing - Hard Version（30 分）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>



typedef struct Nodes {
	int number;
	struct Nodes *next;
}*QNode,Node;

typedef struct N {
	int count;
	struct Nodes *next;
}*Ns, Nd;



int main()
{
	int number;
	scanf_s("%d", &number);
	//Ns n = (Ns)malloc(sizeof(Nd)*number);
	Nd n[11];
	
	for (int i = 0; i < number; i++)
	{
		n[i].count = 0;
		n[i].next = NULL;
	}
	int a[1001];
	for (int i = 0; i < number; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < number; i++)
	{
		if (a[i] >= 0) {
			if (a[i] % number == i) {

			}
			else {
				int j = i;
				while (j != a[i] % number)
				{
					j = (j + number - 1) % number;
					QNode qn = (QNode)malloc(sizeof(Node));
					qn->next = n[i].next;
					qn->number = a[j];
					n[i].next = qn;
					n[i].count++;
				}
			}
		}
	}
	int cnt = number;
	while (cnt)
	{
		int min = 100000;
		int temp = 0;
		for (int i = 0; i < number; i++)
		{
			if (n[i].count == 0 && a[i] < min) {
				min = a[i];
				temp = i;
			}
		}
		n[temp].count--;
		cnt--;
		if (min >= 0) {
			printf("%d", min);
			if (cnt != 0)printf(" ");
		}
		
	

		
		for (int i = 0; i < number; i++)
		{
			if (n[i].count > 0) {
				QNode q = n[i].next;
				while (q!=NULL)
				{
					if (q->number == min) { n[i].count--; break; }
					q = q->next;
				}
			}
		}
	}


	system("pause");
    return 0;
}

