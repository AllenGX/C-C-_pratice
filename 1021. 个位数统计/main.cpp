// 1021. 个位数统计.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	char a[1001];
	cin >> a;
	int b[10] = {0};
	for (int i = 0; a[i]!='\0'; i++)
	{
		switch (a[i])
		{
		case '0':b[0]++; break;
		case '1':b[1]++; break;
		case '2':b[2]++; break;
		case '3':b[3]++; break;
		case '4':b[4]++; break;
		case '5':b[5]++; break;
		case '6':b[6]++; break;
		case '7':b[7]++; break;
		case '8':b[8]++; break;
		case '9':b[9]++; break;
		default:
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (b[i] != 0) {
			cout << i << ":" << b[i] << endl;
		}
	}
	system("pause");
    return 0;
}

