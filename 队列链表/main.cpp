// 队列链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef int ElemTye;
typedef struct Node {
	ElemTye data;
	struct Node *next;
}*qNode,LineNode;

typedef struct Line {
	LineNode *f;
	LineNode *r;
}*qLineNode;


bool CreateLine(qLineNode &q);
bool Delet(qLineNode &q, ElemTye &X);
bool isEmptyLine(qLineNode q);
bool Add(qLineNode &q, ElemTye X);
bool Fre(qLineNode &q);
int main()
{
	qLineNode q = NULL;
	if (CreateLine(q)) {
		printf("创建了一个链队\n");
	}
	if (isEmptyLine(q)) {
		printf("现在还是空的\n");
	}
	int x = 0;
	for (int i = 0;i < 10;i++) {
		if (Add(q, i)) {
			printf("往其中加入一个数%d\n", i);
		}

		if (Delet(q, x)) {
			printf("出队一个数%d\n", x);
		}
	}


	if (Fre(q)) {
		printf("删除了\n");
	}
	system("pause");
    return 0;
}

bool CreateLine(qLineNode &q) {
	bool states = false;
	if (q == NULL) {
		q = (struct Line*)malloc(sizeof(struct Line));
		q->f = NULL;
		q->r = NULL;
		states = true;
	}
	return states;
}

bool isEmptyLine(qLineNode q) {
	bool states = false;
	if (q) {
		if (q->f == NULL) {
			states = true;
		}
	}
	return states;
}

bool Add(qLineNode &q,ElemTye X){
	bool states = false;
	if (q) {
		qNode p = (LineNode *)malloc(sizeof(LineNode));
		p->data = X;
		p->next = NULL;
		if (isEmptyLine(q)) {
			q->f = p;
			q->r = p;
		}
		else {
			q->r->next = p;
			q->r = p;
		}
		states = true;
	}
	return states;
}

bool Delet(qLineNode &q, ElemTye &X) {
	bool states = false;
	if (q) {
		if (!isEmptyLine(q)) {
			qNode p = q->f;
			q->f = q->f->next;
			X = p->data;
			free(p);
			states = true;
		}
	}
	return states;
}

bool Fre(qLineNode &q) {
	bool states = false;
	if (q) {
		free(q);
		states=true;
	}
	return states;
}