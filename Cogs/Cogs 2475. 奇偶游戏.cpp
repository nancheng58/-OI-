/*
����.
�������۵�k+1����˭ȡ��.
n==k��ʱ������һ��.
�������ÿ���˵Ŀɲ�������.
Ȼ�����۾ͺ�.
*/
#include<iostream>
#include<cstdio>
#define MAXN 10001
using namespace std;
int n,k,num1,num0,k0,k1;
int main()
{
	int x;
	while(~scanf("%d%d",&n,&k))
	{
		num1=num0=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x&1) num1++;
			else num0++;
		}
		if(n==k)
		{
			if(num1&1) printf("Stannis\n");
			else printf("Daenerys\n");
			continue;
		}
		k1=(n-k+1)/2;
		k0=n-k-k1;
		if(num1<=k0) printf("Daenerys\n");
		else if(num0<=k0&&(num1-num0)&1&&k0!=k1)
		{
			printf("Daenerys\n");
		}
		else if(num0<=k0&&(num1-num0)%2==0&&k1==k0)
		{
			printf("Daenerys\n");
		}
		else if(num0>k0&&num1>k0&&k1==k0)
		{
			printf("Daenerys\n");
		}
		else {
			printf("Stannis\n");
		}
	}
	return 0;
}
