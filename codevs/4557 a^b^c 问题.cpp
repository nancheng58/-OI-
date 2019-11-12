#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL a,b,c,p,ans=1,n;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
LL mi(LL x,LL y)
{
	LL tot=1;
	while(y)
	{
		if(y&1) tot=tot*x%p;
		x=x*x%p;
		y>>=1;
	}
	return tot;
}
int main()
{
	n=read();
	while(n--)
	{
		a=read(),b=read(),c=read(),p=read();
		ans=ans*mi(a,b)%p;
		ans=mi(ans,c)%p;
		printf("%lld\n",ans);
		ans=1;
	}
	return 0;
}
