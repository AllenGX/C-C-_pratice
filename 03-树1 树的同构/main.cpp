// 03-树1 树的同构.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef char ElemType;
typedef struct Node {
	ElemType data;
	ElemType left;
	ElemType right;
}node;
typedef struct nodes {
	node a[MAXSIZE];
}Nodes,*qNode;


int main()
{

	int count1 = 0;
	scanf_s("%d\n", &count1);
	qNode q = (Nodes *)malloc(sizeof(Nodes));

	for (int i = 0;i < count1;i++) {
		scanf_s("%c %c %c ", &q->a[i].data,2,&q->a[i].left,1,&q->a[i].right,1);
	}

	int count2 = 0;
	qNode p = (Nodes *)malloc(sizeof(Nodes));
	scanf_s("%d\n", &count2);
	for (int i = 0;i < count2;i++) {
		scanf_s("%c %c %c ", &p->a[i].data,1, &p->a[i].left,1, &p->a[i].right,1);
	}
	char leftDA, rightDA;
	int flag = 1;
	if (count1 != count2) {
		flag = 0;
	}
	else if(count1==1){
		if (q->a[0].data != p->a[0].data) {
			flag = 0;
		}
	}
	else {
		int flag2 = 1;
		for (int i = 0;i < count1&&flag == 1;i++) {
			flag2 = 1;
			for (int j = 0;j < count2&&flag == 1 && flag2 == 1;j++) {
				if (p->a[j].data == q->a[i].data) {
					if (p->a[j].left == '-'&&q->a[i].left == '-') {
						if (p->a[j].right == '-'&&q->a[i].right == '-') {
							flag2 = 0;
							continue;
						}
						else if (p->a[j].right == '-'&&q->a[i].right != '-' || p->a[j].right != '-'&&q->a[i].right == '-') {
							flag = 0;
							break;
						}
						else {
							if (p->a[(p->a[j].right) - '0'].data == q->a[(q->a[i].right) - '0'].data) {
								flag2 = 0;
								continue;

							}
							else {
								flag = 0;
								break;
							}
						}
					}
					else if (p->a[j].right == '-'&&q->a[i].left == '-') {
						if (p->a[j].left == '-'&&q->a[i].right == '-') {
							flag2 = 0;
							continue;
						}
						else if (p->a[j].left == '-'&&q->a[i].right != '-' || p->a[j].left != '-'&&q->a[i].right == '-') {
							flag = 0;
							break;
						}
						else {
							if (p->a[(p->a[j].left) - '0'].data == q->a[(q->a[i].right) - '0'].data) {
								flag2 = 0;
								continue;
							}
							else {
								flag = 0;
								break;
							}
						}
					}
					else if (p->a[j].right != '-'&&q->a[i].left != '-'&&p->a[j].left != '-'&&q->a[i].right != '-') {
						if (p->a[(p->a[j].left) - '0'].data == q->a[(q->a[i].right) - '0'].data&&p->a[(p->a[j].right) - '0'].data == q->a[(q->a[i].left) - '0'].data ||
							p->a[(p->a[j].right) - '0'].data == q->a[(q->a[i].right) - '0'].data&&p->a[(p->a[j].left) - '0'].data == q->a[(q->a[i].left) - '0'].data) {
							flag2 = 0;
							continue;
						}
						else
						{
							flag = 0;
							break;
						}
					}
					else if (p->a[j].left == '-'&&q->a[i].right == '-') {
						if (p->a[j].right == '-'&&q->a[i].left == '-') {
							flag2 = 0;
							continue;
						}
						else if (p->a[j].right == '-'&&q->a[i].left != '-' || p->a[j].right != '-'&&q->a[i].left == '-') {
							flag = 0;
							break;
						}
						else {
							if (p->a[(p->a[j].right) - '0'].data == q->a[(q->a[i].left) - '0'].data) {
								flag2 = 0;
								continue;
							}
							else {
								flag = 0;
								break;
							}
						}
					}
					else if (p->a[j].right == '-'&&q->a[i].right == '-') {
						if (p->a[j].left == '-'&&q->a[i].left == '-') {
							flag2 = 0;
							continue;
						}
						else if (p->a[j].left == '-'&&q->a[i].left != '-' || p->a[j].left != '-'&&q->a[i].left == '-') {
							flag = 0;
							break;
						}
						else {
							if (p->a[(p->a[j].left) - '0'].data == q->a[(q->a[i].left) - '0'].data) {
								flag2 = 0;
								continue;
							}
							else {
								flag = 0;
								break;
							}
						}
					}
					else {
						flag = 0;
						break;
					}
				}
			}

		}
	}

	
	if (flag == 0) {
		printf("No");
	}
	else {
		printf("Yes");
	}
	system("pause");
    return 0;
}

