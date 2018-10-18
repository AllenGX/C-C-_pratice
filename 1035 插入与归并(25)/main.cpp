// 1035 插入与归并(25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int isSame(const int *a, const int *b,int cnt) {
	for (int i = 0; i < cnt; i++)
	{
		if (a[i] != b[i])return 0;
	}
	return 1;
}


//插入排序
int insert_sort(int *a, const int *b,int cnt) {
	int flag = 0;
	for (int i = 1; i < cnt; i++)
	{
		int temp = a[i];
		int j;
		for (j= 0; j < i; j++)
		{
			if (a[j] > a[i]) {
				for (int z = i-1; z >=j; z--)
				{
					a[z + 1] = a[z];
				}
				break;
			}
		}
		a[j] = temp;
		if (isSame(a, b,cnt)) {
			flag = i;
			break;
		}
	}
	return flag;
}


//归并
void Sort(int *a, int *b, int left, int right,int center) {
	int L = left;
	int C = center;
	int k = left;
	int R = C + 1;

	while (L!=C+1&&R!=right+1)
	{
		if (a[L] <= a[R]) {
			b[k++] = a[L++];
		}else{
			b[k++] = a[R++];
		}
	}
	while (L != C + 1 )
	{
		b[k++] = a[L++];
	}
	while (R != right + 1)
	{
		b[k++] = a[R++];
	}
}



int main()
{


	int cnt;
	cin >> cnt;
	int A1[101];
	int A3[101];
	int B[101];
	int A2[101];
	for (int i = 0; i < cnt; i++)
	{
		cin >> A1[i];
		A2[i] = A1[i];
	}
	for (int i = 0; i < cnt; i++)
	{
		cin >> B[i];
	}
	int numbers = insert_sort(A1, B, cnt);
	if (numbers) {
		cout << "Insertion Sort"<<endl;


		int temp = A1[numbers+1];
		int j;
		for (j = 0; j < numbers + 1; j++)
		{
			if (A1[j] > A1[numbers + 1]) {
				for (int z = numbers; z >= j; z--)
				{
					A1[z + 1] =A1[z];
				}
				break;
			}
		}
		A1[j] = temp;
		for (int i = 0; i < cnt; i++)
		{
			cout << A1[i];
			if (i != cnt - 1)cout << " ";
		}
	}
	else {
		//归并排序
		int temp=1;
		int flag = 0;
		while (true)
		{
			temp = 2*temp;
			int zu = temp / 2;
			int i=0;
			for (i = 0; i <= cnt - temp; i += temp)
			{
				Sort(A2, A3, i, i + temp - 1,i+(temp-1)/2);
			}
			if (i + zu <= cnt) {
				Sort(A2, A3, i, cnt - 1, i + (temp - 1) / 2);
			}
			else {
				for (int j = i; j <cnt; j++)
				{
					A3[j] = A2[j];
				}
			}
			if (isSame(A3, B, cnt)) {
				flag = 3;
				break;
			}
			temp = 2*temp;
			zu = temp / 2;
			i = 0;
			for (i = 0; i <= cnt - temp; i += temp)
			{
				Sort(A3, A2, i, i + temp - 1, i + (temp - 1) / 2);
			}
			if (i + zu <= cnt) {
				Sort(A3, A2, i, cnt - 1, i + (temp - 1) / 2);
			}
			else {
				for (int j = i; j <cnt; j++)
				{
					A2[j] = A3[j];
				}
			}
			if (isSame(A2, B, cnt)) {
				flag =2;
				break;
			}
		}
		cout << "Merge Sort" << endl;
		temp = temp * 2;
		if (flag == 2) {
			int zu = temp / 2;
			int i = 0;
			for (i = 0; i <= cnt - temp; i += temp)
			{
				Sort(A2, A3, i, i + temp - 1, i + (temp - 1) / 2);
			}
			if (i + zu <= cnt) {
				Sort(A2, A3, i, cnt - 1, i + (temp - 1) / 2);
			}
			else {
				for (int j = i; j <cnt; j++)
				{
					A3[j] = A2[j];
				}
			}
			for (int i = 0; i < cnt; i++)
			{
				cout << A3[i];
				if (i != cnt - 1)cout << " ";
			}
		}
		else if (flag == 3) {
			int zu = temp / 2;
			int i = 0;
			for (i = 0; i <= cnt - temp; i += temp)
			{
				Sort(A3, A2, i, i + temp - 1, i + (temp - 1) / 2);
			}
			if (i + zu <= cnt) {
				Sort(A3, A2, i, cnt - 1, i + (temp - 1) / 2);
			}
			else {
				for (int j = i; j <cnt; j++)
				{
					A2[j] = A3[j];
				}
			}
			for (int i = 0; i < cnt; i++)
			{
				cout << A2[i];
				if (i != cnt - 1)cout << " ";
			}
		}
	}
	system("pause");
    return 0;
}

