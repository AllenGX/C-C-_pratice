// 1036 跟奥巴马一起编程(15).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	char c;
	cin >> c;
	int m;
	if (n % 2 == 0)m = n / 2 - 2;
	else m = n / 2 - 1;
	for (int  i = 0; i < n; i++)
	{
		cout << c;
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0 || j == n - 1)cout << c;
			else cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << c;
	}
	system("pause");
    return 0;
}

