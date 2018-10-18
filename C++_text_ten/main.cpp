// C++_text_ten.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//命名空间的使用
namespace A {
	int i;
	int j;
	int fun(int i, int j);		//定义
}


//两者取并集
//命名空间可以重复
namespace A {
	int fun(int i, int j) { return i*j; }	//实现
}


using namespace A;	//使用A这个命名空间


namespace A {
	namespace B {	//嵌套命名空间
		int i=0;
		int j=0;
	}


}



using namespace A::B;	//使用B命名空间

namespace AA = A;	//	把命名空间A另命名为AA


namespace {		//匿名命名空间	只能在本文件中多次调用，不可跨文件
	int i;
	int j;
}


int main()
{

	cout<<fun(1, 2)<<endl;	//使用命名空间：：调用
	cout <<A::fun(1, 2)<<endl;
	cout << A::B::i<<endl;
	cout<<
	system("pause");
    return 0;
}

