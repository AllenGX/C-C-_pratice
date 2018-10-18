// C++_text_six.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"text.h"
using namespace std;
template <typename T>		//声明一个泛型		typename  和   class  都是可以的							
							//template <class T>
class Point {
private:
	T a, b;
public:
	Point(T a, T b) :a(a), b(b) {}
	void Exchange();
};

template <typename T>		//注此处也要声明
void Point<T>::Exchange() {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T = int, int n = 100>
class Points {
private:
	int n;
	T a, b;
public:
	Points(T a, T b) :a(a), b(b) {}
};



template <class T>
class Array {
public:
	Array(int c) { arr = new T[c]; }	//构造函数
	T& operator[](int i); //{ return arr[i]; }	//运算符重载
private:
	T * arr;
};

template <class T>		//两种都可以
T& Array<T>::operator[](int i) { return arr[i]; }


int main()
{

	Array<int> arr(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		cout << arr[i];
	}

	extern int a;		//直接引用text.cpp中的a  不用包含头文件
	cout << a;
	
	extern struct pos abc;		//包含头文件后，可以直接使用其cpp文件中定义的对象
	abc.x = 100;			//包含text.h文件		//在text.cpp中定义了abc
	abc.y = 100;			//在这可以直接使用
	cout << abc.x << abc.y;

	Point<int> s(1, 2);
	Points<int, 10> d(3, 4);
	Points<int> dd(3, 4);
	Points<> ddd(3, 4);
	s.Exchange();
	system("pause");
    return 0;
}

