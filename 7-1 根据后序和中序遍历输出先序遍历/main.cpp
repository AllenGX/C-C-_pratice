// 7-1 根据后序和中序遍历输出先序遍历.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int number = 0;
void PRE(int *A, int *B, int length,int *S) {
	if (length > 0) {
		int s = A[length - 1];
		//printf("%d ", s);
		S[number++] = s;
		int i = 0;
		while (i<length)
		{
			if (s == B[i])
				break;
			i++;
		}
		PRE(A, B, i,S);
		PRE(A + i, B + i + 1, length - i - 1,S);
	}
}




int main()
{
	int s[31];
	int number;
	scanf_s("%d", &number);
	int A[31];
	int B[31];
	for (int i = 0; i < number; i++)
	{
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < number; i++)
	{
		scanf_s("%d", &B[i]);
	}
	PRE(A, B,number,s);
	printf("Preorder:");
	for (int i = 0; i < number; i++)
	{
		
		if (i != number - 1) {
			//printf(" ");
		}
		printf(" %d", s[i]);
		
	}
	system("pause");
    return 0;
}

