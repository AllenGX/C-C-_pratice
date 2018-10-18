// 二叉树先序遍历.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#define MaxSize 100


//二叉树结构
typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}TreeNode, *qNode;

//栈结构
typedef struct stack {
	TreeNode a[MaxSize];
	int top;
}Stack,*qStack;
TreeNode Pop(qStack *q);
void creaTree(qNode *q, int X);
void Push(qStack *q, TreeNode X);
int isEmpty(qStack q);


int main()
{
	//建树
	qNode tr = (TreeNode*)malloc(sizeof(TreeNode));
	tr->data = 1;
	tr->left = NULL;
	tr->right = NULL;
	creaTree(&tr, 1);	//建树
	qNode td;		//td用来断链
	//建栈
	qStack q = (Stack *)malloc(sizeof(Stack));
	q->top = -1;
	//遍历

	
	int count = 7;		//节点个数
	while(count){
		while(tr->left!= NULL) {	//该节点左子树不为空将其入栈
			td = tr->left;
			tr->left = NULL;	//断链
			Push(&q, *tr);
			count--;
			tr = td;	//指向其左子树
		}
				
		if (tr->right != NULL) {	//该节点左子树不为空将其入栈
			td = tr->right;
			tr->right = NULL;	//断链
			Push(&q, *tr);
			count--;
			tr = td;	//指向其左子树
		}
		else {
			printf("%d ", tr->data);	//节点左右都为空则输出
			if (q->top!=-1) {	//栈不为空继续
				tr = &Pop(&q);	//取上一个元素
			}
			else {		//为空结束
				break;
			}
		}
		
	}
	free(q);
	system("pause");
    return 0;
}


void Push(qStack *q, TreeNode X) {
	if ((*q)->top < MaxSize - 1) {
		(*q)->top++;
		(*q)->a[(*q)->top] = X;
	}
}

TreeNode Pop(qStack *q) {
	TreeNode n;
	if ((*q)->top != -1) {
		n = (*q)->a[(*q)->top];
		(*q)->top--;
	}
	return n;
}

int isEmpty(qStack q) {
	int a = 0;
	if (q->top == -1) {
		a = 1;
	}
	return a;
}

void creaTree(qNode *q,int X) {
	qNode left = (TreeNode*)malloc(sizeof(TreeNode));
	left->data = 2 * X;
	left->left = NULL;
	left->right = NULL;
	qNode right = (TreeNode*)malloc(sizeof(TreeNode));
	right->data = 2 * X+1;
	right->left = NULL;
	right->right = NULL;
	(*q)->left = left;
	(*q)->right = right;
	if (X < 2) {
		creaTree(&(*q)->left,2*X);
		creaTree(&(*q)->right, 2 * X+1);
	}
}

