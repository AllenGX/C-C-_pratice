// 10-排序5 PAT Judge（25 分）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	//int stn;	//学生号
	int grade[6];	//成绩
	int pref;		//满分题目数
	int num;		//总分
}Nodes;


int PanDuan(int *a, Nodes *N, int center, int right) {		//right》center返回1
	if (N[a[right]].num > N[a[center]].num || N[a[right]].num == N[a[center]].num&&N[a[right]].pref > N[a[center]].pref || N[a[right]].num == N[a[center]].num&&N[a[right]].pref == N[a[center]].pref&&right < center) {
		return 1;
	}
	return 0;
}


//归并排序

void sort1(int *n, int left, int right, int *b, Nodes *N) {
	int L = left;
	int C = (left + right) / 2;
	int K = left;
	int R = C + 1;
	while (L!=C+1&&R!=right+1)
	{
		if (PanDuan(n, N, L, R)) {	//R>L
			b[K++] = n[R++];
		}
		else {
			b[K++] = n[L++];
		}
	}
	while (L != C + 1)
	{
		b[K++] = n[L++];
	}
	while (R != right + 1)
	{
		b[K++] = n[R++];
	}
	for (int i = left; i < right+1; i++)
	{
		n[i] = b[i];
	}
}

void apatr(int *n, int left, int right, int *b, Nodes *N) {
	int center = (left + right) / 2;
	if (right > left) {
		apatr(n, left, center, b, N);
		apatr(n, center+1, right, b, N);
		sort1(n, left, right, b, N);
	}
}

void sort(int *n, int left, int right, Nodes *N) {
	int b[10001];
	apatr(n, left, right, b, N);
}

int PanDuan1(int *a, Nodes *N, int center, int right) {		//right》=center返回1
	if (N[a[right]].num > N[a[center]].num || N[a[right]].num == N[a[center]].num&&N[a[right]].pref > N[a[center]].pref || N[a[right]].num == N[a[center]].num&&N[a[right]].pref == N[a[center]].pref&&right <= center) {
		return 1;
	}
	return 0;
}


int main()
{
	int b[6] = { 0 };	//各科满分数
	int stns, gs, ps;	//学生数、题目数、提交数
	scanf_s("%d %d %d", &stns, &gs, &ps);
	for (int i = 1; i <= gs; i++)
	{
		scanf_s("%d", &b[i]);
		//b[i] = 20;
	}
	int snumber, gn, grades;	//学生号，题目号，成绩
	Nodes N[10001];

	for (int i = 1; i <= stns; i++)	//初始化
	{
		for (int j = 1; j <= gs; j++)
		{
			N[i].grade[j] = -2;
		}
		N[i].pref = 0;
		N[i].num = 0;
	}

	for (int i = 1; i <=ps; i++)
	{
		scanf_s("%d %d %d", &snumber, &gn, &grades);
		if (grades>N[snumber].grade[gn]) {
			N[snumber].grade[gn] = grades;
			if (grades == b[gn])N[snumber].pref++;
		}
	}

	for (int i = 1; i <= stns; i++)
	{
		int flag= 0;
		for (int j = 1; j <= gs; j++)
		{
			if (N[i].grade[j]>=0) {
				N[i].num += N[i].grade[j];
				flag = 1;		//有提交通过的题（0也算）
			}
		}
		if (flag == 0)N[i].num = -1;	//-1表示没提交，或编译没通过
	}

	int n[100001];	//记录排序序号
	int kk = 1;
	for (int i = 1; i <=stns; i++)
	{
		if (N[i].num >= 0) {
			n[kk++] = i;
		}
	}
	Qsort(n, 1, kk-1, N);


	int index = 1;
	for (int i = 1; i < kk; i++)
	{
		printf("%d %05d %d",index,n[i],N[n[i]].num);
		if (n[i + 1] >0&&n[i + 1] <=stns&&N[n[i]].num!= N[n[i+1]].num) {
			index = i+1;
		}
		for (int j = 1; j <=gs; j++)
		{
			if (N[n[i]].grade[j] ==-2) {
				printf(" -");
			}
			else if (N[n[i]].grade[j] == -1) {
				printf(" 0");
			}
			else {
				printf(" %d", N[n[i]].grade[j]);
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


