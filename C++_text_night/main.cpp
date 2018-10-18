// C++_text_night.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<list>	//链表
#include<queue>	//队列
#include<stack>	//栈
#include<vector>	//向量
using namespace std;

int main()
{
	list<char> Mylist;	//链表
	Mylist.push_back('a');
	Mylist.push_front('b');

	//生成迭代器
	list<char>::iterator Myiterator;
	Myiterator = find(Mylist.begin(), Mylist.end(), 'a');	//用迭代器查找元素，返回元素位置
	if (Myiterator == Mylist.end()) {
		cout << "没找到";
	}else{
		cout << *Myiterator;
		
	}
	

	system("pause");
    return 0;
}

