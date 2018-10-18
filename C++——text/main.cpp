
// C++——text.cpp: 定义控制台应用程序的入口点。
//
#include"text_1.h"
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

class Preson
{
public:
	Preson(const Preson &a);		//复制构造函数		
	//注:没有复制构造函数时系统会自动生成，但是生成的时浅复制，如果复制中存在指针建议自己定义一个深复制

	explicit Preson(string name, int age=20);//构造函数(不支持隐式类型转化)
	Preson();//默认构造函数支持隐式转换
	void toString() const;	//加	const	表示该方法不改变其中变量的值

	~Preson();	//析构函数，一般用来在对象被释放之后，释放其中的成员

private:
	int age;
	string name;
};//注意要有分号					初始化方法一				初始化方法二
Preson::Preson(const string name, int age) :name(name), age(age) {this->name = name; this->age = age; }	//初始化的两种形式
Preson::Preson():name("小红"),age(18){}
Preson::Preson(const Preson &a) : name(a.name), age(a.age){}	//复制构造函数实现
Preson::~Preson() {/*	释放指针对象	*/  }		//在对象被释放之前调用

void Preson::toString() const { cout << "名字:"<<name <<"   年龄:"<< age << endl; }

class Teacher {
public:
	Teacher(const string name, int age);

private:
	Preson a;
};

					//嵌套类的初始化是能是这样
Teacher::Teacher(const string name, int age) :a(name, age) { /*a(name, age);(X) a.age=age;a.name=name;(X)*/ }	
						//大括号中无法进行初始化，因为a成员变量是私有不能直接访问	
						//同时a的构造方法也不能主动调用

class  Data
{
public:
	int number;
	void tostring();


private:
	
};
void Data::tostring() { cout << "Data"<<endl; }


int main()
{
	string s = "小刚";
	Preson a("李明", 13);
	a.toString();

	a = Preson(s);	
	a.toString();

	Data c,*cc;
	c.number = 100;
	cc = &c;
	int Data::*q = &Data::number;	//指向成员的指针	（并不是类对象）
	
	//使用	(四者等效)
	int nnnn = c.number;
	int nn = cc->number;
	int nnnnn = c.*q;
	int nnn = cc->*q;
	cout << "nn=" << nn << "  nnn=" << nnn << "  nnnnn=" << nnnnn << "  nnnn=" << nnnn<<endl;
	
	void (Data::*x)();	//声明x是一个返回值为void 且无参数的函数指针
	x = &Data::tostring;	//x指向tostring函数

	//使用	(四者等效)
	c.tostring();
	cc->tostring();
	(c.*x)();
	(cc->*x)();

	
	void (Data::*p)() = &Data::tostring;	//指向成员方法的指针	（并不是类方法）



	

	typedef void (Preson::*pp)()const;	//给	void (Preson::*qq)() const	重命名为*pp

	pp ps = &Preson::toString;

	

	void (Preson::*qq)() const = &Preson::toString;



	//Preson b = s;		//隐式类型转换(如果构造方法加上了 explicit关键字，则不能这一使用)
	//b.toString();

	Preson b = a;	//相当于调用了复制构造函数
	b.toString();


	//sb.tostring(10,20);
	//B sb(10, 20);
	//sb.tostring(20, 30);


	system("pause");
    return 0;
}

