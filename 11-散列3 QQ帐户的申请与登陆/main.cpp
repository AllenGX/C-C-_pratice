// 11-散列3 QQ帐户的申请与登陆.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	long long int a;
	char c[17];
	struct node *next;
}*Nodes,Nod;

typedef struct cell {
	Nodes N;
}*Cell;


void insert(Cell ce, long long int numbers, char *c, char states,int key) {
	int ns = numbers % 100000;
	int Nss = ns % key;
	int flag = 4;			//  1 表示密码错误		0 表示登陆成功		2表示已经注册	3表示注册成功		4表示登陆账号不存在
	Nodes P = &ce->N[Nss];
	int lengthc = 0;
	int lengthp = 0;
	while (c[lengthc]!='\0')
	{
		lengthc++;
	}

	if (states == 'L') {
		while (P->next!=NULL)
		{
			if (P->next->a == numbers) {
				while (P->next->c[lengthp] != '\0')
				{
					lengthp++;
				}
				int i = 0;
				if (lengthc == lengthp) {
					while (P->next->c[i] != '\0' || c[i] != '\0')
					{
						if (P->next->c[i] == c[i]) {
							i++;
						}
						else {
							flag = 1;
							break;
						}
					}
					flag = 0;
				}
				else {
					flag = 1;
				}
				break;
			}
			P = P->next;
		}
	}
	else {
		// N
		while (P->next != NULL)
		{
			if (P->next->a == numbers) {
				flag = 2;
				break;
			}
			P = P->next;
		}
		if (flag == 4) {
			flag = 3;
			Nodes ns = (Nodes)malloc(sizeof(Nod));
			ns->a = numbers;
			int i = 0;
			while (c[i]!='\0')
			{
				ns->c[i] = c[i];
				i++;
			}
			ns->c[i] = '\0';
			ns->next = NULL;
			P->next = ns;
		}
	}
	switch (flag)
	{
	case 0:printf("Login: OK\n"); break;
	case 1:printf("ERROR: Wrong PW\n"); break;
	case 2:printf("ERROR: Exist\n"); break;
	case 3:printf("New: OK\n"); break;
	case 4:printf("ERROR: Not Exist\n"); break;
	}
}


int main()
{
	int Ns;
	scanf_s("%d", &Ns);
	int key = 2 * Ns + 1;
	Cell Ce = (Cell)malloc(sizeof(struct cell));
	Ce->N = (Nodes)malloc(sizeof(Nod)*key);
	for (int i = 0; i < key; i++)
	{
		Ce->N[i].a = -1;
		Ce->N[i].c[0] = '\0';
		Ce->N[i].next = NULL;
	}
	char c[20];
	char states;
	long long int numbers;
	for (int i = 0; i < Ns; i++)
	{
		scanf_s("\n%c", &states);
		scanf_s("%lld",&numbers);
		int ii = 0;
		/*do
		{
			scanf_s("%c", &c[ii]);
		} while (c[ii++] != '\0');*/
		scanf_s(" %s", c,17);
		insert(Ce, numbers, c, states,key);
	}
	system("pause");
    return 0;
}

