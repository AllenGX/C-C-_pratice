// 判断栈是否正确.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Stack {
	ElemType *data;
	int top;
}NodeStack,*qStack;

void isStack(int **a, int row, int col,int count);
int CreateStack(qStack *q, int number);
int Add(qStack *q, ElemType X, int number);
int isEmpty(qStack q);
ElemType Delet(qStack *q);
int isFull(qStack q, int number);

int main()
{	
	int X, Y, Z;
	scanf_s("%d %d %d", &X, &Y, &Z);
	int **a = (int **)malloc(sizeof(int *)*Z);
	for (int i = 0;i < Z;i++) {
		a[i] = (int *)malloc(sizeof(int)*Y);
	}
	for (int i = 0;i <Z;i++) {
		for (int j = 0;j < Y;j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	isStack(a,Z ,Y,X );
	system("pause");
    return 0;
}

int CreateStack(qStack *q,int number) {
	int states = 0;
	if (*q == NULL) {
		*q = (NodeStack*)malloc(sizeof(NodeStack));
		(*q)->data = (ElemType*)malloc(sizeof(ElemType)*number);
		(*q)->top = -1;
		states = 1;
	}
	return states;
}

int Add(qStack *q, ElemType X,int number) {
	int states = 0;
	if (*q) {
		if (isFull(*q, number)!=1) {
			(*q)->top++;
			(*q)->data[(*q)->top]=X;
			states = 1;
		}
	}
	return states;
}

ElemType Delet(qStack *q) {
	ElemType X = -1;
	if (*q) {
		if (isEmpty(*q)!=1) {
			X = (*q)->data[(*q)->top];
			(*q)->top--;
		}
	}
	return X;
}

int isEmpty(qStack q) {
	int states = 0;
	if (q) {
		if (q->top == -1) {
			states = 1;
		}
	}
	return states;
}

int isFull(qStack q,int number) {
	int states = 0;
	if (q) {
		if (q->top == number - 1) {
			states = 1;
		}
	}
	return states;
}

void isStack(int **a,int row ,int col,int count) {
	
	for (int i = 0;i < row;i++) {
		int Aold=1, Anow=0,number=0;
		qStack q = NULL;
		CreateStack(&q, count);
		for (int j = 0;j < col;j++) {
			Anow = a[i][j];
			if (Anow >= Aold) {
				while (Aold <= Anow) {
					if (Add(&q, Aold, count) != 1) {
						break;
					}
					Aold++;
				}
				number = Delet(&q);
			}else{
				number = Delet(&q);
			}
			if (number != Anow) {
				printf("NO\n");
				break;
			}
		}
		if (number == Anow) {
			printf("YES\n");
		}
		free(q);
	}
}