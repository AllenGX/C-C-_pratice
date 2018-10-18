// 10-排序6 Sort with Swap(0, i).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int a[100000];
	int b[100000] = { 0 };
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	int cnt = 0;	//记录环数
	int rp = 0;		//记录步数
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] == i) {
			b[i] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] != i && b[i] != 1) {
			cnt++;
			int qidian = a[i];
			do
			{
				rp += 1;
				b[a[i]] = 1;
				i = a[i];
			} while (a[i] != qidian);
		}
	}


	if (a[0] != 0) {
		if (cnt == 0) {
			printf("0");
		}else{
			printf("%d", cnt - 2 + rp);
		}
		
	}
	else {
		if (cnt == 0) {
			printf("0");
		}
		else {
			printf("%d",  cnt + rp );
		}
	}
	
	system("pause");
    return 0;

}

