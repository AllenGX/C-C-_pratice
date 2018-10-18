// C——text.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{

	//int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//int *const b = a;
	//printf("sizeof(a)%d\nsizeof(b)%d\n", sizeof(a), sizeof(b));		//占用空间不一样
	//printf("a[1]=%d\nb[1]=%d\n", a[1], b[1]);	//都可以用下标访问数组
	//printf("a指向地址：%d\nb指向的地址：%d\n",b,a);		//值一样
	//printf("%d\n%d\n", ++b, ++a);		//都不能进行自增操作
	//a[1] = 1; b[1] = 1;		//都可以进行赋值操作

	void *p;
	int n = 0;
	while ((p=malloc(100*1024*1024)))
	{
		n++;
	}
	printf("分配了%d00MB的空间\n",n);



	system("pause");
    return 0;
}

