// 1030. 完美数列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//合并
void sorts(int *a, int left, int right, int *b) {
	int L = left;
	int C = (left + right) / 2;
	int R = C+1;
	int k = left;
	while (L!=C+1&&R!=right+1)
	{
		if (a[L] < a[R]) {
			b[k++] = a[L++];
		}
		else {
			b[k++] = a[R++];
		}
	}
	while (L!=C+1)
	{
		b[k++] = a[L++];
	}
	while (R!=right+1)
	{
		b[k++] = a[R++];
	}
	for (int i = left; i <= right; i++)
	{
		a[i] = b[i];
	}
}

void apart(int *a, int left, int right, int *b) {
	int C = (left + right) / 2;
	if (left < right) {
		apart(a, left, C, b);
		apart(a, C+1, right, b);
		sorts(a, left, right, b);
	}
}


void Sort(int *a, int length) {
	int *b = (int *)malloc(sizeof(int)*length);
	apart(a, 0, length - 1, b);
}


int main()
{
	int n,p;
	cin >> n>>p;
	int a[100000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	Sort(a, n);
	int temp, cnt = 0, max = 0,number=0;
	for (int i = 0; i < n&&(n-i)>max; i++)
	{
		temp = a[i];
		for (int j = cnt; j < n; )
		{
			if (a[j]%p==0&&temp>=a[j]/p|| a[j] % p != 0 && temp > a[j] / p) {
				j++;
				cnt++;
				number++;
			}
			else {
				break;
			}
		}
		if (number > max) {
			max = number;
		}
		number--;
	}
	cout << max;
	system("pause");
    return 0;
}

