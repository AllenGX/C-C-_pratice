// C++_text_eight.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


struct Book {
	char c[5];	//产品代码
	char n[11];	//产品名称
	int p;	//单价
	int q;	//数量
};





int main()
{
	//文件基本操作

	/*
	
	①	定义文件流对象
	②	通过构造函数或者成员函数open打开文件（或者创建）
	③	打开文件失败时中断文件处理
	④	对文件进行各种操作
	⑤	文件处理结束时关闭文件

	*/

/*--------------读写ascall文件-------------------*/

	ifstream inf("2.txt");	//打开文件（用来读）
	char s1[500];
	int cnt = 0;
	if (!inf.fail()) {
		ofstream outf("1.text.txt");	//打开文件（用来写）
		while (!inf.eof())	//文件中还有数据
		{
			inf.getline(s1, sizeof(s1)-1);	//读一行
			outf <<setfill('0')<<setw(4)<<++cnt << " " << s1 << endl;	//写入
			cout << s1 << endl;
		}
		outf.close();
		inf.close();	//关闭
	}
	
/*-----------------读写二进制文件-----------------*/
	char src[260], dest[260], buff[16384];	//读写缓冲16k
	ifstream infs("2.dat", ios_base::in | ios_base::binary);	//二进制读
	if (!infs.fail()) {
		ofstream outfs("1.dat", ios_base::out | ios_base::binary);	//二进制写
		while (!infs.eof())	//是否读到文件末尾
		{
			infs.read(buff, sizeof(buff));
			outfs.write(buff, infs.gcount());	//按实际独到的字节数写入
			cout << buff << endl;
		}
		outfs.close();
		infs.close();
	}


	//seekg  和seekp	可以控制读取的位置


	/*------------使用读写对象实现二进制------------*/


	Book a;
	ifstream infss("book.dat");
	ios_base::openmode  m = ios_base::in | ios_base::out;		//可读可写
	fstream iofss("out.dat", m | ios_base::trunc | ios_base::binary);		//打开out.dat  没有就创建，有，就格式化

	if (infss.fail() || iofss.fail())return -1;
	while (!infss.eof())
	{
		infss >> a.c >> a.n >> a.p >> a.q;		//读文件
		cout << a.c << " " << a.n << " " << a.p << " " << a.q << endl;
		iofss.write((char *)&a, sizeof(Book));	//把Book的地址转化为char *类型
	}

	infss.close();		//关闭book.dat文件	（已经写完成了）
	iofss.seekg(0 * sizeof(Book), ios_base::beg);	//定到文件的开始

	while (!iofss.eof())
	{
		iofss.read((char*)&a, sizeof(Book));	//每次从out.dat读入一个Book
		cout << a.c << " " << a.n << " " << a.p << " " << a.q << endl;
	}
	iofss.close();

	system("pause");
    return 0;
}

