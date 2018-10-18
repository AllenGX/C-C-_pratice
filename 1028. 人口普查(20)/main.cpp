// 1028. 人口普查(20).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void strcpy_sa(char *a, const char *b) {
	int i;
	for (i = 0; i < sizeof(b)/sizeof(char)&&b[i]!='\0'; i++)
	{
		a[i] = b[i];
	}
	a[i] = '\0';
}


int main()
{
	int y, m, d,miny=100000000,maxy=-1,minm=13,maxm=-1,mind=40,maxd=-1;
	char a[100];
	char old[100], yang[100];
	int n;
	cin >> n;
	int error=0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		scanf_s("%d/%d/%d", &y, &m, &d);
		if ((1814<y&&y<2014)||((y == 1814 && m > 9) || (y == 2014 && m < 9))|| ((y == 1814 && m == 9 && d >= 6) || (y == 2014 && m == 9 && d <= 6))) {
			if (y > maxy || (y == maxy && m > maxm )||( y == maxy && m == maxm && d > maxd)) {
				strcpy_sa(old, a);
				maxd = d; maxm = m; maxy = y;
			}
			if ((y < miny )||( y == miny && m < minm )||( y == miny && m == minm && d < mind)) {
				strcpy_sa(yang, a);
				mind = d; minm = m; miny = y;
			}
			error++;
		}
	
	}
	if (error==0) {
		cout << error;
	}
	else {
		cout << error << " " << yang << " " << old;
	}

	system("pause");
    return 0;
}

