// 11-散列4 Hashing - Hard Version.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


int main()
{
	//int k[1000];
	int counts;
	scanf_s("%d", &counts);
	//counts = 1000;
	int *k = (int *)malloc(sizeof(int)*counts);
	int cnt = 0;
	for (int i = 0; i < counts; i++)
	{
		scanf_s("%d", &k[i]);
		//k[i] = i * i-i*3*3;
		if (k[i] >= 0)cnt++;
	}
	int xiaobiao = 0;
	//总共有cnt个数要被输出
	for (int i = 0; i < cnt; i++)
	{
		//移位操作
		int ns = 0;
		
		if (xiaobiao < 0)xiaobiao = counts - 1;
		if (xiaobiao == counts)xiaobiao = 0;
		while (ns<counts)
		{
			if (xiaobiao < 0)xiaobiao = counts - 1;
			if (xiaobiao == counts)xiaobiao = 0;
			if (k[xiaobiao] >= 0) {	//有数

				int XX = xiaobiao;
				int X = XX - 1;		//前一个数
				if (X == counts)X = 0;
				if (X < 0)X = counts - 1;

				while (k[XX] % counts != XX && k[X]<0)	//有移动条件
				{

					k[X] = k[XX];
					k[XX] = -1;
					XX--;
					X--;
					if (XX < 0)XX = counts - 1;
					if (XX == counts)XX = 0;
					if (X == counts)X = 0;
					if (X < 0)X = counts - 1;
				}
			}
			ns++;
			xiaobiao++;
		}
		int min = 100000 ; 
		xiaobiao = 0;
		//扫描一遍求最小
		for (int j = 0; j < counts; j++)
		{
			if (k[j] % counts == j && k[j] < min) {
				min = k[j];
				xiaobiao = j;
			}
		}
		//最小值保存在k[xiaobiao]中
		k[xiaobiao] = -1;	//置为空
		printf("%d", min);	
		if (i<cnt-1)
		{
			printf(" ");
			//printf("\n");
		}
	}
	system("pause");
    return 0;
}

