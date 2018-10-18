// 1014. 福尔摩斯的约会.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[100];
	char b[100];
	char c[100];
	char d[100];
	scanf_s("%s", a, 100);
	scanf_s("%s", b, 100);
	scanf_s("%s", c, 100);
	scanf_s("%s", d, 100);
	
	
	int flag = 0;
	for (int i = 0; a[i]!='\0'&&b[i] != '\0'; i++)
	{
		if (a[i] == b[i]) {
			if (flag == 1) {
				if (a[i] >= 48 && a[i] <= 57) {
					printf("0%d:", a[i] - 48);
					break;
				}
				else if (a[i] >= 'A' && a[i] <= 'N') {
					printf("%d:", a[i] - 55);
					break;
				}
			}
			if (a[i] >= 65 && a[i] <= 90) {
				if ((a[i] - 65) == 0 && flag == 0) {
					printf("MON ");
					flag = 1;
				}
				else if ((a[i] - 65) == 1 && flag == 0) {
					flag = 1;
					printf("TUE ");
				}
				else if ((a[i] - 65) == 2 && flag == 0) {
					flag = 1;
					printf("WED ");
				}
				else if ((a[i] - 65) == 3 && flag == 0) {
					flag = 1;
					printf("THU ");
				}
				else if ((a[i] - 65) == 4 && flag == 0) {
					flag = 1;
					printf("FRI ");
				}
				else if ((a[i] - 65) == 5 && flag == 0) {
					flag = 1;
					printf("SAT ");
				}
				else if ((a[i] - 65) == 6 && flag == 0) {
					flag = 1;
					printf("SUN ");
				}
			}
		}
	}
	for (int i = 0; c[i] != '\0'&&d[i] != '\0'; i++)
	{
		if (c[i] == d[i]) {
			if (c[i] >= 97 && c[i] <= 122|| c[i] >= 65 && c[i] <= 90) {
				if (i > 9) {
					printf("%d", i);
					break;
				}
				else {
					printf("0%d", i);
					break;
				}
			}
		}
	}
	system("pause");
	return 0;
}

