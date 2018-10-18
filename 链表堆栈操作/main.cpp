// 链表堆栈操作.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdint.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Elempty;
typedef struct Link {
	Elempty data;
	int length;
	struct Link *next;
}LinkStack,*qStack;

bool CreateListStack(qStack &q);
bool DestoryStack(qStack &q);
bool StackEmpty(qStack q);
bool StackLength(qStack q, int &length);
bool Push(qStack &q, Elempty X);
bool Pop(qStack &q, Elempty &X);
bool DispStack(qStack q);
int main()
{	
	qStack q = NULL;

	if (CreateListStack(q)) {
		printf("创建一个栈了\n");
	}
	if (StackEmpty(q)) {
		printf("还是空的\n");
	}
	int length = 0;
	if (StackLength(q, length)) {
		printf("长度为%d\n"+length);
	}
	int x1, x2, x3, x4, x5;
	Push(q, 1);	printf("进去第一个\n");
	Pop(q, x1);printf("销毁一个值为%d\n",x1);
	Push(q,2);	printf("进去第二个\n");
	Push(q, 3);	printf("进去第三个\n");
	Pop(q, x2);printf("销毁一个值为%d\n", x2);
	Pop(q, x3);printf("销毁一个值为%d\n", x3);
	Push(q, 4);	printf("进去第四个\n");
	Push(q, 5);	printf("进去第五个\n");
	Pop(q, x4);printf("销毁一个值为%d\n", x4);
	Pop(q, x5);printf("销毁一个值为%d\n", x5);
	printf("———————————————\n");
	DispStack(q);

	if (DestoryStack(q)) {
		printf("销毁了哦\n");
	}

	system("pause");
    return 0;
}

bool CreateListStack(qStack &q) {
	bool states = false;
	if (q==NULL) {
		q = (LinkStack*)malloc(sizeof(LinkStack));
		q->length = 0;
		q->next = NULL;
		states = true;
	}
	return states;
}

bool DestoryStack(qStack &q) {
	bool states = false;
	if (q) {
		free(q);
		states = true;
	}
	return states;
}

bool StackEmpty(qStack q) {
	bool states = false;
	if (q) {
		if (q->length == 0) {
			states = true;
		}
	}
	return states;
}

bool StackLength(qStack q,int &length) {
	bool states = false;
	if (q) {
		length = q->length;
	}
	return states;
}

bool Push(qStack &q, Elempty X) {
	bool states = false;
	if (q) {
		qStack s = (LinkStack*)malloc(sizeof(LinkStack));
		s->data = X;
		s->next = q->next;
		q->next = s;
		q->length++;
		states = true;
	}
	return states;
}

bool Pop(qStack &q, Elempty &X) {
	bool states = false;
	if (q) {
		if (q->length == 0) {
			printf("链栈已经为空了\n");
		}
		else {
			
			qStack s = q->next;
			X = s->data;
			q->next = s->next;
			free(s);
			q->length--;
			states = true;
		}
	}
	return states;
}

bool DispStack(qStack q) {
	bool states = false;
	if (q) {
		qStack p = q->next;
		while (p != NULL) {
			printf("%d\n", p->data);
			p = p->next;
		}
	}
	return states;
}

