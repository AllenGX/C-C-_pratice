// C++text_three.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class A {
public:
	void tostring() { cout << "A"<<endl; }
	A() { cout << "a" << endl; }
};

class B :virtual public A{
public :
	virtual void tostring() { cout << "B"<<endl; }	//父类的tostring方法是虚函数，那么继承他的子类的同名方法也会默认为虚函数  例如  D  的tostring
	B() { cout << "b" << endl; }
};

class C :virtual public A {
public:
	void tostring() { cout << "C"<<endl; }
	C() { cout << "c" << endl; }
};

class D : public C,  public B {		//此时在D中存在两个A类的副本
public:
	void tostring() { cout << "D"<<endl; }
	D() { cout << "d" << endl; }																		//  abstract class
//	virtual void string() = 0;	//定义纯虚构函数		类似java的抽象方法	//且只能作为基类	有纯虚函数的类是抽象类，不能有实例
};



//存在多态的情况下，尽量让析构函数命名为虚函数
//基类的析构函数是虚函数那么		子类的虚构函数都默认为虚函数


int main()
{	
	D d;		//	a重复创建两次	解决办法：在每个派生类前面加上virtual	表面其是虚基类
	d.B::A::tostring();	//		
	d.C::A::tostring();	//
	d.B::tostring();
	d.C::tostring();
	d.tostring();

	cout << "____________________________" << endl;

	C c;
	C *p;
	cout << "____________________________" << endl;
	cout << "静态联边:" << endl;		//父类和子类中有同名方法时，方法调用由声明的接受对象决定	既 C类型
	p = &c;
	p->tostring();
	p = &d;
	p->tostring();

	cout << "____________________________" << endl;
	B b;
	B *q;
	cout << "____________________________" << endl;
	cout << "动态联边:" << endl;		//父类和子类中有同名方法时，在父类方法前加上 virtual  时，方法的调用由变量自己的类型决定
	q = &b;																						//既	*q指向的对象决定	b 或 d	
	q->tostring();
	q = &d;
	q->tostring();


	system("pause");
    return 0;
}

