// 二分查找.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Node {
	ElemType data[100];
	int length;
}ListNode, *qNode;
int chazhao(qNode q, ElemType number);
int chazhao2(qNode q, ElemType number);
int main()
{
	qNode q = (ListNode *)malloc(sizeof(ListNode));
	q->length = 100;
	for (int i = 0;i < q->length;i++) {
		q->data[i] = i;
	}
	int number = 0, value = 0;
	scanf_s("%d", &number);
	value = chazhao(q, number);

	value = chazhao2(q, number);
	system("pause");
	return 0;
}

int chazhao(qNode q, ElemType number) {
	int value = -1, count = 0;
	int left = 0, right = q->length - 1, mid = 0;
	do {
		count++;
		mid = (left + right) / 2;
		if (q->data[mid] > number) {
			right = mid - 1;
		}
		else if (q->data[mid] < number) {
			left = mid + 1;
		}
		else {
			value = mid;
			break;
		}
	} while (left <= right);
	if (value != -1) {
		printf("查找了%d次", count);
		printf("   %d\n", value);
	}
	else {
		printf("查找了%d次\n", count);
		printf("没找到\n");
	}
	
	return value;
}

int chazhao2(qNode q, ElemType number) {
	int value = -1, count = 0;
	int left = 0, right = q->length - 1, mid = 0;
	do {
		count++;
		mid = int((right - left) *0.618) + left;
		if (q->data[mid] > number) {
			right = mid - 1;
		}
		else if (q->data[mid] < number) {
			left = mid + 1;
		}
		else {
			value = mid;
			break;
		}
	} while (left <= right);
	if (value != -1) {
		printf("查找了%d次", count);
		printf("    %d\n", value);
	}
	else {
		printf("查找了%d次\n", count);
		printf("没找到\n");
	}
	return value;
}