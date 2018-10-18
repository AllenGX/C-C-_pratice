// 1029. 旧键盘.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	char a[100];
	char b[100];
	cin >> a >> b;
	int c[63] = { 0 };		//		0~25	26~51	52	53~62
	int m = 0;				//		A~Z		a~z		_	0~9
	for (int i = 0,j=0; i < sizeof(a)/sizeof(char)&&a[i]!='\0';)
	{
		if (a[i] != b[j]) {
			if ('A' <= a[i] && a[i] <= 'Z') {
				m = a[i] - 'A';
			}
			else if ('a' <= a[i] && a[i] <= 'z') {
				m = a[i] - 'a';
				a[i] = a[i] - 'a' + 'A';
			}
			else if (a[i]=='_') {
				m = 52;
				
			}
			else {
				m = a[i] - '0' + 53;
			}
			if (c[m] != 1) {
				cout << a[i];
				c[m] = 1;
			}
			i++;
		}
		else {
			i++;
			j++;
		}
	}

	system("pause");
    return 0;
}

