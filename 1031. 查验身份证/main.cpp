// 1031. 查验身份证.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main() {
	char a[20];
	int nx;
	cin >> nx;
	int number = 0;
	int b[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	for (int j = 0; j<nx; j++) {
		int n = 0;
		int flag = 0;
		cin >> a;
		for (int i = 0; i<17; i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
				n += b[i] * (a[i] - '0');
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			n %= 11;
			switch (n) {
			case 0:if (a[17] == '1') { number++; }
				   else flag = 1; break;
			case 1:if (a[17] == '0') { number++; }
				   else flag = 1; break;
			case 2:if (a[17] == 'X') { number++; }
				   else flag = 1; break;
			case 3:if (a[17] == '9') { number++; }
				   else flag = 1; break;
			case 4:if (a[17] == '8') { number++; }
				   else flag = 1; break;
			case 5:if (a[17] == '7') { number++; }
				   else flag = 1; break;
			case 6:if (a[17] == '6') { number++; }
				   else flag = 1; break;
			case 7:if (a[17] == '5') { number++; }
				   else flag = 1; break;
			case 8:if (a[17] == '4') { number++; }
				   else flag = 1; break;
			case 9:if (a[17] == '3') { number++; }
				   else flag = 1; break;
			case 10:if (a[17] == '2') { number++; }
					else flag = 1; break;
			}
		}
		if (flag == 1) {
			cout << a << endl;
		}
	}
	if (number == nx)printf("All passed");
	return 0;
}

