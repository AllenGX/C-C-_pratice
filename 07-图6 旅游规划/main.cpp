// 07-图6 旅游规划.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// 07-图6 旅游规划.cpp: 定义控制台应用程序的入口点。
//
#include<stdio.h>

#include<stdlib.h>
#define MAXSIZE 1000000
typedef struct node {
	int start;
	int end;
	int money;
	int Long;
}Node;

typedef struct t {
	int longs;
	int states;
	int Moneys;
}T;

int main()
{
	int n, m, str, eng;
	scanf_s("%d %d %d %d", &n, &m, &str, &eng);
	Node *N = (Node *)malloc(sizeof(Node)*m);
	//保存路线
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d %d %d", &N[i].start, &N[i].end, &N[i].Long, &N[i].money);
	}

	if (n==2) {
		printf("%d %d", N[0].Long, N[0].money);
	}
	else {
		int *moneyss = (int *)malloc(sizeof(int)*n);
		int *Longs = (int *)malloc(sizeof(int)*n);
		int *states = (int *)malloc(sizeof(int)*n);
		//初始化数据
		for (int i = 0; i < n; i++)
		{
			moneyss[i] = MAXSIZE;
			Longs[i] = MAXSIZE;
			states[i] = 0;
		}

		moneyss[str] = 0;
		Longs[str] = 0;
		states[str] = 1;

		for (int i = 0; i < m; i++)
		{
			if (N[i].start == str) {
				moneyss[N[i].end] = N[i].money;
				Longs[N[i].end] = N[i].Long;
			}
			if (N[i].end == str) {
				moneyss[N[i].start] = N[i].money;
				Longs[N[i].start] = N[i].Long;
			}
		}
		while (1)
		{
			int starts = -1, min = MAXSIZE;
			for (int i = 0; i < n; i++)
			{	//找到目前最短路径
				if (states[i] != 1 && Longs[i] < min) {
					min = Longs[i];
					starts = i;
				}

			}
			if (starts == -1 || starts == eng) {
				break;
			}
			else
			{
				states[starts] = 1;
				for (int i = 0; i < m; i++)
				{
					if (N[i].start == starts && states[N[i].end] != 1) {		//从该点扫描位走过的点
						if (N[i].Long + Longs[N[i].start] < Longs[N[i].end]) {
							Longs[N[i].end] = N[i].Long + Longs[N[i].start];
							moneyss[N[i].end] = N[i].money + moneyss[N[i].start];
						}
						else if (N[i].Long + Longs[N[i].start] == Longs[N[i].end] && moneyss[N[i].end] > N[i].money + moneyss[N[i].start]) {
							moneyss[N[i].end] = N[i].money + moneyss[N[i].start];
						}
					}
					if (N[i].end == starts && states[N[i].start] != 1) {		//从该点扫描位走过的点
						if (N[i].Long + Longs[N[i].end] < Longs[N[i].start]) {
							Longs[N[i].start] = N[i].Long + Longs[N[i].end];
							moneyss[N[i].start] = N[i].money + moneyss[N[i].end];
						}
						else if (N[i].Long + Longs[N[i].end] == Longs[N[i].start] && moneyss[N[i].start] > N[i].money + moneyss[N[i].end]) {
							moneyss[N[i].start] = N[i].money + moneyss[N[i].end];
						}
					}
				}
			}
		}
		printf("%d %d", Longs[eng], moneyss[eng]);
	}
	system("pause");
	return 0;
}


