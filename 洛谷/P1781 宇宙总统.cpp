//�߾������ֵıȽ� 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char max1[1000];
char a[100];
int main()
{
	int n,t;
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		int l1=strlen(a);
		int l2=strlen(max1);
		if(l1>l2)//λ�����һ���� 
		{
			strcpy(max1,a);//�ַ������Ǻ��� 
			t=i;
		}
		if(l1==l2&&strcmp(a,max1)>0)//��ıȽϴ�С 
		{
			strcpy(max1,a);//�ַ������Ǻ���
			t=i;
		}
	}
	cout<<t<<endl<<max1;
	return 0; 
}
