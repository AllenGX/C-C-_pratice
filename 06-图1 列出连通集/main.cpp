// 06-图1 列出连通集.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>

typedef struct node {
	int y;
}Node;

typedef struct line {
	int end;
	int top;
	Node a[10];
}Line,*qLine;

typedef struct stack {
	int top;
	Node a[10];
}Stack, *qStack;


Node Pop(qStack s) {
	Node n;
	n = s->a[s->top];
	s->top--;
	return n;
}

void Push(qStack s,Node n) {
	s->top++;
	s->a[s->top] = n;
}

//遍历
void LookAll(int a[][10],qStack s,int *b,int numbers) {
	int start = 0, flag = 0, count = 0;
	while (count!=numbers)
	{
		for (int i = 0; i < numbers; i++)
		{
			if (b[i] == 0) {
				start = i;
				break;
			}
		}
		Node N, n;
		N.y = start;
		Push(s, N);
		printf("{");
		printf(" %d", N.y);
		b[N.y] = 1;
		count++;
		while (s->top != -1)
		{
			flag = 0;
			n.y = s->a[s->top].y;
			for (int i = 0; i < numbers; i++)
			{
				if (a[n.y][i] == 1&& b[i] != 1) {
					start = i;
					N.y = start;
					Push(s, N);
					printf(" %d", N.y);
					b[N.y] = 1;
					count++;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				Pop(s);
			}
		}
		printf(" }\n");
	}
}


Node Popl(qLine s) {
	Node n;
	s->top++;
	n = s->a[s->top];
	
	return n;
}

void Pushl(qLine s, Node n) {
	s->end++;
	s->a[s->end] = n;
}

//遍历
void LookAlL (int a[][10], qLine s, int *b, int numbers) {
	int count = 0, m = 0;
	while (count != numbers)
	{
		for (int k = 0; k < numbers; k++)
		{
			if (b[k] == 0) {
				m = k;
				break;
			}
		}
		Node N;
		N.y = m;
		printf("{");
		Pushl(s, N);
		b[N.y] = 1;
		while (s->top != s->end)
		{
			Node x = Popl(s);
			printf(" %d", x.y);
			count++;
			b[x.y] = 1;
			for (int i = 0; i <numbers; i++)
			{
				if (a[x.y][i] == 1 && b[i] != 1) {
					Node n;
					n.y = i;
					Pushl(s, n);
					b[n.y] = 1;
				}
			}
		}
		printf(" }\n");
	}
}



int main()
{
	int a[10][10] = { 0 };

	int n, L;
	scanf_s("%d %d", &n, &L);

	int b[10] = { 0 };
	int c[10] = { 0 };
	int x, y;
	for (int i = 0; i < L; i++)
	{
		scanf_s("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}

	a;

	qLine q = (Line *)malloc(sizeof(Line));
	q->end = 0;
	q->top = 0;

	qStack p = (Stack *)malloc(sizeof(Stack));
	p->top = -1;
	


	LookAll(a, p, b, n);

	LookAlL(a, q, c, n);


	system("pause");
    return 0;
}

