// 08-图7 公路村村通.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MaxSzie 10000
typedef struct line {
	int qidian;
	int zhongdian;
	int changdu;
}Line;

int getTopZ(Line *l,int *parent,int f) {
	int pA= l[f].zhongdian;
	while (parent[l[f].zhongdian] != -1)
	{
		l[f].zhongdian = parent[l[f].zhongdian];
		pA = l[f].zhongdian;
	}
	return pA;
}
int getTopQ(Line *l, int *parent, int f) {
	int pA= l[f].qidian;
	while (parent[l[f].qidian] != -1)
	{
		l[f].qidian = parent[l[f].qidian];
		pA = l[f].qidian;
	}
	return pA;
}

int main()
{
	int n, m;
	scanf_s("%d %d\n", &n, &m);
	int *parent = (int *)malloc(sizeof(int)*(n+1));
	for (int i = 1; i <= n; i++)
	{
		parent[i] = -1;
	}
	Line *l = (Line *)malloc(sizeof(Line)*m);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d", &l[i].qidian, &l[i].zhongdian, &l[i].changdu);
	}
	int Longs = 0;
	int count = 0;
	while (count<(n-1))
	{
		int min = MaxSzie;
		int f=-1;
		for (int i = 0; i < m; i++)
		{
			if (l[i].changdu < min) {
				min = l[i].changdu;
				f = i;
			}
		}
		if (f == -1) {
			break;
		}

		int pA, pB;
		pA = getTopZ(l, parent, f);
		pB=getTopQ(l, parent, f);
		if (pB != pA) {
			parent[pB] = pA;
			Longs += l[f].changdu;
			count++;
		}
		
		l[f].changdu = MaxSzie;
	}

	if (count==(n-1)) {
		printf("%d", Longs);
	}
	else {
		printf("-1");
	}
	system("pause");
    return 0;
}

