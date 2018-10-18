// text.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
inline int A(int a,int b) {
	a = 1; b = 2;
	return a + b;
}

template<typename T> T S(T X) {
	return X * X;
}

void strcpy4(char *p1, char *p2)
{
	while (*p2)  *p1++ = *p2++;
}

int main()
{

	char a[] = "1as23";
	char b[10];
	strcpy4(b, a);
	cout << b;
	//int a = 0, b = 1;
	//int k = A(a, b);
	//printf("%d %d %d %d",a,b ,k,S(2));
	//cout<< S(2) << endl;
	PlaySound("a.mp3", NULL, SND_LOOP);
	system("pause");
    return 0;
}

