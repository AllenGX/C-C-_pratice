// 顺序表各项操作.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
typedef int Elemtype;
typedef struct Node {
	Elemtype *data;		//存储数组的指针
	int length;			//顺序表元素个数
	int size;			//顺序表长度
}List,*QList;		//指向结构体的指针

bool InitList(QList &L);
void DestroyList(QList &L);
bool ListEmpty(QList q);
bool ListLength(QList q, int &n);
bool DisList(QList q);
bool GetElem(QList q, int P, int &number);
int LocateElem(QList q, Elemtype X);
bool ListInsert(QList &q, int P, Elemtype X);
bool ListDelet(QList &q, int P, Elemtype &X);
void InverstList_SeqStrage(QList &q);
int main()
{
	QList q=NULL;

	if (InitList(q)!=NULL) {
		printf("%d\n", q->size);
	}

	int n = 0;
	if (ListLength(q, n)) {
		printf("%d\n", n);
	}
	DisList(q);
	InverstList_SeqStrage(q);
	printf("颠倒之后\n");

	DisList(q);

	int number;
	if (GetElem(q, 1, number)) {
		printf("第1个数为%d\n", number);
	}

	if (ListInsert(q, 1, 3)) {
		if (GetElem(q, 1, number)) {
			printf("把3插入第一个位置\n");
			DisList(q);
			printf("第1个数为%d\n", number);
		}
	}
	int X = LocateElem(q, 1);

	printf("值为1的数在第%d个位置\n", X);

	int W;
	if (ListDelet(q, X, W)) {
		printf("值为%d的数在第%d个位置被删去\n", W,X);
	}
	
	DisList(q);
	InverstList_SeqStrage(q);
	printf("颠倒之后\n");

	DisList(q);
	

	if (ListEmpty(q)) {
		printf("空的\n");
	}

	DestroyList(q);
	system("pause");
	return 0;
}

//新建一个顺序表	加&表示该变量会返回更改后的值  一般在需要操作传入数本身时使用
bool InitList(QList &L) {
	bool states = false;
	if (L == NULL) {
		L = (List *)malloc(sizeof(List));
		L->data = (Elemtype *)malloc(sizeof(Elemtype)*MaxSize);
		L->data[0] = 1;
		L->data[1] = 2;
		L->data[2] = 3;
		L->data[3] = 4;
		L->length =4;
		L->size = MaxSize;
		if (L != NULL) {
			states = true;
		}
	}
	return states;
}

//销毁顺序表
void DestroyList(QList &L) {
	//free(L->data);
	free(L);
}

//判断顺序表是否为空
bool ListEmpty(QList q) {
	bool states = false;
	if (q->length==0) {
		states = true;
	}
	return states;
}

//得到表长
bool ListLength(QList q,int &n) {
	bool states = false;
	if (q) {
		n = q->length;
		states = true;
	}
	return states;
}

//得到表数据
bool DisList(QList q) {
	bool states = false;
	if (q) {
		for (int i = 0;i < q->length;i++) {
			printf("%d ", q->data[i]);
		}
		states = true;
		printf("\n");
	}
	return states;
}

//得到某个位置的数
bool GetElem(QList q, int P, int &number) {
	bool states = false;
	if (q) {
		if (P - 1 < q->length&&P > 0) {
			number = q->data[P-1];
			states = true;
		}
	}
	return states;
}

//查找某个元素位置
int LocateElem(QList q, Elemtype X) {
	if (q) {
		if (q->length > 0) {
			for (int i = 0;i < q->length;i++) {
				if (q->data[i] == X) {
					return i+1;
				}
			}
		}
	}
	return 0;
}

//插入元素
bool ListInsert(QList &q, int P, Elemtype X) {
	bool states = false;
	P--;
	if (q) {
		if (q->length < MaxSize) {
			if (P >= 0 && P < q->length) {
				for (int i = q->length - 1;i >= P;i--) {
					q->data[i + 1] = q->data[i];
				}
				q->data[P] = X;
				q->length++;
				states = true;
			}
		}
	}
	return states;
}

//删除某个元素
bool ListDelet(QList &q,int P, Elemtype &X) {
	bool states = false;
	P--;
	if (q) {
		if (P >= 0 && P < q->length) {
			X = q->data[P];
			for (int i = P;i < q->length-1;i++) {
				q->data[i] = q->data[i + 1];
			}
			q->length--;
			states = true;
		}
	}
	return states;
}

//倒置
void InverstList_SeqStrage(QList &q) {
	QList p = NULL;
	if (InitList(p)) {
		p->length = q->length;
		p->size = q->size;
		for (int i = 0;i < p->length;i++) {
			p->data[i] = q->data[p->length - i-1];
		}
		DestroyList(q);
		q = p;
	}
}

