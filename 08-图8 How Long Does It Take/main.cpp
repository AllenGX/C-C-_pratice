// 08-图8 How Long Does It Take.cpp: 定义控制台应用程序的入口点。
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
	int n,m;
	scanf_s("%d %d", &n, &m);
	int DEEP[101] = { 0 };	//保存点的度数
	int sort[101] = { 0 };	//保存排序结果
	int a[101][101] = { 0 };	//保存路径长度
	int start[100];

	Nodes *N = (Nodes *)malloc(sizeof(Nodes)*n);
	for (int i = 0; i < n; i++)
	{
		start[i] = -1;
		N[i].El = 0;
		N[i].La = MaxSize;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = -1;
		}
	}
	int qi, zhong, chang;
	for (int j = 0; j < m; j++)
	{
		scanf_s("%d %d %d", &qi, &zhong, &chang);
		a[qi][zhong] = chang;
		DEEP[zhong]++;
	}
	int ss = 0,flag=0;
	for (int i = 0; i < n; i++)
	{
		flag = -1;
		for (int j = 0; j < n; j++)
		{
			if (DEEP[j] == 0) {
				flag = 0;
				DEEP[j] = -1;
				sort[ss] = j;
				ss++;
				for (int k = 0; k < n; k++)
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
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[j][sort[i]] != -1) {
					if (N[sort[i]].El < N[j].El + a[j][sort[i]]) {
						N[sort[i]].El = a[j][sort[i]] + N[j].El;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (N[i].El > max) {
				max = N[i].El;
			}
		}
		printf("%d",max);
	}
	else {
		printf("Impossible");
	}
	system("pause");
	return 0;
}