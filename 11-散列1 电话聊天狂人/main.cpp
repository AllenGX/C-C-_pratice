// 11-散列1 电话聊天狂人.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
//#define key 91		//影响因子

typedef struct Node {
	long long int n;
	int cnt;
	struct Node *next;
}*Nodes,Nod;
typedef struct Cell{
	//Nod N[key];
	Nod *N;
}*Cells;


int insert(Cells Ce,long long int n, int keys,int max) {
	int ns = n % 100000;
	int number = ns % keys;
	Nodes N = &Ce->N[number];
	int flag = 0;
	while (N->next!=NULL)
	{
		if (N->next->n == n) {
			N->next->cnt++;
			if (N->next->cnt > max) {
				max = N->next->cnt;
			}
			flag = 1;
			break;
		}
		N = N->next;
	}
	if (flag != 1) {
		//插入
		Nodes tep = (Nodes)malloc(sizeof(Nod));
		tep->cnt = 1;
		tep->n = n;
		tep->next = NULL;
		N->next = tep;
	}
	return max;
}




int main()
{
	int n;
	scanf_s("%d", &n);
	int key = 2 * n + 1;
	Cells Ce = (Cells)malloc(sizeof(struct Cell));
	Ce->N = (Nodes)malloc(sizeof(Nod)*key);
	for (int i = 0; i < key; i++)
	{
		Ce->N[i].cnt = 0;
		Ce->N[i].next = NULL;
		Ce->N[i].n = i;
	}

	long long int ns1 = 0, ns2 = 0 ;
	int max = 1;
	for (int i = 0; i < n; i++)
	{
		
		scanf_s("%lld %lld", &ns1, &ns2);
		max=insert(Ce,ns1, key,max);
		max=insert(Ce, ns2, key,max);
	}
	long long int nss = 99999999999;
	int cnt = 0;
	for (int i = 0; i < key; i++)
	{
		Nodes NN = &Ce->N[i];
		while (NN->next != NULL)
		{
			if (NN->next->cnt==max) {
				if (NN->next->n < nss) {
					nss = NN->next->n;
				}
				cnt++;
			}
			NN = NN->next;
		}
	}
	printf("%lld %d", nss, max);
	if (cnt > 1) {
		printf(" %d", cnt);
	}

	system("pause");
    return 0;
}

