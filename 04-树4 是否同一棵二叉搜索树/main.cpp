// 04-树4 是否同一棵二叉搜索树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct node *Node;
typedef Node treeNode;
typedef struct node {
	int data;
	treeNode left;
	treeNode right;
};
treeNode Insert(treeNode T, int X);
int PK(treeNode q, treeNode p);
int main()
{
	int n = 0,s=0,x=0;
	treeNode p = NULL, q = NULL;
	scanf_s("%d", &n);
	while (n!=0)
	{
		scanf_s("%d", &s);
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &x);
			p = Insert(p, x);
		}
		for (int i = 0; i < s; i++) {
			for (int i = 0; i < n; i++) {
				scanf_s("%d", &x);
				q = Insert(q, x);
			}
			if (PK(q, p) == 1) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
			free(q);
			q = NULL;
		}
		free(p);
		p= NULL;
		scanf_s("%d", &n);
	}


	system("pause");
    return 0;
}

treeNode Insert(treeNode T, int X) {
	if (T == NULL) {
		Node s = (Node)malloc(sizeof(struct node));
		s->data = X;
		s->left = NULL;
		s->right = NULL;
		T = s;
	}
	else {
		Node q=T;
		while (1)
		{
			if (X > q->data) {
				if (q->right != 0) {
					q = q->right;
				}
				else {
					Node s = (Node)malloc(sizeof(struct node));
					s->data = X;
					s->left = NULL;
					s->right = NULL;
					q->right = s;
					break;
				}
			}
			else if(X<q->data){
				if (q->left != 0) {
					q = q->left;
				}
				else {
					Node s = (Node)malloc(sizeof(struct node));
					s->data = X;
					s->left = NULL;
					s->right = NULL;
					q->left = s;
					break;
				}
			}
		}
	}
	return T;
}

int PK(treeNode q, treeNode p) {
	if (q == NULL && p == NULL) {
		return 1;
	}
	else if (q == NULL || p == NULL) {
		return 0;
	}
	if (q->data == p->data) {
		return PK(q->left, p->left) && PK(q->right, p->right);
	}
	else
	{
		return 0;
	}
}
