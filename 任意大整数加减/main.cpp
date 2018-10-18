#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int ElemType;
typedef struct Node {
	ElemType date;
	struct Node *next;
}ListNode,*qNode;
void MathLong(qNode q1, qNode q2, qNode *q3, char math);
void rever(qNode q, qNode *l);
void addHead(qNode *q, ElemType X);
int PK(qNode q1, qNode q2);
void print(qNode q);
int main()
{
	char add = '+', di = '-', result = '=';
	char a = 0, b = 0, c = 0;
	int A = 0;
	qNode q1 = NULL, q2 = NULL,q3=NULL;

	printf("输入第一个数字:\n");
	do
	{
		scanf_s("%c", &a);
		if ((a >= '0'&&a <= '9')) {
			A = a - '0';
			addHead(&q1, A);
		}
		else if(int(a) == int(di)){
			c = di;
		}
		else {
			c = add;
		}
	} while (int(a)!=int(di)&&int(a) != int(add));

	printf("输入第二个数字:\n");
	do
	{
		scanf_s("%c", &b);
		if (b>='0'&&b<='9') {
			A = b - '0';
			addHead(&q2, A);
		}
	} while (int(b) != int(result));

	printf("结果为:		");
	MathLong(q1, q2, &q3, c);
	printf("\n");
	free(q1);
	free(q2);
	free(q3);
	system("pause");
    return 0;
}

void addHead(qNode *q, ElemType X) {
	if (*q == NULL) {
		(*q) = (ListNode *)malloc(sizeof(ListNode));
		(*q)->date = X;
		(*q)->next = NULL;
	}
	else {
		qNode s = (ListNode *)malloc(sizeof(ListNode));
		s->date = X;
		s->next = (*q);
		(*q)= s;
	}
}

void rever(qNode q,qNode *l) {
	qNode p = NULL, pre = q, p1 = NULL;;
	while (pre != NULL)
	{
		qNode s = (qNode)malloc(sizeof(ListNode));
		s->date = pre->date;
		s->next = p1;
		p = s;
		p1 = s;
		pre = pre->next;
	}
	(*l) = p;
}

void print(qNode q) {
	int flag = 0, number = 0;
	qNode p = q;
	while (p!=NULL)
	{
		if (p->date == 0 && flag == 0) {
		}
		else {
			flag = 1;
			number++;
		}
		p = p->next;
	}
	if (q) {
		flag = 0;
		while (q!=NULL)
		{
			if (q->date == 0 && flag == 0) {
				q = q->next;
			}
			else {

				printf("%d", q->date);
				flag = 1;
				q = q->next;
				
				number=number-1;
				if (number % 4 == 0 && number>3) {
					printf(",");
				}
			}
		}
	}
}


int PK(qNode q1, qNode q2) {
	int result = -1,flag1=0,flag2=0;
	qNode p1 = q1,p2=q2;
	while (1)
	{
		if (p1 != NULL) {
			flag1++;
			if (p2 == NULL) {
				result = 1;
				break;
			}
			else
			{
				flag2++;
			}
		}
		else
		{
			if (p2 != NULL) {
				result = 2;
			}
			
			break;
			
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	
	if (result == -1) {
		rever(q1, &p1), rever(q2, &p2);
		while (p1 != NULL)
		{
			if (p1->date > p2->date) {
				result = 1;
				break;
			}
			else if (p1->date < p2->date) {
				result = 2;
				break;
			}
			else {
				p1 = p1->next;
				p2 = p2->next;
			}
			result = 0;
		}
	}
	return result;
}

void MathLong(qNode q1, qNode q2, qNode *q3,char math) {
	(*q3) = (qNode)malloc(sizeof(ListNode));
	(*q3)->date = 0;
	(*q3)->next = NULL;
	if (int(math) == int('+')) {
		qNode p = (*q3);
		int  ten = 0,ling=0;
		while (q2!=NULL&&q1!=NULL)
		{
			qNode s= (qNode)malloc(sizeof(ListNode));
			if ((q2->date + q1->date+ten)>9) {
				ling = (q2->date + q1->date + ten- 10);
				ten = 1;
				s->date = ling;
				s->next = NULL;
				p->next = s;
				p = s;
			}
			else {
				ling = q2->date + q1->date + ten;
				ten = 0;
				s->date = ling;
				s->next = NULL;
				p->next = s;
				p = s;
			}
			q2 = q2->next;
			q1 = q1->next;
		}
		if (q2 == NULL&&q1!=NULL) {
			p->next = q1;
			q1->date = ten +q1->date;
		}
		else if (q2 != NULL && q1 == NULL) {
			p->next = q2;
			q2->date = ten + q2->date;
		}
		else {
			if (ten == 1) {
				qNode s = (qNode)malloc(sizeof(ListNode));
				s->date = 1;
				s->next = NULL;
				p->next = s;
				p = s;
			}

		}
		p = (*q3);
		(*q3) = (*q3)->next;
		free(p);
		qNode q4 =NULL;
		rever(*q3, &q4);
		print(q4);
	}
	else {
		int flag = PK(q1, q2), ten = 0;
		qNode p = (*q3);
		if (flag == 1) {
			while (q1!=NULL&&q2!=NULL)
			{
				if (q1->date+ten >= q2->date) {
					qNode s = (qNode)malloc(sizeof(ListNode));
					s->date = q1->date - q2->date + ten;
					ten = 0;
					s->next = NULL;
					p->next = s;
					p = s;
				}
				else {
					qNode s = (qNode)malloc(sizeof(ListNode));
					s->date = q1->date - q2->date +10;
					s->next = NULL;
					p->next = s;
					p = s;
					ten = -1;
				}
				q1 = q1->next;
				q2 = q2->next;
			}
			if (q1 != NULL && q2 == NULL) {
				p->next = q1;
				q1->date = q1->date + ten;
			}
			p = (*q3);
			(*q3) = (*q3)->next;
			free(p);
			qNode q4 = NULL;
			rever(*q3, &q4);
			print(q4);

		}
		else if (flag = 2) {
			while (q1 != NULL && q2 != NULL)
			{
				if (q2->date + ten >= q1->date) {
					qNode s = (qNode)malloc(sizeof(ListNode));
					s->date = q2->date - q1->date + ten;
					ten = 0;
					s->next = NULL;
					p->next = s;
					p = s;
				}
				else {
					qNode s = (qNode)malloc(sizeof(ListNode));
					s->date = q2->date - q1->date + 10;
					s->next = NULL;
					p->next = s;
					p = s;
					ten = -1;
				}
				q1 = q1->next;
				q2 = q2->next;
			}
			if (q2 != NULL && q1 == NULL) {
				p->next = q2;
				while (q2->date + ten<0)
				{
					q2->date = q2->date + ten+10;
					ten = -1;
					q2 = q2->next;
				}
				q2->date = q2->date + ten;
			}
			p = (*q3);
			(*q3) = (*q3)->next;
			free(p);
			qNode q4 = NULL;
			rever(*q3, &q4);
			printf("-");
			print(q4);
		}
		else {
			printf("0");
		}
	}

	

}