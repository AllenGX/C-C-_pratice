// C++text_one.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;



class A {
public:
	void tostring(int a, int b) const;	//常函数
	A(int a, int b);
	mutable int a;
	const int b;		//常数据
};

void A::tostring(int a, int b) const { cout << a << b << endl; }
A::A(int a, int b) :a(a), b(b) {}


class B {
public:
	void tostring(int a, int b, A &aa);
	void tostring(int a, int b);
	B(int a, int b);
private:
	int a;
	int b;
};


void B::tostring(int a, int b,A &aa) { cout << a << b << endl; }
void B::tostring(int a, int b) { cout << a << b << endl; }
B::B(int a, int b) : a(a), b(b) {}

int main()
{
	int ss = 100;	//非常数据
	const int sss = 1;	//常数据
	
	A as(111, 222);
	const A aa(10, 20);	//常对象
	B bb(1, 2);
	const B sb(11, 22);


	aa.a;	//常对象数据

	cout << aa.a<<endl;

	//bb.tostring(1, 2,aa);		//非常成员函数(不能引用常对象)
	//sb.tostring();		//常对象不允许访问非常函数
	bb.tostring(sss, sss);		//非常函数允许访问常数据


	/*								const修饰的函数			无const修饰的函数
			const 修饰的数据		  可用，不可改				可用，不可改
		  无const 修饰的数据		  可用，不可改				可用，可改
	   const修饰的对象的数据		  可用，不可改				不可用，不可改
	
	*/



	system("pause");
    return 0;
}

