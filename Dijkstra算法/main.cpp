// Dijkstra算法.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXV 30
#define MAX 1000000
void Floyd(int path[][30],int A[][30],int a[][30])
{
	int i, j, k, n = MAXV;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
		{
			A[i][j] = a[i][j];
			path[i][j] = -1;
		}
	for (k = 0; k<n; k++)
	{
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				if (sqrt(A[i][j])>(sqrt(A[i][k]) + sqrt(A[k][j]))&& A[i][k] != MAX&&A[j][k] != MAX)
				{
					A[i][j] = (sqrt(A[i][k]) + sqrt(A[k][j]))*(sqrt(A[i][k]) + sqrt(A[k][j]));
					path[i][j] = k;
				}
	}
	for (int i = 0; i < MAXV; i++)
	{
		for (int j = 0; j < MAXV; j++)
		{
			if (path[i][j] != -1 && i < j&&i == 0) {
				printf("点%d到点%d要经过点%d\n", i + 1, j + 1, path[i][j] + 1);
				A[0][12];
			}
		}
	}
}
int main()
{
	int a[MAXV][MAXV];
	int path[MAXV][MAXV];
	int A[MAXV][MAXV] = {
{ 0	  ,  725, 2125, MAX , MAX , MAX , 1850, MAX ,  925, MAX , 5650, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ 725 ,    0,  800, 2000, 2500, 4100, 3125, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ 2125,  800,    0, 2000, MAX , MAX , MAX , MAX , MAX , MAX , 6725, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , 4625,18925, MAX , MAX , MAX ,15925, MAX , MAX , MAX , MAX },
{ MAX , 2000, 2000,    0, 2500, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,12125, 3874, MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , 2500, MAX , 2500,    0, 1600, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , 3700, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , 4100, MAX , MAX , 1600,    0,  725, MAX , MAX , MAX , MAX , MAX , 4850,17450, MAX , MAX , MAX , 6100, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ 1850, 3125, MAX , MAX , MAX ,  725,    0, 8000, 1625, MAX , MAX , MAX , 5525, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , 8000,    0, 8125, 4625, MAX , 5525, 4825, MAX , MAX , MAX ,19125, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ 925 , MAX , MAX , MAX , MAX , MAX , 1625, 8125,    0, 2650, 5525, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , 4625, 2650,    0, 6925, MAX , MAX , MAX , MAX , MAX ,19400, MAX , 8000, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ 5650, MAX , 6725, MAX , MAX , MAX , MAX , MAX , 5525, 6925,    0, MAX , MAX , MAX , MAX , MAX , MAX , MAX ,13325, 6425, 4900, MAX , MAX , MAX , MAX , MAX ,11925, MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , 5525, MAX , MAX , MAX ,    0, 8200, MAX ,17125,34250,25250, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , 4850, 5525, 4825, MAX , MAX , MAX , 8200,    0, 8100, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX ,17450, MAX , MAX , MAX , MAX , MAX , MAX , 8100,    0, MAX , MAX , MAX ,15725, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,18125, MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,17125, MAX , MAX ,    0, 2725,37925, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,34250, MAX , MAX , 2725,    0,13700, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX ,19125, MAX ,19400, MAX ,25250, MAX , MAX ,37925,13700,    0, MAX , 9000, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , 3700, 6100, MAX , MAX , MAX , MAX , MAX , MAX , MAX ,15725, MAX , MAX , MAX ,    0, MAX , MAX , MAX , MAX , 7354, MAX , MAX , MAX , MAX , MAX ,36625, MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , 8000,13325, MAX , MAX , MAX , MAX , MAX , 9000, MAX ,    0, MAX , MAX , MAX , MAX , MAX , MAX , MAX ,11300, MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , 6425, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,    0,10625, MAX , MAX , MAX , MAX , MAX , 1850,10789, MAX , MAX },
{ MAX , MAX , 4625, MAX , MAX , MAX , MAX , MAX , MAX , MAX , 4900, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,10625,    0, MAX , MAX , MAX , MAX , 7250, MAX , MAX , MAX , MAX },
{ MAX , MAX ,18925,12125, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,    0, 6089, 6500,15850,13850, MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , 3874, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , 7354, MAX , MAX , MAX , 6089,    0,18769, MAX , MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , 6500,18769,    0, 6050, MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,15850, MAX , 6050,    0, MAX , MAX , MAX , MAX , MAX },
{ MAX , MAX ,15925, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , 7250,13850, MAX , MAX , MAX ,    0, MAX , MAX , MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,11925, MAX , MAX , MAX , MAX , MAX , MAX , MAX ,11300, 1850, MAX , MAX , MAX , MAX , MAX , MAX ,    0,10829, MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,10789, MAX , MAX , MAX , MAX , MAX , MAX ,10829,    0, MAX , MAX },
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,18125, MAX , MAX , MAX ,36625, MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX ,    0, 4825},
{ MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , MAX , 4825,    0},
	};
	Floyd(path, a, A);
	system("pause");
    return 0;
}

