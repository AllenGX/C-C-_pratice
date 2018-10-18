// 07-图5 Saving James Bond - Hard Version.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node {
	int x;
	int y;
}Node, *qNode;

typedef struct nodes {
	int visited;
	int fater;
	int ceng;
	int number;
}Nodes, *qNodes;

typedef struct line {
	int li[102];
	int top;
	int end;
}Line,*qLine;

typedef struct stack {
	int li[102];
	int top;
}Stack,*qStack;


int Pop(qLine *q) {
	int i=-1;
	if ((*q)->top!= (*q)->end) {
		(*q)->top++;
		i = (*q)->li[(*q)->top];
	}
	 return i;
}

void Pushs(qStack *q, int i) {
	(*q)->top++;
	(*q)->li[(*q)->top] = i;
}

int Pops(qStack *q) {
	int i = -1;
	if ((*q)->top != -1) {
		i = (*q)->li[(*q)->top];
		(*q)->top--;
	}
	return i;
}

void Push(qLine *q, int i) {
	(*q)->end = ((*q)->end + 1) % 102;
	(*q)->li[(*q)->end] = i;
}

int main() {
	int N, M;
	scanf_s("%d %d ", &N, &M);
	Node *a = (Node *)malloc(sizeof(Node)*(N+1));
	int X, Y;
	a[0].x = 0;
	a[0].y = 0;
	for (int i = 1; i <= N; i++) {
		scanf_s("%d %d", &X, &Y);
		a[i].x = X;
		a[i].y = Y;
	}
	if (M >= 35) {
		
		printf("1");
	}
	else {
		int B[101][101] = { 0 };

		//构建邻接矩阵
		for (int i = 1; i <= N; i++) {
			if ((a[i].x - a[0].x)*(a[i].x - a[0].x) + (a[i].y - a[0].y)*(a[i].y - a[0].y) <= (M + 7.5) * (M + 7.5)) {
				B[i][0] = 1;
				B[0][i] = 1;
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if ((a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y) <= M * M&&i != j) {
					B[i][j] = 1;
					B[j][i] = 1;
				}
			}
		}
		//标识数组
		Nodes *S = (Nodes *)malloc(sizeof(Nodes)*(N + 1));
		for (int i = 0; i <= N; i++)
		{
			S[i].number = 0;
			S[i].fater = -1;
			S[i].visited = 0;	//0表示没走过
			S[i].ceng = 0;
		}
		//队列
		qLine  q = (qLine)malloc(sizeof(Line));
		q->top = 0;
		q->end = 0;
		Push(&q, 0);
		S[0].visited = 1;
		//栈
		qStack p = (qStack)malloc(sizeof(Stack));
		p->top = -1;

		//广度便利
		int W;
		while (q->top != q->end)
		{
			W = Pop(&q);
			if ((abs(a[W].x)) >= (50 - M) || (abs(a[W].y)) >= (50 - M)) {
				S[W].number = 1;
				continue;
			}
			for (int i = 0; i <= N; i++) {
				if (B[W][i] == 1 && S[i].visited != 1) {
					Push(&q, i);
					S[i].visited = 1;
					S[i].fater = W;
					S[i].ceng = S[W].ceng + 1;
				}
			}
		}

		int min = 1000, traget = -1, onceJump = 10001, answer = -1;;
		for (int i = 0; i <= N; i++)	//获得最小跳
		{
			if (S[i].number == 1 && S[i].ceng < min) {
				min = S[i].ceng;
				//traget = i;
			}

		}
		if (min==1000) {
			printf("0");
		}
		else {
			int j;
			for (int i = 0; i <= N; i++)
			{
				//更新最短路
				if (S[i].ceng == min && S[i].number == 1) {
					traget = i;
					j = i;
					while (S[j].ceng != 1)
					{
						j = S[j].fater;
					}
					j = a[j].x*a[j].x + a[j].y*a[j].y;
					if (onceJump > j) {
						onceJump = j;
						answer = traget;
					}
				}

			}
			int cc = answer;
			for (int i = 0; i < min; i++)
			{
				Pushs(&p, cc);
				cc = S[cc].fater;
			}
			printf("%d\n", min + 1);
			int k;
			for (int i = 0; i < min; i++)
			{
				k = Pops(&p);
				printf("%d %d\n", a[k].x, a[k].y);
			}
		}
	}
	system("pause");
	return 0;
}

