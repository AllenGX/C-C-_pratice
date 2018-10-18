// 队列顺序表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIEZ 10


typedef int Elemtype;
typedef struct Link {
	Elemtype data[MAXSIEZ];
	int f;
	int r;
}Line,*LinkLine;
bool IsEmpty(LinkLine L);
bool Add(LinkLine &L, Elemtype X);
bool CreatLine(LinkLine &L);
bool Delet(LinkLine &L, Elemtype &X);
bool IsFull(LinkLine L);

int main()
{
	LinkLine line = NULL;
	if (CreatLine(line)) {
		printf("创建了一个队列\n");
	}
	if (IsEmpty(line)) {
		printf("是空的队列\n");
	}
	for (int i = 0;i <15;i++) {
		if (Add(line, i)) {
			printf("把%d放进去\n",i);
		}
		int X;
		if (Delet(line, X)) {

			printf("把%d取出来了\n", X);

		}
	}

	system("pause");
    return 0;
}

bool CreatLine(LinkLine &L) {
	bool states = false;
	if (L == NULL) {
		L = (Line*)malloc(sizeof(Line));
		L->f = L->r = 0;
		states = true;
	}
	return states;
}

bool IsFull(LinkLine L) {
	bool states = false;
	if (L) {
		if ((L->r + 1) % MAXSIEZ == L->f) {
			states = true;
		}
	}
	return states;
}

bool Add(LinkLine &L, Elemtype X) {
	bool states = false;
	if (L) {
		if (!IsFull(L)) {
			L->r=(L->r+1)%MAXSIEZ;
			L->data[L->r] = X;
			states = true;
		}
	}
	return states;
}

bool IsEmpty(LinkLine L) {
	bool states = false;
	if (L) {
		if (L->r == L->f) {
			states = true;
		}
	}
	return states;
}

bool Delet(LinkLine &L,Elemtype &X) {
	bool states = false;
	if (L) {
		if (!IsEmpty(L)) {
			L->f = (L->f +1 + MAXSIEZ) % MAXSIEZ;
			X = L->data[L->f];
			states = true;
		}
	}
	return states;
}