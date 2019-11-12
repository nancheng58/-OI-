//高精度数字的比较 
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
		if(l1>l2)//位数大的一定大 
		{
			strcpy(max1,a);//字符串覆盖函数 
			t=i;
		}
		if(l1==l2&&strcmp(a,max1)>0)//最长的比较大小 
		{
			strcpy(max1,a);//字符串覆盖函数
			t=i;
		}
	}
	cout<<t<<endl<<max1;
	return 0; 
}
