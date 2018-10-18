// 1019. 数字黑洞.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;

void Max(int a,int *d) {
	int b[4],c[2];
	for (int i = 0; i < 4; i++)
	{
		b[i] = a % 10;
		a = a / 10;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3-i; j++)
		{
			if (b[j+1] > b[j]) {
				int e = b[j+1];
				b[j+1] = b[j];
				b[j] = e;
			}
		}
	}
	int k = 0, l = 0;
	for (int z = 3; z >=0; z--)
	{
		k = k * 10 + b[z];
	}
	for (int m = 0; m < 4; m++)
	{
		l = l * 10 + b[m];
	}
	d[0] = l;
	d[1] = k;
}


int main()
{
	int n1, n2 = 0,n3=0;
	int b[2] = { 0 };
	cin >> n1;
	while (1)
	{
		if (n3 != 0)n1 = n3;
		Max(n1, b);
		n2 = b[0];	//小的
		n1= b[1];
		
		if (n1 == n2) {
			cout.width(4); cout.fill('0');
			cout << setw(4) << setfill('0') << n1 << " - " << setw(4) << setfill('0') << n2 << " = " << "0000";
			break;
		}
		else
		{
			n3 = n2 - n1;
			
			cout << setw(4) << setfill('0') << n2 << " - " << setw(4) << setfill('0') << n1 << " = " << setw(4) << setfill('0') << n2 - n1<<endl;
			if (n2 - n1 == 6174) {
				break;
			}
			

		}

	}

	system("pause");
    return 0;
}

