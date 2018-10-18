// 1026. 程序运行时间.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;


int main()
{
	double n1, n2;
	cin >> n1 >> n2;
	double time = (n2 - n1) / 100;

	int hh, mm, sss;
	hh = time / 3600;
	time = time - hh * 3600;
	mm = time / 60;
	sss = time - mm * 60+0.5;
	cout<< setfill('0') << setw(2) << hh << ":" << setw(2) << setfill('0') << mm << ":" << setw(2) << setfill('0') << sss;
	system("pause");
    return 0;
}

