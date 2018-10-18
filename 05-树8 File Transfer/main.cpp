// 05-树8 File Transfer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100000
typedef int node;

typedef struct Node {
	node *a;
}Nodes, *qNode;

typedef qNode QNode;

//建树
void Create(QNode *q, int length) {
	*q = (Nodes*)malloc(sizeof(Nodes));
	(*q)->a = (node*)malloc(sizeof(node)*(length + 1));
	for (int i = 0; i < length + 1; i++) {
		(*q)->a[i] = -1;
	}
}

//寻找集合
int Find(QNode q, int A) {
	while (q->a[A]>-1)
	{
		A = q->a[A];
	}
	return A;
}

//判断是否在一个集合
void Look(QNode q, int A, int B) {
	if (Find(q, A) == Find(q, B)) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
}

//建立连接
void Link(QNode *q, int A, int B) {
	A = Find(*q, A);
	B = Find(*q, B);
	int temp = 0;
	if (A != B) {
		if ((*q)->a[A] < (*q)->a[B]) {
			temp = (*q)->a[A] + (*q)->a[B];
			(*q)->a[B] = A;
			(*q)->a[A] = temp;
		}
		else
		{
			temp = (*q)->a[B] + (*q)->a[A];
			(*q)->a[A] = B;
			(*q)->a[B] = temp;
		}
	}
}

//查看是否全连通
void LookAll(QNode q, int length) {
	int flag = 0;
	for (int i = 1; i < length + 1; i++) {
		if (q->a[i] < 0) {
			flag++;
		}
	}
	if (flag == 1) {
		printf("The network is connected.");
	}
	else {
		printf("There are %d components.", flag);
	}
}

int main()
{
	int n = 0;
	QNode q = NULL;
	scanf_s("%d\n", &n);
	Create(&q, n);
	int N = 1, A, B;
	char info;

	do {
		scanf_s("%c", &info);
		switch (info)
		{
		case 'C':
			scanf_s("%d %d\n", &A, &B);
			Look(q, A, B);
			break;
		case 'I':
			scanf_s("%d %d\n", &A, &B);
			Link(&q, A, B);
			break;
		case 'S':
			LookAll(q, n);
			N = 0;
			break;
		default:
			break;
		}
	} while (N == 1);

	system("pause");
	return 0;
}
