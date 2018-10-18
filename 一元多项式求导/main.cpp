// text1.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
int main() {
	int a, b;
	char c = ' ';
	scanf_s("%d %d", &a, &b);
	scanf_s("%c", &c);
	int flag = 0, f = 0;
	if (a != 0 && b != 0) {
		f = 2;
		printf("%d %d", a*b, b - 1);
	}
	else if (a == 0 && b == 0) {
		if (c != ' ') {
			f = 2;
			printf("0 0");
		}

	}
	else {
		flag = 1;
	}
	while (c == ' ')
	{
		scanf_s(" %d %d", &a, &b);
		scanf_s("%c", &c);
		if (c == ' ') {  //后面还有数
			if (a != 0 && b != 0) {
				if (flag ==1) {
					f = 2;
					printf("%d %d", a*b, b - 1);
				}
				else {
					f = 2;
					printf(" %d %d", a*b, b - 1);
				}
			}
			else if (a == 0 && b == 0 && f != 2) {
				if (flag == 0) {
					f = 2;
					printf("0 0");
				}
				else {
					f = 2;
					printf(" 0 0");
				}
			}

		}
		else if (c != ' ') {
			if (a != 0 && b != 0) {
				if (f == 0) {
					f = 2;
					printf("%d %d", a*b, b - 1);
				}
				else {
					f = 2;
					printf(" %d %d", a*b, b - 1);
				}
			}
			else if (a == 0 && b == 0)
			{
				if (f == 0) {
					if (flag == 1) {
						f = 2;
						printf("0 0");
					}
					else {
						f = 2;
						printf(" 0 0");
					}
				}
				break;
			}
		}

	}
	if (f == 0) {
		printf("0 0");
	}
		system("pause");
	
	return 0;
}
