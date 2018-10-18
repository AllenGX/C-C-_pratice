// 1018. 锤子剪刀布.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


//		石头C	剪刀J	布B
char Max(int a, int b, int c) {
	if (a >= b) {
		if (a > c) {
			return 'C';
		}
		return 'B';
	}
	else {
		if (b > c) {
			return 'J';
		}
		return 'B';
	}
}


int main()
{
	int B=0, C=0, J = 0;
	int B1 = 0, C1 = 0, J1 = 0;
	int n;
	cin >> n;
	char jia, yi;
	int jiasheng = 0, jiafu = 0, jiaping = 0, yisheng = 0, yifu = 0, yiping = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> jia >> yi;
		if (jia == 'B'&&yi == 'J') {
			J1++;
			yisheng++;
			jiafu++;
		}
		else if (jia == 'J'&&yi == 'B') {
			J++;
			jiasheng++;
			yifu++;
		}
		else if (jia == 'B'&&yi == 'C') {
			B++;
			jiasheng++;
			yifu++;
		}
		else if (jia == 'C'&&yi == 'B') {
			B1++;
			yisheng++;
			jiafu++;
		}
		else if (jia == 'J'&&yi == 'C') {
			yisheng++;
			jiafu++;
			C1++;
		}
		else if (jia == 'C'&&yi == 'J') {
			yifu++;
			jiasheng++;
			C++;
		}
		else {
			jiaping++;
			yiping++ ;
		}
		
	}
	//cout << jiasheng << " " << jiaping << " " << jiafu << endl << yisheng << " " << yiping << " " << yifu << endl << Max(C, J, B) << " " << Max(C1, J1, B1);

	printf("%c",Max(1,2,3));
	system("pause");
    return 0;
}

