// C++_text_seven.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<sstream>
using namespace std;
int main()
{

	//字符串流对象的使用		
	//输出
	ostringstream oss;		// oss对象可以将各种类型转化为string类型 转化用<<符号
	oss << 1.234;
	oss << "rerwer3sdf";
	oss << 3.548964;
	cout << oss.str()<<endl;
	oss.str("");		//清空缓存区
	cout << oss.str() << endl;
	oss << 100;
	cout << oss.str()<<endl;



	//输入
	int a=0;
	string str1;
	string input = "abc de ferew 3jkf s3wed";
	istringstream iss(input);	//输入对象
	iss.str(input);		//两者等效		//这种方法末尾会加上空格
	//以空格为分隔，从input字符串中提取数据
	while (iss>>str1)
	{
		cout << str1 << " " << endl;
	}


	//输出&&输入
	string input1 = "adc 123 def 456 ghi 789";
	int as;
	string str;
	stringstream ss;		//输出输入对象
	ss << input1;		//写入
	cout << ss.str()<<endl;
	while (ss >> str>>as)		//取出
	{
		cout << str << " " <<as<< endl;
	}
	system("pause");
    return 0;
}

