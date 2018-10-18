// 03-树2 List Leaves.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct Node {
	char right;
	char left;
}node;

typedef struct line {
	int b[MAXSIZE];
	int f;
	int r;
}Line,*qLine;

typedef struct nodes{
	node a[MAXSIZE];
}Nodes, *qNode;
//void L(qNode q, int i);
void Push(qLine *p, int X);
int Pop(qLine *p);
int main()
{
	
	int count = 0;
	scanf_s("%d\n", &count);
	
	qNode q = (Nodes *)malloc(sizeof(Nodes));
	for (int i = 0;i < count;i++) {
		scanf_s("%c %c\n",&q->a[i].left, 1, &q->a[i].right, 1);
	}
	int top = 0,n=0;
	for (int i = 0;i < count;i++) {
		for (int j = 0;j < count;j++) {
			if (top == q->a[j].left-'0' || top == q->a[j].right-'0') {
				top = j;
				n = 0;
				break;
			}
			n++;
			
		}
		if (n >= count - 1) {
			break;
		}
	}

	qLine p = (Line *)malloc(sizeof(Line));
	p->f = 0;
	p->r = 0;
	Push(&p,top);
	int l = 0;
	while (top!=-1)
	{
		l++;
		top = Pop(&p);
		if (q->a[top].left != '-') {
			Push(&p, (q->a[top].left - '0'));
		}
		if (q->a[top].right != '-') {
			Push(&p, (q->a[top].right - '0'));
		}
		if (q->a[top].left == '-'&&q->a[top].right == '-') {
			if (l != count) {
				printf("%d ", top);
			}
			else {
				printf("%d", top);
			}
		}
	}



	system("pause");
    return 0;
}


void Push(qLine *p,int X) {
	if (((*p)->r- (*p)->f + 1+ MAXSIZE) % MAXSIZE != 0) {
		(*p)->r++;
		(*p)->b[(*p)->r] = X;
		
	}
}

int Pop(qLine *p) {
	int j = -1;
		if ((*p)->f!=(*p)->r) {
			(*p)->f++;
			j=(*p)->b[(*p)->f];
			
		}
	return j;
}