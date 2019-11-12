#include<iostream>
#include<cstdio>
#define MAXN 100001
using namespace std;
int s[MAXN],n,tot,sum=1,l,a[MAXN],b[MAXN],c[MAXN];
void slove(int x)
{
	for(int i=1;i<=l;i++)
	{
		a[i]*=x;
		a[i]+=a[i-1]/10;
		a[i-1]%=10;
	}
	if(a[l]>9) a[++l]=a[l-1]/10,a[l-1]%=10;
}
int main()
{
	scanf("%d",&n);l=1;
	while(n>=3) s[++tot]=3,n-=3;
	if(n==1) s[tot]=2,s[++tot]=2;
	else if(n==2) s[++tot]=n;
	a[1]=1;
	for(int i=1;i<=tot;i++) slove(s[i]);
	while(!a[l]&&l>=1) l--;
	printf("%d\n",l);
	for(int i=l;i>=max(l-99,1);i--)
	  printf("%d",a[i]);
	return 0;
}
