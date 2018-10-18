// 双栈顺序表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSize 1000

typedef int ElemType;
typedef struct Stack {
	ElemType data[MAXSize];
	int top1;
	int top2;
}DouStack,*qStack;
bool initStack(qStack &q);
bool DestoryStack(qStack &q);
bool StackEmpty(qStack q, int flag);
bool Push(qStack &q, int flag, ElemType X);
bool Pop(qStack &q, int flag, ElemType &X);
bool GetTop(qStack q, int flag, ElemType &X);

int main()
{
	system("pause");
    return 0;
}

//新建
bool initStack(qStack &q) {
	bool states = false;
	if (q==NULL) {
		q = (DouStack*)malloc(sizeof(DouStack));
		q->top1 = -1;
		q->top2 = MAXSize;
		states = true;
	}
	return states;
}

//销毁
bool DestoryStack(qStack &q) {
	bool states = false;
	if (q) {
		free(q);
		states = true;
	}
	return states;
}

//判断栈空
bool StackEmpty(qStack q,int flag) {
	bool states = false;
	if (q) {
		if (flag == 1) {
			if (q->top1 == -1) {
				states = true;
			}
		}
		else {
			if (q->top2 == MAXSize) {
				states = true;
			}
		}
	}
	return states;
}

//进栈
bool Push(qStack &q,int flag,ElemType X) {
	bool states=false;
	if (q) {
		if ((q->top2 - q->top1) == 1) {
			printf("栈已满\n");
		}
		else {
			if (flag == 1) {
				q->top1++;
				q->data[q->top1] = X;
			}
			else {
				q->top2--;
				q->data[q->top2] = X;
			}
			states = true;
		}
	}
	return states;
}

//出栈
bool Pop(qStack &q, int flag, ElemType &X) {
	bool states=false;
	if (q) {
		if (flag == 1) {
			if (q->top1 == -1) {
				printf("栈已空了\n");
			}
			else {
				X = q->data[q->top1];
				q->top1--;
				states = true;
			}
		}
		else {
			if (q->top2 == MAXSize) {
				printf("栈已空了\n");
			}
			else {
				X = q->data[q->top2];
				q->top2++;
				states = true;
			}
		}
	}
	return states;
}

//取栈顶元素
bool GetTop(qStack q, int flag, ElemType &X) {
	bool states=false;
	if (q) {
		if (flag == 1) {
			if (q->top1 == -1) {
				printf("栈已空了\n");
			}
			else {
				X = q->data[q->top1];
				states = true;
			}
		}
		else {
			if (q->top2 == MAXSize) {
				printf("栈已空了\n");
			}
			else {
				X = q->data[q->top2];
				states = true;
			}
		}
	}
	return states;
}
