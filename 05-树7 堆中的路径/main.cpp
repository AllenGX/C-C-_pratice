// 05-树7 堆中的路径.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
void create(int *a, int n);
void insert(int *a, int n, int number);
void print1(int *a, int n,int h);
int main()
{
	int a[1001];
	a[0] = -100001;
	int n = 0, h = 0, s = 0;;
	scanf_s("%d %d", &n, &h);
	
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
		insert(a, i, a[i]);
	}

	//create(a, n);
	for (int i = 0; i <h; i++) {
		scanf_s("%d", &s);
		print1(a,n,s);
	}


	system("pause");
    return 0;
}

void create(int *a,int n) {
	int flag = 0;
	if (n != 0) {
		for (int i = n; i>0; i--) {
			if (2 * i  <= n) {	//左子树判别
				if (a[i] > a[2 * i ]) {	//交换
					int temp = a[i];
					a[i] = a[2 * i ];
					a[2 * i] = temp;
					flag = 1;
				}
			}
			if (2 * i + 1 <= n) {	//右子树判别
				if (a[i] > a[2 * i + 1]) {	//交换
					int temp = a[i];
					a[i] = a[2 * i + 1];
					a[2 * i + 1] = temp;
					flag = 1;
				}
			}
		}
		if (flag == 1) {
			create(a, n);
		}
	}
}

void insert(int *a, int n,int number) {
	a[n] = number;
	while (n>=1)
	{
		if (a[n] < a[(n / 2)]) {
			int temp = a[n];
			a[n] = a[(n / 2)];
			a[(n / 2)] = temp;
		}
		n = n / 2;
	}
}

void print1(int *a, int n,int h) {
	if (n != 0&&h<=n&&h>0) {

		if (h == 1) {
			printf("%d\n", a[1]);
		}
		else {
			do
			{
				printf("%d ", a[h]);
				h = h / 2;
			} while (h>1);
			printf("%d\n", a[1]);
		}
	}
	else {
		printf("\n");
	}
}
