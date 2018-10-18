// C++text_four.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;


class A {
public:
	int m;
	A operator+(A a) { A b; b.m = a.m + this->m; return b; }	//类中定义的运算符参数比类外要少一个，默认自身是一个参数
	A operator!() { A b; b.m = this->m*-1; return b; }	//前置运算符
	A operator++(int) { A b; b.m = this->m*-1; return b; }	//后置运算符	（）无参数时括号里加个int
};

class B {

};


//运算符重载		参数必须是自定义类型或枚举		其中 .	.*	?:	::	sizeof 不可以重载
//A operator+(A a, A b) {
//	cout << "aaa" << endl;
//	return a;
//}

A & operator>(A &a, A &b) {
	if (a.m > b.m) {
		return a;
	}
	else {
		return b;
	}
}


int main()
{
	A a, b;
	a.m = 1;
	b.m = 2;
	(a > b).m = 3;
	a = a + b;
	cout << a.m<<endl;
	cout << b.m<<endl;
	a = !a;
	b = !b;
	cout << a.m << b.m<<endl;

	a = a++;
	b = b++;
	cout << a.m << b.m << endl;
	system("pause");
    return 0;
}

