// 1022. D进制的A+B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>






int main()
{
	int a, b,n;
	char A[100] = { 0 }, B[100] = { 0 };
	int C[100] = { 0 };
	scanf_s("%d %d %d", &a, &b, &n);
	int countA = 0,countB=0,countC=0;
	do
	{
		A[countA] = a % n;
		countA++;
		a /= n;
	} while (a!=0);
	do
	{
		B[countB] = b % n;
		countB++;
		b /= n;
	} while (b!= 0);

	int length = countA > countB ? countA : countB;
	int flag = 0;
	for (int i = 0; i < length; i++)
	{
		if (flag + (int)(A[i]) + (int)(B[i]) >= n) {	
			C[i] = (flag + (int)(A[i]) + (int)(B[i]))-n;
			flag = 1;
		}
		else {
			
			C[i] = flag + (int)(A[i]) + (int)(B[i]);
			flag = 0;
		}
	}
	if (flag == 1) {
		C[length] = 1;
		length++;
	}
	for (int i = length-1; i >=0; i--)
	{
		printf("%d", C[i]);
	}
	system("pause");
    return 0;
}

