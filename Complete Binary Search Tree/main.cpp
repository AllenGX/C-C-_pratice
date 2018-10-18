// Complete Binary Search Tree.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 300
typedef struct node *Node;
typedef Node AVLtree;
typedef struct node {
	int data;
	int left, right;
}nodes;

typedef struct line {
	struct node a[MAXSIZE];
	int f,r;
}*Line;

typedef struct ine {
	int a[MAXSIZE];
	int f, r;
}*qLine;
void change(Line *li, qLine *l,int N);
int create(int left, int right);
int Kuai(int *a, int start, int end);
void swap(int *a, int i, int j);
void Sort(int *a, int start, int end);
void Push(Line *li, nodes n);
nodes Pop(Line *li);
void Pushli(qLine *li, int n);
int Popli(qLine *li);
int main()
{
	
	Line li = (Line)malloc(sizeof(struct line));
	li->r = 0;
	li->f = 0;
	int n = 0,k=0;
	scanf_s("%d", &n);
	
	nodes m;
	m.left = 0;
	m.right = n - 1;
	m.data = create(m.left, m.right);
	Push(&li, m);

	qLine l = (qLine)malloc(sizeof(ine));
	l->f = 0;
	l->r = 0;

	int *a = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &k);
		a[i] = k;
	}
	Sort(a, 0, n-1);
	change(&li, &l,n);
	for (int i = 0; i < n-1; i++) {
	
		printf("%d ", a[Popli(&l)]);
	}
	printf("%d", a[Popli(&l)]);
	system("pause");
	return 0;
}


//构建完全二叉树规则返回根节点
int create(int left,int right) {
	int temp = 0;
	int height = 0;
	int N =right-left+1;
	while (N > 1) {
		N = N / 2;
		height++;
	}
	int nodes = 1;
	for (int i = 0; i < height-1; i++) {
		nodes = nodes * 2;
	}
	int L = 0;
	temp = (right - left + 1) - 2*nodes + 1;
	temp = (temp > nodes) ? nodes : temp;
	L = nodes - 1 + temp+left;
	return L;
}


//中序转换
void change(Line *li,qLine *l,int N) {
	int i = 0;
	nodes n = Pop(li);
	Pushli(l, n.data);
	i++;
	while (i<N)
	{
		nodes m;
		if (n.left <= n.data) {
			m.left = n.left;
			m.right = n.data - 1;
			m.data = create(m.left, m.right);
			Push(li, m);
			Pushli(l, m.data);
			i++;
		}
		if (n.data <= n.right) {
			m.left = n.data + 1;
			m.right = n.right;
			m.data = create(m.left, m.right);
			Push(li, m);
			Pushli(l, m.data);
			i++;
		}
		n = Pop(li);
	}
}



//快速排序
int Kuai(int *a,int start,int end) {
	int position = a[start];
	while (start<end)
	{
		while (a[end] >= position&&end > start)
		{
			end--;
		}
		swap(a, start, end);
		while (a[start]<=position&&end>start)
		{
			start++;
		}
		swap(a, start, end);
	}
	
	return start;
}
void Sort(int *a, int start, int end) {
	int position;
	if (end > start) {
		position = Kuai(a, start, end);
		Sort(a, start, position - 1);
		Sort(a, position + 1, end);
	}
}

void swap(int *a, int i,int j) {
	int temp = a[i];
	a[i]=a[j];
	a[j] = temp;
}

void Push(Line *li, nodes n) {
	if (((*li)->r + 1 - (*li)->f + MAXSIZE) % MAXSIZE != 0) {
		(*li)->r++;
		(*li)->a[(*li)->r] = n;
	}
}

nodes Pop(Line *li) {
	nodes m;
	if (((*li)->r != (*li)->f)){
		(*li)->f++;
		m = (*li)->a[(*li)->f];
	}
	return m;
}

void Pushli(qLine *li, int n) {
	if (((*li)->r + 1 - (*li)->f + MAXSIZE) % MAXSIZE != 0) {
		(*li)->r++;
		(*li)->a[(*li)->r] = n;
	}
}

int Popli(qLine *li) {
	int m;
	if (((*li)->r != (*li)->f)) {
		(*li)->f++;
		m = (*li)->a[(*li)->f];
	}
	return m;
}