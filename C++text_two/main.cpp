// C++text_two.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;

class Point;
class Line {
public:
	Line(int x, int y) :x1(x), y1(y) {};
	void drawLine(Point &a, Point &b);		//前面必须先有Point的声明
private:
	int x1;
	int y1;
};

class Point {
public:
	Point(int x,int y):x(x),y(y){}
private:
	int x;
	int y;
	friend double distances(Point &a1, Point &a2);		//将外部函数设为该类的友元之后	该函数便可以访问该类的私有变量
	friend void Line::drawLine(Point &a, Point &b);		//前面必须现有改函数的声明
	friend class Line;		//类Line是Point的友元类		Line可以访问Point的全部成员		读作Line是Point的友元	Line可以使用Point中的全部成员
	void toString() { cout << "Poi!!!,通过类友元调用我哦" << endl; }		//友元是单向的，不可传递不可继承
};

double distances(Point &a1, Point &a2) {
	return sqrt((a1.x - a2.x)*(a1.x - a2.x) + (a1.y - a2.y)*(a1.y - a2.y));
}

void Line::drawLine(Point &a, Point &b) { cout << "(" << a.x << "," << a.y << ")---->" << "(" << b.x << "," << b.y << ")" << endl; a.toString(); }	//前面必须有Point 的参数声明例如x，y




//void Line::drawLine(Point &a, Point &b){cout<<"("<< }

int main()
{
	Point a1(1, 1);
	Point a2(2, 2);
	cout << distances(a1, a2)<<endl;
	Line li(1, 2);
	
	li.drawLine(a1, a2);
	system("pause");
    return 0;
}

