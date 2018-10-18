// 双栈队列实现.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef int ElemType;
typedef struct stack {
	ElemType data[MaxSize];
	int top;
}SqStack, *qStack;

bool InversionStack(qStack &q1, qStack &q2, int number);	//倒置操作
ElemType PopLine(qStack &q1, qStack &q2);	//出队
bool PushLine(qStack &q1, qStack &q2, ElemType X);	//入队
bool initStack(qStack &q);	//新建栈
bool DestoryStack(qStack &q);	//销毁栈
bool StackEmpty(qStack q);	//判断是否为空
bool Push(qStack &q, ElemType X);	//进栈
ElemType Pop(qStack &q);	//出栈


int main()
{
	int a[10];
	qStack q1 = NULL;
	qStack q2 = NULL;
	initStack(q1);
	initStack(q2);
	for (int i = 0;i < 10;i++) {
		if (PushLine(q1, q2, i+1)) { printf("第%d个进队的数为:	%d\n",i+1,i+1); }
	}
	printf("------------------------------\n");

	for (int i = 0;i < 10;i++) {
		a[i]= PopLine(q1, q2 );
		printf("第%d个出队的数为:	%d\n",i+1,a[i] );
	}

	DestoryStack(q1);
	DestoryStack(q2);

	system("pause");
	return 0;
}


//新建栈
bool initStack(qStack &q) {
	bool states = false;
	if (q == NULL) {
		q = (SqStack*)malloc(sizeof(SqStack));
		q->top = -1;
	}

	if (q) {
		states = true;
	}
	return states;
}

//销毁栈
bool DestoryStack(qStack &q) {
	bool states = false;
	if (q) {
		free(q);
		states = true;
	}
	return states;
}

//判断是否为空
bool StackEmpty(qStack q) {
	bool states = false;
	if (q) {
		if (q->top == -1) {
			states = true;
		}
	}
	return states;
}

//进栈
bool Push(qStack &q, ElemType X) {
	bool states = false;
	if (q) {
		if (q->top == (MaxSize - 1)) {
			printf("栈已经满了！！\n");
		}
		else {
			q->top++;
			q->data[q->top] = X;
			states = true;
		}
	}
	return states;
}


//出栈
ElemType Pop(qStack &q) {
	ElemType X=0;
	if (q) {
		if (q->top == -1) {
			printf("栈已经空了！！\n");
		}
		else {
			X = q->data[q->top];
			q->top--;
		}
	}
	return X;
}



//倒置栈							-1 一个都不留	0 剩下一个
bool InversionStack(qStack &q1, qStack &q2, int number) {
	bool states = false;
	if (q1) {
		if (!StackEmpty(q1)) {
			while (q1->top != number) {
				states=Push(q2, Pop(q1));
				if (!states) {
					break;
				}
			}
		}
	}
	return states;
}


//进队
bool PushLine(qStack &q1, qStack &q2,ElemType X) {
	bool states = false;
	if (StackEmpty(q1)) {
		if (StackEmpty(q2)) {
			states=Push(q1, X);
		}
		else {
			if(InversionStack(q2, q1, -1)){
				states = Push(q1, X);
			}	
		}
	}
	else {
		states = Push(q1, X);
	}
	return states;
}


//出队
ElemType PopLine(qStack &q1, qStack &q2) {
	ElemType X=0;
	if (StackEmpty(q1)) {
		X = Pop(q2);
	}
	else {
		if(InversionStack(q1, q2, 0)){
			X = Pop(q1);
		}	
	}
	return X;
}
