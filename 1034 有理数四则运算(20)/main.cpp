// 1034 有理数四则运算(20).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

typedef struct nunber {
	long long int C;
	long long int a1;
	long long int b1;
	int flag;
}*Number, Numbe;


Number exchange(const Number N) {
	//化简
	Number N1 = (Number)malloc(sizeof(Numbe));
	N1->C = 0;
	long long int cc=N->a1 / N->b1;
	N1->b1 = N->b1;
	N1->flag = N->flag;
	long long int b = N->b1;
	N1->a1 = N->a1 - N->b1*cc;
	N1->C +=cc;
	long long int a = N1->a1;
	long long int c =1 ;
	while (c!=0&&a!=0)
	{
		c= b % a;
		if (c != 0) {
			b = a;
			a= c;
		}
	}
	if (a != 0) {
		N1->a1 = N1->a1 / a;
		N1->b1 = N1->b1 / a;
	}
	else {
		N1->a1 = 0;
		N1->b1 = 0;
		if (N1->C == 0) {
			N1->flag = 0;
		}
	}
	return N1;
}

//   +		无化简
Number add(const Number N1,const Number N2) {
	Number N = (Number)malloc(sizeof(Numbe));
	N->C = 0;
	N->a1 = N1->a1*N2->b1 + N2->a1*N1->b1;
	N->b1 = N1->b1*N2->b1;
	N = exchange(N);
	N->flag = N1->flag;
	return N;
}


//   - 法   无化简
Number jian(const Number N1, const Number N2) {
	Number N = (Number)malloc(sizeof(Numbe));
	N->C = 0;
	if ((N1->a1*N2->b1) > (N1->b1*N2->a1)) {
		N->flag = N1->flag;
		N->b1 = N1->b1*N2->b1;
		N->a1 = (N1->a1*N2->b1) - (N1->b1*N2->a1);
		N = exchange(N);
	}
	else if ((N1->a1*N2->b1) == (N1->b1*N2->a1)) {
		N->flag = 0;
		N->a1 = 0;
		N->b1 = 1;
		N->C = 0;
	}
	else {
		N->flag = N2->flag;
		N->b1 = N1->b1*N2->b1;
		N->a1 =(N1->b1*N2->a1)- (N1->a1*N2->b1) ;
		N = exchange(N);
	}
	return N;

}

//  *  法
Number chen(const Number N1, const Number N2) {
	Number N = (Number)malloc(sizeof(Numbe));
	N->C = 0;
	if (N1->flag == N2->flag) {
		N->flag = 1;
		N->b1 = N1->b1*N2->b1;
		N->a1 = N1->a1*N2->a1;
	}
	else if (N2->flag == 0) {
		N->flag = 1;
		N->b1 = 1;
		N->a1 = 0;
		
	}else{
		N->flag = -1;
		N->b1 = N1->b1*N2->b1;
		N->a1 = N1->a1*N2->a1;
	}
	N = exchange(N);
	return N;
}

// / 法
Number chu(const Number N1, const Number N2) {
	Number N = (Number)malloc(sizeof(Numbe));
	N->C = 0;
	if (N1->flag == N2->flag&&N2->flag != 0) {
		N->flag = 1;
		N->b1 = N1->b1*N2->a1;
		N->a1 = N1->a1*N2->b1;
	}
	else if (N2->flag == 0) {
		N->flag = 0;
		N->b1 = 1;
		N->a1 = 0;

	}
	else {
		N->flag = -1;
		N->b1 = N1->b1*N2->a1;
		N->a1 = N1->a1*N2->b1;
	}
	N = exchange(N);
	return N;
}

void print(Number n1) {
	if (n1->flag == 1) {
		if (n1->C != 0) {
			cout << n1->C;
		}
		if (n1->C != 0 && n1->a1 != 0)cout << " ";

		if (n1->a1 != 0) {
			cout << n1->a1 << "/" << n1->b1;
		}
	}
	else if(n1->flag == 0){
		cout << "0";
	}
	else {
		cout << "(-";
		if (n1->C != 0) {
			cout << n1->C;
		}
		if (n1->C != 0 && n1->a1 != 0)cout << " ";

		if (n1->a1 != 0) {
			cout << n1->a1 << "/" << n1->b1;
		}
		cout << ")";
	}
}




int main()
{
	Number N1 = (Numbe *)malloc(sizeof(Numbe));
	Number N2= (Numbe *)malloc(sizeof(Numbe));
	N1->C = 0;
	N2->C = 0;
	char c = '\0';
	cin >> N1->a1 >>c>>N1->b1  >>N2->a1 >>c>>N2->b1 ;
	if (N2->a1 > 0)N2->flag = 1;
	if (N2->a1 == 0)N2->flag = 0;
	if (N2->a1 < 0) {
		N2->flag = -1;
		N2->a1 = -N2->a1;
	}
	if (N1->a1 > 0)N1->flag = 1;
	if (N1->a1 == 0)N1->flag = 0;
	if (N1->a1 < 0) { 
		N1->flag = -1; 
		N1->a1 = -N1->a1;
	}
	Number A = (Numbe *)malloc(sizeof(Numbe));
	Number B = (Numbe *)malloc(sizeof(Numbe));
	A = exchange(N1);
	B = exchange(N2);

	
	// +法
	Number n1 = (Numbe *)malloc(sizeof(Numbe));
	if (N1->flag == N2->flag) {
		n1 = add(N1, N2);
	}
	else {
		n1 = jian(N1, N2);
	}
	print(A);
	cout << " + ";
	print(B);
	cout << " = ";
	print(n1);
	cout << endl;


	//  -法
	Number n2 = (Numbe *)malloc(sizeof(Numbe));
	if (N1->flag == N2->flag) {
		n2 = jian(N1, N2);
	}
	else {
		n2 = add(N1, N2);
	}
	print(A);
	cout << " - ";
	print(B);
	cout << " = ";
	print(n2);
	cout <<endl;



	// *  法
	Number n3 = (Numbe *)malloc(sizeof(Numbe));
	n3 = chen(N1, N2);

	print(A);
	cout << " * ";
	print(B);
	cout << " = ";
	print(n3);
	cout << endl;


	// /  法
	Number n4 = (Numbe *)malloc(sizeof(Numbe));
	n4 = chu(N1, N2);

	print(A);
	cout << " / ";
	print(B);
	cout << " = ";
	if (n4->flag == 0) {
		cout << "Inf";
	}
	else {
		print(n4);
	}
	cout << endl;

	system("pause");
    return 0;
}

