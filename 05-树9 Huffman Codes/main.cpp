// 05-树9 Huffman Codes.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define Maxsize 63
typedef struct node {
	int n;
	char s;
	struct node * left;
	struct node * right;
}Node;

typedef struct nodes {
	Node *A;
}Nodes,*qNodes;

typedef struct tree {
	int N;
	char S;
	struct tree * left;
	struct tree * right;
}Tree,*qTree;
//构造堆
void Create(qNodes *a,int length) {
	*a = (Nodes *)malloc(sizeof(Nodes));
	(*a)->A = (Node *)malloc(sizeof(Node)*(length+1));
	(*a)->A[0].n = -1;
	(*a)->A[0].s = '*';
	(*a)->A[0].left = NULL;
	(*a)->A[0].right = NULL;
}

//小顶堆排序
void Sort(qNodes *a,int length) {
	for (int i = length; i >0; i--) {
		int j = i;
		while (j!=1)
		{
			if ((*a)->A[j].n < (*a)->A[j / 2].n) {
				int temp = (*a)->A[j].n;
				char tep = (*a)->A[j].s;
				(*a)->A[j].n = (*a)->A[j / 2].n;
				(*a)->A[j].s = (*a)->A[j / 2].s;
				(*a)->A[j / 2].n = temp;
				(*a)->A[j / 2].s = tep;
			}
			j /= 2;
		}
	}
}

//插入堆
void Insert(qNodes *q, Node *N,int length) {
	length++;
	//(*q)->A[length].n = N->n;
	//(*q)->A[length].s = N->s;
	while (length>1)
	{
		if (N->n < (*q)->A[length / 2].n) {
			(*q)->A[length].n = (*q)->A[length / 2].n;
			(*q)->A[length].s = (*q)->A[length / 2].s;
			(*q)->A[length].left = (*q)->A[length / 2].left;
			(*q)->A[length].right = (*q)->A[length / 2].right;
		}
		else {
			break;
		}
		length /= 2;
	}
	(*q)->A[length].n = N->n;
	(*q)->A[length].s = N->s;
	(*q)->A[length].left = N->left;
	(*q)->A[length].right = N->right;
}

//弹出根节点
Node * Pop(qNodes *q,int length) {
	int len = length;
	length--;
	Node *p = (Node *)malloc(sizeof(Node));
	p->n = (*q)->A[1].n;
	p->s = (*q)->A[1].s;
	p->right = (*q)->A[1].right;
	p->left = (*q)->A[1].left;
	int i = 1;
	//(*q)->A[1].n = (*q)->A[length].n;
	//(*q)->A[1].s = (*q)->A[length].s;
	while (i*2<=length)
	{	//有右子树存在且右子树更小
		if (2*i!=length&&(*q)->A[2*i].n> (*q)->A[2*i + 1].n) {
			i = 2 * i + 1;
		}
		else {
			i *= 2;
		}
		if ((*q)->A[i].n < (*q)->A[len].n) {	//更小的往上移动
			(*q)->A[i / 2].n = (*q)->A[i].n;
			(*q)->A[i / 2].s = (*q)->A[i].s;
			(*q)->A[i / 2].right = (*q)->A[i].right;
			(*q)->A[i / 2].left = (*q)->A[i].left;
		}
		else {		
			i /= 2;
			break;
		}
	}//尾节点放入适合位置
	(*q)->A[i].n = (*q)->A[len].n;
	(*q)->A[i].s = (*q)->A[len].s;
	(*q)->A[i].left = (*q)->A[len].left;
	(*q)->A[i].right = (*q)->A[len].right;
	return p;
}

//构建哈希排序树
Node* CreatTree(qNodes q, int length) {
	Node *N=NULL;
	while (length > 1) {
		Node *t = (Node *)malloc(sizeof(Node));

		Node *L = Pop(&q, length);
		length--;
		Node *R = Pop(&q, length);
		length--;
		
		t->n = L->n + R->n;
		t->left = L;
		t->right = R;
		t->s = '*';

		N = t;	//N保存树根
		Insert(&q, t, length);
		length++;
	}
	return	N;
}

int PanDuan(qTree tr) {
	if (tr->S != '*') {
		if (tr->right == NULL && tr->left == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (tr->S == '*') {
		if (tr->left != NULL && tr->right!= NULL) {
			return PanDuan(tr->right) && PanDuan(tr->left);
		}
		else {
			return 0;
		}
	}
	
}

int QiuHe(qTree tr,int hight) {
	if (tr->S != '*') {
		return tr->N*hight;
	}
	else {
		return QiuHe(tr->left, hight+1) + QiuHe(tr->right, hight+1);
	}
}

int He(Node tr, int hight) {
	if (tr.s != '*') {
		return tr.n*hight;
	}
	else {
		return He(*tr.left, hight + 1) + He(*tr.right, hight + 1);
	}
}


int main()
{
	int N = 0;
	scanf_s("%d\n", &N);
	qNodes a=NULL;
	Create(&a,N);
	int n;
	char s;
	for (int i = 1; i < N; i++) {
		scanf_s("%c ", &s);
		scanf_s("%d ", &n);
		a->A[i].s = s;
		a->A[i].n = n;
		a->A[i].left = NULL;
		a->A[i].right = NULL;
	}
	scanf_s("%c ", &s);
	scanf_s("%d", &n);
	a->A[N].s = s;
	a->A[N].n = n;
	a->A[N].left = NULL;
	a->A[N].right = NULL;
	Sort(&a, N);

	qNodes b= NULL;
	Create(&b, N);
	for (int i = 1; i <= N; i++) {
		b->A[i].s = a->A[i].s;
		b->A[i].n = a->A[i].n;
		b->A[i].left = a->A[i].left;
		b->A[i].right = a->A[i].right;
	}
	//构建哈希排序树
	Node *Z = CreatTree(a, N);

	int pep = 0, length = 0;;
	scanf_s("%d\n", &pep);
	char C1='*', *C2=NULL;
	C2 = (char*)malloc(sizeof(char) * 10);
	for (int k = 0; k < pep; k++) {
		qTree tree = (Tree *)malloc(sizeof(Tree));
		tree->left = NULL;
		tree->right = NULL;
		tree->S = '*';
		tree->N = 0;
		for (int i = 0; i < N; i++) {
			scanf_s("%c ", &C1);
			gets_s(C2, 10);
			qTree pre = tree;
			int j = 0;
			do
			{
				if (C2[j] == '0') {
					if (pre->left == NULL) {
						qTree pp = (Tree *)malloc(sizeof(Tree));
						pp->left = NULL;
						pp->right = NULL;
						pp->S = '*';
						pp->N = 0;
						pre->left = pp;
					}
					pre = pre->left;
				}
				else {
					if (pre->right == NULL) {
						qTree pp = (Tree *)malloc(sizeof(Tree));
						pp->left = NULL;
						pp->right = NULL;
						pp->S = '*';
						pp->N = 0;
						pre->right = pp;
					}
					pre = pre->right;
				}
				j++;
			} while (C2[j] != '\0');
			pre->S = C1;
			for (int m = 1; m <= N; m++) {
				if (b->A[m].s == C1) {
					pre->N = b->A[m].n;
					break;
				}
			}
		}
		int flag = PanDuan(tree);
		int count = 0, count1 = 0;;
		if (flag==1)
		{
			count = QiuHe(tree,0);
			count1 = He(*Z,0);
			if (count == count1) {
				printf("Yes");
			}
			else {
				printf("No");
			}
		}
		else {
			printf("No");
		}
		if (k != pep - 1) {
			printf("\n");
		}
		
		free(tree);
		tree = NULL;
	}
	if (pep <= 0) {
		printf("No");
	}

	system("pause");
    return 0;
}

