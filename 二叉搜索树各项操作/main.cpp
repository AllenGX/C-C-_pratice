// 二叉搜索树各项操作.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};



BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf_s("%d", &N);
	for (i = 0; i<N; i++) {
		scanf_s("%d", &X);
		BST = Insert(BST, X);
	}
	printf("Preorder:");  printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf_s("%d", &N);
	for (i = 0; i<N; i++) {
		scanf_s("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf_s("%d", &N);
	for (i = 0; i<N; i++) {
		scanf_s("%d", &X);
		BST = Delete(BST, X);
	}
	Position p = BST;
	printf("Inorder:");  printf("\n");

	return 0;
}

BinTree Insert(BinTree BST, ElementType X) {
	Position p = BST;
	if (BST != NULL) {
		while(true){
			if (p->Data > X) {
				if (p->Left != NULL) {
					p = p->Left;
				}
				else {
					Position node = (struct TNode*)malloc(sizeof(struct TNode));
					node->Data = X;
					node->Left = NULL;
					node->Right = NULL;
					p->Left = node;
					break;
				}
			}
			else if(p->Data<X){
				if (p->Right != NULL) {
					p = p->Right;
				}
				else {
					Position node = (struct TNode*)malloc(sizeof(struct TNode));
					node->Data = X;
					node->Left = NULL;
					node->Right = NULL;
					p->Right = node;
					break;
				}
			}
		}
	}
	else {
		Position node = (struct TNode *)malloc(sizeof(struct TNode));
		node->Data = X;
		node->Left = NULL;
		node->Right = NULL;
		BST = node;
	}
	return BST;
}


BinTree Delete(BinTree BST, ElementType X) {
	Position q,p1,p=NULL;
	if (BST != NULL) {
		q = BST;
		while (q != NULL) {		//找到要删除的节点
			if (q != NULL) {
				 if (q->Data > X) {
					p = q;
					q = q->Left;
				}
				else if(q->Data < X){
					p = q;
					q = q->Right;
				}
				else {
					break;
				}
			}
		}
		//找到了		放在q中		p为前一个节点
		if (q != NULL) {
			if (q->Left != NULL && q->Right != NULL) {		//要删除节点左右子树都不为空												
															//得到其左子树最大值
				p1 = FindMax(q->Left);
				q->Data = p1->Data;
				q = p1;
				p = BST->Left;
				while (p->Right!=p1)
				{
					p = p->Right;
				}
			}
			if (p != NULL) {
				if (q->Left != NULL) {		//左子树不为空
					if (p->Left == q) {
						p->Left = q->Left;
					}
					else {
						p->Right = q->Left;
					}
					free(q);
					q = NULL;
				}
				else if (q->Right != NULL) {	//右子树不为空
					if (p->Left == q) {
						p->Left = q->Right;
					}
					else {
						p->Right = q->Right;
					}
					free(q);
					q = NULL;
				}
				else {		//左右子树都为空
					if (p->Left == q) {
						p->Left = NULL;
					}
					else {
						p->Right = NULL;
					}
					free(q);
					q = NULL;
				}
			}
			else {
				if (q->Left != NULL) {
					BST = BST->Left;
					free(q);
					q = NULL;
				}
				else if (q->Right != NULL) {
					
					BST = BST->Right;
					free(q);
					q = NULL;
				}
				else {
					free(q);
					q = NULL;
					BST = NULL;
				}
			}
		}
		else {
			printf("Not Found\n");
		}
	}
	else {
		printf("Not Found\n");
	}
	return BST;
}

Position Find(BinTree BST, ElementType X) {
	Position p=NULL;
	if (BST != NULL) {
		p = BST;
		while (p!=NULL) {
			if (p->Data > X) {
				p = p->Left;
			}
			else if(p->Data<X){
				p = p->Right;
			}
			else {
				break;
			}
		}
	}
	return p;
}
Position FindMin(BinTree BST) {
	Position p = NULL;
	if (BST != NULL) {
		p = BST;
		while (p->Left!=NULL)
		{
			p = p->Left;
		}
	}
	return p;
}
Position FindMax(BinTree BST) {
	Position p = NULL;
	if (BST != NULL) {
		p = BST;
		while (p->Right!=NULL)
		{
			p = p->Right;
		}
	}
	return p;
}