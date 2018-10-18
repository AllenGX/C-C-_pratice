// 04-树5 Root of AVL Tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node *Node;
typedef Node AVLtree;
typedef struct node {
	int data;
	Node left, right;
}nodes;

typedef struct stack {
	Node nodes[30];
	int top;
}*STACK;

Node Get(STACK *q);
int Max(int i, int j);
void Push(STACK *q, Node n);
int getHeight(Node q);
Node Pop(STACK *q);
AVLtree LeftLeft(Node A);
AVLtree LeftRight(Node A);
AVLtree RightLeft(Node A);
AVLtree RightRight(Node A);
AVLtree Insert(AVLtree tr, STACK *q, int X);
int main()
{
	STACK q = (stack*)malloc(sizeof(stack));
	AVLtree tr = NULL;
	q->top = -1;
	int n,m;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &m);
		tr = Insert(tr, &q, m);
	}
	printf("%d", tr->data);
	system("pause");
    return 0;
}

//获取节点高度
int getHeight(Node q) {
	if (q != NULL) {
		return Max(getHeight(q->left), getHeight(q->right)) + 1;
	}
	else {
		return 0;
	}
}

int Max(int i, int j) {
	return (i > j) ? i : j;
}

void Push(STACK *q, Node n) {
	if ((*q)->top < MAXSIZE - 1) {
		(*q)->top++;
		(*q)->nodes[(*q)->top] = n;
	}
}

Node Get(STACK *q) {
	Node a = NULL;
	if ((*q)->top > -1) {
		a = (*q)->nodes[(*q)->top];
	}
	return a;
}

Node Pop(STACK *q) {
	Node a = NULL;
	if ((*q)->top > -1) {
		a = (*q)->nodes[(*q)->top];
		(*q)->top--;
	}
	return a;
}

//左左旋
AVLtree LeftLeft(Node A) {
	Node B;
	B = A->left;
	A->left = B->right;
	B->right = A;
	return B;
}

//左右旋
AVLtree LeftRight(Node A) {
	Node B, C;
	B = A->left;
	C = B->right;
	B->right = C->left;
	A->left = C->right;
	C->left = B;
	C->right = A;
	return C;
}


//右左旋
AVLtree RightLeft(Node A) {
	Node B, C;
	B = A->right;
	C = B->left;
	B->left = C->right;
	A->right = C->left;
	C->left = A;
	C->right = B;
	return C;
}

//右右旋
AVLtree RightRight(Node A) {
	Node B;
	B = A->right;
	A->right = B->left;
	B->left = A;
	return B;
}

//插入
AVLtree Insert(AVLtree tr, STACK *q,int X) {
	(*q)->top = -1;	//清空栈
	if (tr == NULL) {		//初始为空
		Node n = (Node)malloc(sizeof(struct node));
		n->data = X;
		n->left = NULL;
		n->right = NULL;
		tr = n;
	}
	else {
		Node p = tr,pre=NULL,A,B=NULL,C,t;		//	C存放刚插入节点		pre存放C的父节点	A存放受影响节点
		int D=-1;
		while (1)
		{
			if (p != NULL) {
				if (p->data < X) {
					Push(q,p);		//依次入栈
					pre = p;
					p = p->right;
				}
				else if (p->data > X) {
					Push(q, p);		//依次入栈
					pre = p;
					p = p->left;
				}
			}
			else {
				if (pre->data>X) {	//插入
					Node n = (Node)malloc(sizeof(struct node));
					C = n;
					n->data = X;
					n->left = NULL;
					n->right = NULL;
					pre->left = n;
					break;
				}
				if (pre->data<X) {	//插入
					Node n = (Node)malloc(sizeof(struct node));
					C = n;
					n->data = X;
					n->left = NULL;
					n->right = NULL;
					pre->right = n;
					break;
				}
			}
		}	//插入完成开始摆
		while (Get(q) != NULL)	//得到栈顶元素
		{
			A = Pop(q);
			if (getHeight(A->left) - getHeight(A->right) == 2) {
				if (A->left->data>X)
				{
					if (Get(q) != NULL) {		//拼接
						B = Get(q);
						if (B->left == A) {
							D = 1;		//表示左
						}
						else {
							D = 0;		//表示右
						}
					}
					t = LeftLeft(A);
					if (D != -1) {
						if (D == 1) {
							B->left = t;
						}
						else {
							B->right = t;
						}
					}
					else {
						tr = t;	//旋转之后根节点
					}

				}
				else {
					if (Get(q) != NULL) {		//拼接
						B = Get(q);
						if (B->left == A) {
							D = 1;		//表示左
						}
						else {
							D = 0;		//表示右
						}
					}
					t = LeftRight(A);
					if (D != -1) {
						if (D == 1) {
							B->left = t;
						}
						else {
							B->right = t;
						}
					}
					else {
						tr = t;	//旋转之后根节点
					}
				}
			}
			if (getHeight(A->right) - getHeight(A->left) == 2) {	//右边大
				if (A->right->data>X)
				{
					if (Get(q) != NULL) {		//拼接
						B = Get(q);
						if (B->left == A) {
							D = 1;		//表示左
						}
						else {
							D = 0;		//表示右
						}
					}
					t = RightLeft(A);
					if (D != -1) {
						if (D == 1) {
							B->left = t;
						}
						else {
							B->right = t;
						}
					}
					else {
						tr = t;	//旋转之后根节点
					}

				}
				else {
					if (Get(q) != NULL) {		//拼接
						B = Get(q);
						if (B->left == A) {
							D = 1;		//表示左
						}
						else {
							D = 0;		//表示右
						}
					}
					t = RightRight(A);
					if (D != -1) {
						if (D == 1) {
							B->left = t;
						}
						else {
							B->right = t;
						}
					}
					else {
						tr = t;	//旋转之后根节点
					}
				}
			}
		}
	}
	return tr;
}