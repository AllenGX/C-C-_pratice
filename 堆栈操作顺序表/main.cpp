// 堆栈操作顺序表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef int ElemType;
typedef struct stack {
	ElemType data[MaxSize];
	int top;
}SqStack,*qStack;


bool initStack(qStack &q);	//新建栈
bool DestoryStack(qStack &q);	//销毁栈
bool StackEmpty(qStack q);	//判断是否为空
bool Push(qStack &q, ElemType X);	//进栈
bool Pop(qStack &q, ElemType &X);	//出栈
bool GetTop(qStack q, ElemType &X);	//取栈顶元素
int main()
{
	qStack q = NULL;
	if (initStack(q)) {
		printf("top为:%d\n", q->top);
	}
	if (StackEmpty(q)) {
		printf("栈是空的\n");
	}
	Push(q, 1);
	Push(q, 2);
	Push(q, 3);
	printf("top为:%d\n", q->top);
	int x;
	GetTop(q, x);
	printf("栈顶元素为:%d\n",x);

	int a[MaxSize];
	for (int i = 0;q->top!=-1;i++) {
		Pop(q, a[i]);
		printf("第%d个数为:%d		",i,a[i]);
		printf("top值为:%d\n", q->top);
	}
	if (DestoryStack(q)) {
		printf("已经销毁了\n");
		if(!StackEmpty(q)){
			printf("已经空了\n");
		}
	}

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
bool Pop(qStack &q, ElemType &X) {
	bool states = false;
	if (q) {
		if (q->top == -1) {
			printf("栈已经空了！！\n");
		}
		else {
			X = q->data[q->top];
			q->top--;
			states = true;
		}
	}
	return states;
}


//取栈顶元素
bool GetTop(qStack q, ElemType &X) {
	bool states = false;
	if (q) {
		if (q->top == -1) {
			printf("取不出来了，栈已经空了\n");
		}
		else {
			X = q->data[q->top];
			states = true;
		}
	}
	return states;
}
