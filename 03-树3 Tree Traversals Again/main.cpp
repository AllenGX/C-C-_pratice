// 03-树3 Tree Traversals Again.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
typedef struct line {
	int a[MAXSIZE];
	int f;
	int r;
}Line,*qLine;

typedef struct SNode {
	int a[MAXSIZE];
	int top;
}Stack,*qStack;
void Push(qStack *q, int X);
int Pop(qStack *q);
int Get(qStack q);
void pirnt(qLine q,int count);
int PopLine(qLine *q);
void PushLine(qLine *q, int X);
int main()
{
	qLine line = (Line*)malloc(sizeof(Line));
	line->f = 0;
	line->r = 0;
	qStack stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	int count = 0,number=0,temp=0;
	char a[5];
	scanf_s("%d", &count);
	int nn = count;
	if (count == 1) {
		scanf_s("%s", a, 5);
		scanf_s("%d", &number);
		printf("%d", number);
	}
	else {
		while (count)
		{
			scanf_s("%s", a, 5);
			if (a[0] == 'P'&&a[1] == 'u'&&a[2] == 's'&&a[3] == 'h') {
				Pop(&stack);
				scanf_s("%d", &number);
				Push(&stack, number);
				Push(&stack, -2);
				Push(&stack, -2);
				count--;
			}
			else {
				do {
					temp = Pop(&stack);
					if (temp >=0) {
						PushLine(&line, temp);
					}
				} while (Get(stack) != -2);
			}
		}
		while (Get(stack) != -1) {
			temp = Pop(&stack);
			if (temp >= 0) {
				PushLine(&line, temp);
			}
		} 
		pirnt(line,nn);
	}

	system("pasue");
	return 0;
}



void Push(qStack *q, int X) {
	if ((*q)->top < MAXSIZE - 1) {
		(*q)->top++;
		(*q)->a[(*q)->top] = X;
	}
}

int Pop(qStack *q) {
	int n = -1;
	if ((*q)->top != -1) {
		n = (*q)->a[(*q)->top];
		(*q)->top--;
	}
	return n;
}

int Get(qStack q) {
	int n = -1;
	if (q->top != -1) {
		n = q->a[q->top];	
	}
	return n;
}

void PushLine(qLine *q,int X) {
	if (((*q)->r- (*q)->f+1+MAXSIZE)%MAXSIZE!=0) {
		(*q)->r++;
		(*q)->a[(*q)->r] =X;
	}
}

int PopLine(qLine *q) {
	if ((*q)->r != (*q)->f) {
		(*q)->f++;
		return (*q)->a[(*q)->f];
	}
	return -1;
}

void pirnt(qLine q ,int count) {
	if (q->r != q->f) {
		while ((count-1))
		{
			q->f++;
			printf("%d ", q->a[q->f]);
			count--;
		}
		q->f++;
		printf("%d", q->a[q->f]);
	}
}