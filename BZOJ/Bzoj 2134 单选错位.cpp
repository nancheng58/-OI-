/*
原谅我一开始没看懂题目.
这题还是比较简单的说.
i有a[i]选法,i+1有a[i+1]选法,ai与ai+1相等时得1分,求期望.
贡献=1,所以最后的期望值就等于概率值喽.
然后会发现每个题目都是独立的.
case 1:a[i]>=a[i+1] 有a[i]种选法,a[i+1]/a[i]的概率选到1 2 3 ---a[i+1].
并有1/a[i+1]的概率选对,总概率为1/a[i].
case 2:a[i]<a[i+1] 同理.
*/
#include<iostream>
#include<cstdio>
#define MAXN 10000001
#define LL long long
using namespace std;
LL a[MAXN],n,A,B,C;
double ans;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f; 
}
double slove1(LL x,LL y)
{
	double tot=double(1/double(max(x,y)));
	return tot;
}
void slove()
{
	a[0]=a[n];
	for(int i=1;i<=n;i++) ans+=slove1(a[i-1],a[i]);
	return ;
}
int main()
{
	n=read(),A=read(),B=read(),C=read(),a[1]=read();
	for(int i=2;i<=n;i++) a[i]=(a[i-1]*A+B)%100000001;
	for(int i=1;i<=n;i++) a[i]=a[i]%C+1;
	slove();
	printf("%.3lf",ans);
	return 0;
}
