// 链表各项操作.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node *next;
}LinkNode,*QLink;
bool CreateList(QLink &q);	//创建
bool DestoryList(QLink &q);	//销毁
bool ListEmpty(QLink q);	//判断空
bool ListLength(QLink q, int &X);	//求长度
bool DispList(QLink q);		//输出
bool GetElem(QLink q, int P, ElemType &X);	//找某个位置的数
bool LocateElem(QLink q, ElemType X, int &P); //找元素位置
bool ListInsert(QLink &q, ElemType X, int P);	//在某个位置插入元素
void InvertList_LinkedStorage(QLink &q);		//倒置
int main()
{
	QLink q = NULL;
	if (ListEmpty(q)) {
		printf("空的\n");
	}
	if (CreateList(q)) {
		printf("长度为%d\n",q->data);
	}
	if (ListEmpty(q)) {
		printf("空的\n");
	}
	ListInsert(q, 10, 1);
	ListInsert(q, 9, 1);
	ListInsert(q, 8, 1);
	ListInsert(q, 7, 1);
	DispList(q);
	InvertList_LinkedStorage(q);
	DispList(q);

	int number=0;
	ListLength(q, number);
	printf("长度为%d\n", number);
	GetElem(q, 4, number);
	printf("第四个数为%d\n", number);
	LocateElem(q, 8, number);
	printf("8在第%d个\n", number);
	if (DestoryList(q)) {
		printf("销毁了\n");
	}

	system("pause");
    return 0;
}


//创建操作
bool CreateList(QLink &q) {
	bool states = false;
	if (q == NULL) {
		q = (LinkNode *)malloc(sizeof(LinkNode));
		q->next = NULL;
		q->data = NULL;
		states = true;
	}
	return states;
}

//销毁操作
bool DestoryList(QLink &q) {
	bool states = false;
	LinkNode *pre = q, *p = q->next;
	if (q) {
		while (p != NULL) {
			free(pre);
			pre = p;
			p = p->next;
		}
		states = true;
	}
	return states;
}

//判断是否为空表
bool ListEmpty(QLink q) {
	LinkNode *p = q;
	bool states = false;
	if (q==NULL) {
		//if (p->next == NULL) {
			states = true;
		//}
	}
	return states;
}

//返回链表长度
bool ListLength(QLink q,int &X) {
	bool states = false;
	LinkNode *p = q;
	int i = 0;
	if (q) {
		while (p->next!=NULL) {
			p = p->next;
			i++;
		}
		states = true;
	}
	X = i;
	return states;
}

//输出链表中所有元素
bool DispList(QLink q) {
	LinkNode *p = q;
	bool states = false;
	if (q) {
		while (p->next != NULL) {
			p = p->next;
			printf("%d ", p->data);
		}
		printf("\n");
		states = true;
	}
	return states;
}

//求链表中某个元素的值
bool GetElem(QLink q, int P, ElemType &X) {
	int j = 0;
	LinkNode *p = q;
	bool states = false;
	if (q) {
		while (p->next != NULL) {
			p = p->next;
			j++;
			if (j == P) {
				X = p->data;
				states = true;
				break;
			}
		}
	}
	return states;
}

//查找元素位置
bool LocateElem(QLink q, ElemType X,int &P) {
	LinkNode *p = q;
	int i = 0;
	bool states = false;
	if (q) {
		while (p->next!= NULL) {
			p = p->next;
			i++;
			if (p->data == X) {
				P = i;
				states = true;
				break;
			}
		}
	}
	return states;
}

//在某个位置插入元素
bool ListInsert(QLink &q, ElemType X,int P) {
	LinkNode *p=q;
	int i = 0;
	bool states = false;
	if (q) {
		if (P == 1) {
			LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = X;
			s->next = p->next;
			p->next = s;
			states = true;
		}else{
			while (p->next != NULL) {
				p = p->next;
				i++;
				if (i == P) {
					LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = X;
					s->next = p->next;
					p->next = s;
					states = true;
					break;
				}
			}
		}
	}
	return states;
}


//倒置
void InvertList_LinkedStorage(QLink &q) {
	if (q->next->next!=NULL) {
		LinkNode *pre=q->next->next,*p=pre->next;
		q->next->next = NULL;
		while (p != NULL) {
			pre->next = q->next;
			q->next = pre;
			pre = p;
			p = p->next;
		}
		pre->next = q->next;
		q->next = pre;
	}
}