// 06-图2 Saving James Bond - Easy Version.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>

typedef float Elemetype;
typedef struct v {
	int n;
	struct v* next;
}V,*qV;

typedef struct point {
	Elemetype x;
	Elemetype y;
	int states;
}Point,*qPoint;

typedef struct stack {
	int *n;	//*qV的编号
	int top;
}Stack,*qStack;

//构造栈
void CreateStack(qStack *q,int numbers) {
	*q = (Stack *)malloc(sizeof(Stack));
	(*q)->n = (int *)malloc(sizeof(int)*numbers);
	(*q)->top = -1;
}

//出栈
int Pop(qStack *q) {
	int N;
	if ((*q)->top != -1) {
		N = (*q)->n[(*q)->top];
		(*q)->top--;
	}
	return N;
}
//入栈
void Push(qStack *q, int N) {
	(*q)->top++;
	(*q)->n[(*q)->top] = N;
}

//构造矩阵表
void Create(qV **q,int numbers) {
	*q = (qV *)malloc(sizeof(qV)*numbers);
	for (int i = 0; i < numbers; i++)
	{
		V *a = (V *)malloc(sizeof(V));
		a->n = i;
		//a->states = 0;
		a->next = NULL;
		(*q)[i] = a;
	}
}

//判断点集是否能连通
int isLink(Point q, Point p,float d) {
	if (p.x==0&&p.y==0) {
		float D = (q.x - p.x)*(q.x - p.x) + (q.y - p.y)*(q.y - p.y);
		if (D <= (d+15/2.0) * (d + 15/2.0)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		float D = (q.x - p.x)*(q.x - p.x) + (q.y - p.y)*(q.y - p.y);
		if (D <= d * d) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

//判断能否逃脱
int isPao(Point q,float D) {
	if (q.x >= (50 - D) || q.x <= (D - 50) || q.y >= (50-D) || q.y <= (D - 50)) {
		return 1;
	}
	else {
		return 0;
	}
	
}

//向矩阵表插入节点
void Insert(qV **q,int i,int n) {
	if (i != n) {
		qV s = (qV)malloc(sizeof(V));
		s->n = i;
		//s->states = 0;
		s->next = (*q)[n]->next;
		(*q)[n]->next = s;
	}
}


//构造点集
qPoint Creat(qPoint q,int number) {
	q = (Point *)malloc(sizeof(Point)*number);
	return q;
}


//开始遍历图
int Throgh(qStack *stack,qV *q,int numbers,qPoint p,float D) {
	int N;
	qV s;
	s = q[0];
	//(*s) = (*s)->next;	//起点的周围点都放入栈中
	while (s->next != NULL) {
		s = s->next;
		Push(stack, (s)->n);
		//printf("%d", p[13].states);
		p[((s)->n) - 1].states = 1;
	}
	//栈不为空时
	while ((*stack)->top!=-1)
	{
		N = Pop(stack);
		if (isPao(p[N-1], D) == 1) {
			return 1;
		}
		s = q[N];
		//(*s) = (*s)->next;
		while (s->next != NULL) {	//队列都入栈
			s = s->next;
			if (p[(s->n) - 1].states != 1) {
				Push(stack, (s)->n);
				p[(s->n) - 1].states = 1;
				
			}
		}
	}
	return 0;
}


int main()
{
	//读入的数以及距离
	int numbers,D;
	scanf_s("%d %d", &numbers, &D);
	
	//构造矩阵表
	qV *a = NULL;
	Create(&a, numbers+1);

	//创建栈
	qStack stack=NULL;
	CreateStack(&stack,numbers);
	//Push(&stack, 1);
	//printf("%d", Pop(&stack));

	//原点
	Point p0;
	p0.x = 0;
	p0.y = 0;
	p0.states = 0;

	//构造点集
	qPoint q = NULL;
	q=Creat(q,numbers);
	int X, Y;
	for (int  i = 0; i < numbers; i++)
	{
		scanf_s("%d %d", &X, &Y);
		q[i].x = X;
		q[i].y = Y;
		q[i].states = 0;

		//起始点能走的路径都插入
		if (isLink(q[i],p0 , D)==1) {
			Insert(&a, i+1, 0);
		}
		/*if (isPao(q[i],D) == 1) {
			printf("\n%d\n  ", i);
		}*/
		//
	}
	

	//从第一个点开始插入能连通的路径
	for (int i = 1; i <= numbers; i++)
	{
		for (int j = 0; j < numbers; j++)
		{
			if (isLink(q[j], q[i-1], D) == 1) {
				Insert(&a, j + 1, i);
			}
			//printf("%d", a[1]->next);
		}
	}
	//printf("%f", (D+ 15 / 2.0) * (D + 15 / 2.0));


	//



	//for (int i = 0; i <= numbers; i++)
	//{
	//	qV q = a[i];
	//	
	//	printf("%d ", q->n);
	//	while (q->next != NULL)
	//	{
	//		q = q->next;
	//		printf("-->%d ", q->n);
	//	}
	//	printf("\n");
	//}


	int flag= Throgh(&stack,  a,  numbers, q,  D);
	if (flag == 1) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	system("pause");
    return 0;
}

