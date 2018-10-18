// 1033. 旧键盘打字.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;


int main() {
	int a[67] = { 0 };	//0~25 26~51 52~61 62~66
						//a~z	A~Z	 0~9	_ , . - +
	char c[100001];
	char b[100001];
	cin >> c;
	cin >> b;
	int i = 0;
	while (c[i]!='\0')
	{
		if (c[i] == '_')a[62] = 1;
		if (c[i] == ',')a[63] = 1;
		if (c[i] == '.')a[64] = 1;
		if (c[i] == '-')a[65] =1;
		if (c[i] == '+') {
			a[66] = 1; for (int j = 26; j < 52; j++)
			{
				a[j] = 1;
			}
		}
		if (c[i] >= 'A'&&c[i] <= 'Z') { a[c[i] - 'A' + 26] = 1; a[c[i] - 'A'] = 1; }
		if (c[i] >= 'a'&&c[i] <= 'z') { a[c[i] - 'a'] = 1; a[c[i] - 'a' + 26] = 1; }
		if (c[i] >= '0'&&c[i] <= '9')a[c[i] - '0'+52] = 1;
		i++;
	}
	i = 0;
	while (b[i]!='\0')
	{
		if (b[i] == '_'&&a[62] != 1)cout<<b[i];
		if (b[i] == ','&&a[63] != 1)cout << b[i];
		if (b[i] == '.'&&a[64] != 1)cout << b[i];
		if (b[i] == '-'&&a[65] != 1)cout << b[i];
		if (b[i] == '+'&&a[66] != 1)cout << b[i];
		if (b[i] >= 'A'&&b[i] <= 'Z'&&a[b[i] - 'A' + 26] != 1 )cout << b[i];
		if (b[i] >= 'a'&&b[i] <= 'z'&&a[b[i] - 'a']!=1)cout << b[i];
		if (b[i] >= '0'&&b[i] <= '9'&&a[b[i] - '0'+52] != 1 )cout << b[i];
		i++;
	}

	system("pause");
	return 0;
}

