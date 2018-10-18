// 08-图9关键活动.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10000
typedef struct Node {
	int El;
	int La;
}Nodes;

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	int DEEP[101] = { 0 };	//保存点的度数
	int sort[101] = { 0 };	//保存排序结果
	int a[101][101] = { 0 };	//保存路径长度
	int end[101];
	int b[101][101];	//保存关键路径
	int sunxu[101];		//保存顺序
	Nodes *N = (Nodes *)malloc(sizeof(Nodes)*(n+1));
	for (int i = 1; i <= n; i++)
	{
		
		end[i] = -1;
		N[i].El = 0;
		N[i].La = MaxSize;
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = -1;
			b[i][j] = -1;
		}
	}
	int qi, zhong, chang, count = 0, px = 0, countt = 1;
	for (int j = 1; j <= m; j++)
	{
		px = 0;
		scanf_s("%d %d %d", &qi, &zhong, &chang);
		a[qi][zhong] = chang;
		DEEP[zhong]++;
		for (int y = 1; y < j; y++)
		{
			if (zhong == sunxu[y]) {
				px = 1;
				break;
			}
		}
		if (px != 1) {
			sunxu[countt] = zhong;
			countt ++ ;
		}
	}
	int ss = 1, flag = 0,isend=1,QQ=1;
	for (int i = 1; i <= n; i++)
	{
		int z=1,isend=1;
		for (z = 1; z<=n; z++)
		{
			if (a[i][z] != -1) { isend = 0; break; }	//不是结束点
		}
		if (isend == 1) {
			end[count] = i;
			count++;
		}
		flag = -1;
		for (int j = 1; j <= n; j++)
		{
			if (DEEP[j] == 0) {
				flag = 0;
				DEEP[j] = -1;
				sort[ss] = j;
				ss++;
				for (int k = 1; k <= n; k++)
				{
					if (a[j][k] != -1) {
						DEEP[k]--;
					}
				}
				break;
			}
		}
		if (flag == -1) {
			break;
		}
	}
	if (flag == 0) {
		int max = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[j][sort[i]] != -1) {
					if (N[sort[i]].El < N[j].El + a[j][sort[i]]) {
						N[sort[i]].El = a[j][sort[i]] + N[j].El;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (N[i].El > max) {
				max = N[i].El;
			}
		}
		printf("%d\n", max); int lengths = 0;
		for (int z = 0; z < count; z++)
		{
			N[end[z]].La = max;
		}
		for (int l = n; l>=1; l--)
		{
			for (int i = 1; i <=n; i++)
			{
				if (a[i][sort[l]]!=-1) {
					if (N[sort[l]].La - a[i][sort[l]] < N[i].La) {
						N[i].La = N[sort[l]].La - a[i][sort[l]];
					}
				}
			}
			for (int x = 1; x <=n; x++)
			{
				if (a[x][sort[l]] != -1) {
					if (N[sort[l]].La - a[x][sort[l]] == N[x].La&&N[x].La== N[x].El) {
						b[x][sort[l]] = 1;
						lengths++;
					}
				}
			}
		}
		for (int p = 1; p <= n; p++) {
			for (int k = countt - 1; k >= 1; k--) {
				if (b[p][sunxu[k]] == 1) {
					printf("%d->%d", p, sunxu[k]);
					lengths--;
					printf("\n");
				}
			}
		}
	}
	else {
		printf("0");
	}
	system("pause");
	return 0;
}