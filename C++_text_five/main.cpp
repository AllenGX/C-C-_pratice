// C++_text_five.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class A {
public:
	A(int a, int b) :a(a), b(b) {};
	friend ostream& operator<<(ostream &os, A aa);		//必须设置为友元函数
	friend istream& operator>>(istream&is, A &aa);	//因为可以作为左值所以返回值是引用类型

	//类型转换必须为该类的public类型函数
	operator double();
private:
	int a;
	int b;
};

//重载流运算符		输入输出
ostream& operator<<(ostream &os, A aa) {
	os << aa.a<<endl << aa.b<<endl;
	return os;
}

istream& operator>>(istream &is, A &aa) {
	is >> aa.a >> aa.b;
	return is;
}



//重载类型转换
A::operator double() {
	return (double)this->a / this->b;
}






int main()
{

	A a(1, 2);
	A b(1, 2);
	//cin >> a;
	//cout << a;
	cout << double(a);
	system("pause");
    return 0;
}

