// 递增单链表合并.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Merge(List L1, List L2);

int main()
{
	List L1=NULL, L2=NULL, L;
	L = Merge(L1, L2);

	return 0;
}

List Merge(List l1, List l2) {
	List pre = l1->Next, qre = l2->Next;
	List L = (struct Node*)malloc(sizeof(struct Node));
	List l = L;
	L->Data = 0;
	L->Next = NULL;
	
	while (pre != NULL && qre != NULL)
	{
		if (pre->Data > qre->Data) {
			l->Next = qre;
			qre = qre->Next;
			l = l->Next;
		}
		else if (pre->Data < qre->Data) {
			l->Next = pre;
			pre = pre->Next;
			l = l->Next;
		}
		else {
			l->Next = pre;
			pre = pre->Next;
			l = l->Next;
			l->Next = qre;
			qre = qre->Next;
			l = l->Next;
		}
	}
	if (pre == NULL) {
		l->Next = qre;
;
	}
	if (qre == NULL) {
		l->Next = pre;
	}
	l1->Next = NULL;
	l2->Next = NULL;
	return L;
}