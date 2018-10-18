// 06-图3 六度空间.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>

typedef struct v {
	int n;
	struct v* next;
}V,*qV;


typedef struct node {
	int data;
	int C;
}Node;

typedef struct  stack
{
	Node *a;
	int top;
	int end;
}Stack,*qStack;


//建队
void CreateStack(qStack *q,int number) {
	*q = (qStack )malloc(sizeof(Stack));
	(*q)->a = (Node *)malloc(sizeof(Node)*number);
	(*q)->top = 0;
	(*q)->end = 0;
}

//出队
Node Pop(qStack *q) {
	Node s;
	s.C = 0;
	s.data = 0;
	(*q)->top++;
	s.C = (*q)->a[(*q)->top].C;
	s.data = (*q)->a[(*q)->top].data;
	return s;
}

//入队
void Push(qStack *q, Node n) {
	(*q)->end++;
	(*q)->a[(*q)->end] = n;
}

//创建邻接表
qV* Create(qV *q,int number) {
	q = (qV *)malloc(sizeof(qV)*number);
	for (int i = 1; i < number; i++) {
		qV s = (qV)malloc(sizeof(V));
		s->n = i;
		s->next = NULL;
		q[i] = s;
	}
	return q;
}

//插入邻接表
void Insert(qV **q,int a,int b) {
	qV s = (qV)malloc(sizeof(V));
	s->n = b;
	s->next = (*q)[a]->next;
	(*q)[a]->next = s;
}

//遍历六层
void LookAll(qV *q,qStack *stack,int number,int *m,int i) {
	float ss = 0;
	qV s;
	Node N;
	N.C = 0;
	N.data = i;
	m[i] = 1;
	Push(stack, N);
	while ((*stack)->top!= (*stack)->end)
	{
		Node w = Pop(stack);
		s = q[w.data];
		while (s->next != NULL)
		{
			s = s->next;
			if (m[s->n]!=1) {
				m[s->n] = 1;
				Node N;
				N.data = s->n;
				N.C = w.C + 1;
				if (N.C <= 6) {
					ss++;
					Push(stack, N);
				}			
			}
		}
	}
	printf("%d: %.2f%%\n",i,((ss+1)/number)*100);
	for (int i = 0; i <= number; i++)
	{
		m[i] = 0;
	}
	
}

int main()
{

	int number, L;
	scanf_s("%d %d", &number, &L);

	//建立邻接表
	qV *q = NULL;
	q=Create(q, number+1);

	//建立数组
	int m[10001] = {0};
	

	//插入元素
	int a, b;
	for (int i = 0; i < L; i++)
	{
		scanf_s("%d %d", &a, &b);
		Insert(&q, a, b);
		Insert(&q, b, a);
	}

	//建栈
	qStack p=NULL;
	CreateStack(&p,number);

	for (int i = 1; i <= number; i++)
	{
		qV s = q[i];
		printf("%d", s->n);
		while (s->next!=NULL)
		{
			s = s->next;
			printf("-->%d ", s->n);
		}
		printf("\n");
	}

	//便利六层
	for (int i = 1; i <= number; i++)
	{
		LookAll(q, &p, number, m, i);
		(*p).top = 0;
		(*p).end = 0;
	}

	

	system("pause");
    return 0;
}

