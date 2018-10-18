// 1015. 德才论.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
	int id;
	int de;
	int cai;
}Nodes;

void Sort(Nodes *q,int length) {
	int temp;
	int flag;
	for (int i = 0; i < length; i++)
	{
		flag = 0;
		for (int j = 0; j < length-1-i; j++)
		{
			if ((q[j].cai + q[j].de) < (q[j + 1].cai + q[j + 1].de)) {
				temp = q[j].cai;
				q[j].cai = q[j + 1].cai;
				q[j + 1].cai = temp;

				temp = q[j].de;
				q[j].de = q[j + 1].de;
				q[j + 1].de = temp;

				temp = q[j].id;
				q[j].id = q[j + 1].id;
				q[j + 1].id = temp;
				flag = 1;
			}
			else if ((q[j].cai + q[j].de) == (q[j + 1].cai + q[j + 1].de)) {
				if (q[j].de < q[j + 1].de) {
					temp = q[j].cai;
					q[j].cai = q[j + 1].cai;
					q[j + 1].cai = temp;

					temp = q[j].de;
					q[j].de = q[j + 1].de;
					q[j + 1].de = temp;

					temp = q[j].id;
					q[j].id = q[j + 1].id;
					q[j + 1].id = temp;
					flag = 1;
				}
			}
		}
		if (flag == 0)break;
	}
}
// 归并
void SortLink(int *a, int *b, int left, int right) {
	int center = (left + right - 1) / 2;
	int A = left;
	int B = center + 1;
	for (int i = left; i < right; i++) {		//归并操作
		if (a[A] > a[B]) {
			b[i] = a[B];
			B++;
		}
		else {
			b[i] = a[A];
			A++;
		}
		if (B >= right) {		//后面部分遍历完了，前面还没有，直接把前面部分进行拼接
			while (A <= center) {
				b[++i] = a[A];
				A++;
			}
		}
		if (A > center) {		//前面部分遍历完了，后面还没有，直接把后面部分进行拼接
			while (B <= right) {
				b[++i] = a[B];
				B++;
			}
		}
	}
	for (int i = left; i < right; i++)		//把b数组内容返回给a
	{
		a[i] = b[i];
	}
}


//分治
void ApartSort(int *a, int start, int length, int *b) {
	int center = (start + length - 1) / 2;
	//int *b = (int *)malloc(sizeof(int)*length);		为了节约空间  不在递归中使用创建空间
	if (center>start) {
		ApartSort(a, start, center, b);	//递归左边
		ApartSort(a, center + 1, length, b);	//递归右边
		SortLink(a, b, start, length);	//归并
	}
}

//出口	分治调用
void Apart_sort(int *a, int start, int length) {
	if (length != 0) {
		int *b = (int *)malloc(sizeof(int)*length);
		ApartSort(a, start, length, b);
	}
	else {
		printf("数组为空");
	}
}

//归并排序
void Sort(Nodes *a, Nodes *b, int left, int right) {
	int Center = (left + right) / 2;
	int A = left;
	int B = Center + 1;
	int K = left;
	while (A != Center + 1 && B != right + 1) {
		if ((a[A].cai + a[A].de) < (a[B].cai + a[B].de) || (a[A].cai + a[A].de) == (a[B].cai + a[B].de) && (a[A].de < a[B].de) || (a[A].cai + a[A].de) == (a[B].cai + a[B].de) && (a[A].de == a[B].de) && a[A].id > a[B].id) {
			b[K].cai = a[B].cai;
			b[K].de = a[B].de;
			b[K].id = a[B].id;
			B++;
			K++;
		}
		else {
			b[K].cai = a[A].cai;
			b[K].de = a[A].de;
			b[K].id = a[A].id;
			A++;
			K++;
		}
	}
	while (A != Center + 1)
	{
		b[K].cai = a[A].cai;
		b[K].de = a[A].de;
		b[K].id = a[A].id;
		A++;
		K++;

	}
	while (B != right + 1)
	{
		b[K].cai = a[B].cai;
		b[K].de = a[B].de;
		b[K].id = a[B].id;
		B++;
		K++;
	}
	for (int i = left; i <=right; i++)
	{
		a[i].cai = b[i].cai;
		a[i].de = b[i].de;
		a[i].id = b[i].id;
	}
}

//分治
void Apart(Nodes *a, Nodes *b, int left, int right) {
	
	if (right > left) {
		int Center = (left + right) / 2;
		Apart(a, b, left, Center);
		Apart(a, b, Center + 1, right);
		Sort(a, b, left, right);
	}
}

//出口
void SSort(Nodes *a, int left, int right) {
	Nodes *b;
	if (left < right) {
		 b= (Nodes *)malloc(sizeof(Nodes)*(100000));
		Apart(a, b, left, right);
		free(b);
		b = NULL;
	}
}

int main()
{

	
	int n, m1, m2;
	int a, b, c;
	int b1=0, c1=0, d1=0, e1=0;
	scanf_s("%d %d %d\n", &n, &m1, &m2);

	Nodes *B = (Nodes *)malloc(sizeof(Nodes) * n);
	Nodes *C = (Nodes *)malloc(sizeof(Nodes) * n);
	Nodes *D = (Nodes *)malloc(sizeof(Nodes) * n);
	Nodes *E = (Nodes *)malloc(sizeof(Nodes) * n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d %d", &a, &b, &c);
		if (b >= m2 && c >= m2) {
			B[b1].id = a;
			B[b1].de = b;
			B[b1].cai = c;
			b1++;
		}
		else if (b>=m2&&c>=m1) {
			C[c1].id = a;
			C[c1].de = b;
			C[c1].cai = c;
			c1++;
		}
		else if (b >= m1 && c >= m1 && b >= c) {
			D[d1].id = a;
			D[d1].cai = c;
			D[d1].de = b;
			d1++;
		}
		else if(b >= m1 && c >= m1){
			E[e1].id = a;
			E[e1].de = b;
			E[e1].cai = c;
			e1++;
		}
	}

	SSort(B,0,b1-1);
	SSort(C, 0,c1-1);
	SSort(D, 0,d1-1);
	SSort(E, 0,e1-1);

	printf("%d\n", (b1 + c1 + d1 + e1));
	for (int i = 0; i < b1; i++)
	{
		printf("%d %d %d\n", B[i].id, B[i].de, B[i].cai);
	}
	for (int i = 0; i < c1; i++)
	{
		printf("%d %d %d\n", C[i].id, C[i].de,C[i].cai);
	}
	for (int i = 0; i < d1; i++)
	{
		printf("%d %d %d\n", D[i].id, D[i].de, D[i].cai);
	}
	for (int i = 0; i < e1; i++)
	{
		printf("%d %d %d\n",E[i].id, E[i].de, E[i].cai);
	}

	system("pause");
    return 0;
}

