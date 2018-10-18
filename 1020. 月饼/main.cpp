// 1020. 月饼.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

typedef struct node {
	double ns;
	double gra;
	double n_g;
}Node;

//简单排序
void paixu(int *a,Node *q,int length) {
	int c[1001] = {0};
	double  max = 0;
	for (int i = 1; i <=length; i++)
	{
		max = 0;
		for (int j= 1; j <=length; j++)
		{
			if (q[j].n_g > max&&c[j]==0) {
				a[i] = j;
				max = q[j].n_g;
			}
		}
		c[a[i]] = 1;
	}
}


int main()
{
	int n, number;	//种类和数量
	cin >> n >> number;
	Node a[1001];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].ns;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].gra;
		a[i].n_g =  a[i].gra/ a[i].ns ;
	}
	int b[1001];
	paixu(b, a, n);
	int k = 1;
	double money = 0;
	while (number>0)
	{
		if (a[b[k]].ns <= number) {
			number = number - a[b[k]].ns;
			money = a[b[k]].gra + money;
			k++;	//判断总需求小于总供给
			if (k > n) {
				break;
			}
		}
		else {
			money = a[b[k]].n_g*number + money;
			number = 0;
		}
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << (float)money << endl; 
	system("pause");

    return 0;
}

