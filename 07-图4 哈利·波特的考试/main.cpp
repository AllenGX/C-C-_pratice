// 07-图4 哈利·波特的考试.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#define MaxSize 1000
int main()
{
	int N, M;
	scanf_s("%d %d", &N,&M);
	//int **A = (int **)malloc(sizeof(int *)*N);
	int A[100][100];
	for (int i = 0; i < N; i++)
	{
		//int *a = (int *)malloc(sizeof(int)*N);
		//A[i] = a;
		for (int j = 0; j < N; j++)
		{
			A[i][j] = MaxSize;
		}
	}
	int c, d ,n;
	for (int i = 0; i < M; i++)
	{
		scanf_s("%d %d %d", &c, &d,&n);
		A[c-1][d-1] = n;
		A[d-1][c-1] = n;
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] > a[i][k] + a[k][j]&&i!=j) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}

	


	int max=0, min=MaxSize,z,count=0;
	for (int i = 0; i < N; i++)
	{
		max = 0, count = 0;
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] > max&&i!=j) {
				max = A[i][j];
			}
			if (A[i][j] == MaxSize) {
				count++;
			}
		}
		if (count > 1) {
			z = -1;
			break;
		}
		if (max < min) {
			min = max;
			z = i+1;
		}
	}

	if (z == -1) {
		printf("0");
	}
	else {
		printf("%d %d", z, min);
	}

	system("pause");
    return 0;
}

