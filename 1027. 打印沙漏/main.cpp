// 1027. 打印沙漏.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;

int main()
{

	int number;
	char s;
	cin >> number;
	cin >> s;
	int yu=0;
	int ceng = sqrt((number + 1) / 2) - 1;
	yu = number - (ceng + 1)*(ceng + 1) * 2 + 1;
	int left = 0;
	int Long = 2 * ceng + 1;
	number = Long;
	for (int i = 0; i <= ceng; i++)
	{
		for (int j = 0; j < left; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < number; j++)
		{
			cout << s;
		}
		cout <<endl;
		number -= 2;
		left++;
	}
	left--; number += 2;
	for (int i = 0; i < ceng; i++)
	{
		number += 2;
		left--;
		for (int j = 0; j < left; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < number; j++)
		{
			cout << s;
		}
		cout << endl;
	}
	cout << yu;

	system("pause");
    return 0;
}

