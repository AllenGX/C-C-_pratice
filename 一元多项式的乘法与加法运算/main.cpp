// 一元多项式的乘法与加法运算.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int N;
	int K;
	struct Node* next;
}LinkNode,*qNode;
void Consult(qNode q1, qNode q2, qNode *consult);
void Add(qNode *q, int n, int k);
void Create(qNode *q);
void Print(qNode q);
void AddNode(qNode q1, qNode *q2);
void exchange(qNode *q);
int main()
{
	qNode q1 = NULL;
	Create(&q1);
	int number, K, N;
	scanf_s("%d", &number);
	for (int i = 0;i < number;i++) {
		scanf_s("%d %d", &N,&K);
		Add(&q1, K, N);
	}
	qNode q2 = NULL;
	Create(&q2);
	scanf_s("%d", &number);
	for (int i = 0;i < number;i++) {
		scanf_s("%d %d", &N, &K);
		Add(&q2,K, N);
	}
	qNode consult = NULL;
	Create(&consult);
	Consult(q1, q2, &consult);
	AddNode(q1, &q2);
	exchange(&consult);
	exchange(&q2);
	Print(consult);
	printf("\n");
	Print(q2);
	free(q1);
	free(q2);
	free(consult);
	system("pause");
    return 0;
}

void Create(qNode *q) {
	if (*q == NULL) {
		*q = (LinkNode *)malloc(sizeof(LinkNode));
		(*q)->next = NULL;
	}
}

void Add(qNode *q,int n,int k) {
	if (*q) {
		qNode Q = *q;
		qNode s = (LinkNode*)malloc(sizeof(LinkNode));
		s->N = n;
		s->K = k;
		s->next = NULL;
		while (Q->next!=NULL)
		{
			Q = Q->next;
		}
		Q->next = s;
	}
}

void Print(qNode q) {
	int flag = 0;
	int flag1 = 0;
	if (q) {
		qNode p=q->next;
		while (p) {
			if (p->K != 0) {
				flag++;
				p=p->next;
			}
		}
		p = q->next;
		while (p&&flag!=0) {
			if (p->next != NULL) {
				printf("%d %d ", p->K, p->N);
			}
			else {
				printf("%d %d", p->K, p->N);
			}
			p = p->next;
		}


		if (flag == 0) {
			printf("0 0");
		}
	}
}

void AddNode(qNode q1, qNode *q2) {
	if (q1->next != NULL) {
		if ((*q2)->next == NULL) {
			(*q2)->next = q1->next;
		}
		else {
			qNode Q1 = q1->next,preQ1=q1;
			qNode Q2 = (*q2)->next,preQ2=(*q2);
			while (Q1 != NULL&&Q2!=NULL) {
				if (Q1->N == Q2->N) {
					if ((Q1->K + Q2->K) == 0) {
						Q1 = Q1->next;
						preQ1 = preQ1->next;
						preQ2->next=Q2->next;
						free(Q2);
						Q2 = preQ2->next;
					}
					else {
						Q2->K = Q1->K + Q2->K;
						Q1 = Q1->next;
						Q2 = Q2->next;
						preQ2 = preQ2->next;
						preQ1 = preQ1->next;
					}
				}
				else if (Q1->N > Q2->N) {
					preQ1 = Q1;
					Q1 = Q1->next;
					preQ1->next = preQ2->next;
					preQ2->next = preQ1;
					preQ2 = preQ2->next;
				}
				else {
					preQ2 = Q2;
					Q2 = Q2->next;
				}
			}
			if (Q2 == NULL) {
				preQ2->next = Q1;
			}
		}
	}
}

void Consult(qNode q1, qNode q2, qNode *consult) {
	qNode Q1,temp1;
	while (q2->next!=NULL)
	{
		qNode temp = (LinkNode*)malloc(sizeof(LinkNode));
		temp->next = NULL;
		temp1 = temp;
		Q1 = q1->next;
		q2 = q2->next;

		while (Q1!=NULL)
		{
			qNode s= (LinkNode*)malloc(sizeof(LinkNode));
			s->K = Q1->K*(q2->K);
			s->N = Q1->N + q2->N;
			s->next = NULL;
			temp1->next = s;
			temp1 = temp1->next;
			Q1 = Q1->next;
		}
		AddNode(temp, consult);
		free(temp);
	}
}

void exchange(qNode *q) {
	int flag = 0;
	qNode p = (*q)->next,pre=(*q); 
		while (p) {
			if (p->K == 0) {
				if (flag > 0) {
					pre->next = p->next;
					free(p);
					p = pre->next;
				}
				else {
					pre = p;
					p = p->next;
				}
				flag++;
			}
			else {
				pre = p;
				p = p->next;
			}	
		}
	
}