/*
ԭ����һ��ʼû������Ŀ.
���⻹�ǱȽϼ򵥵�˵.
i��a[i]ѡ��,i+1��a[i+1]ѡ��,ai��ai+1���ʱ��1��,������.
����=1,������������ֵ�͵��ڸ���ֵ�.
Ȼ��ᷢ��ÿ����Ŀ���Ƕ�����.
case 1:a[i]>=a[i+1] ��a[i]��ѡ��,a[i+1]/a[i]�ĸ���ѡ��1 2 3 ---a[i+1].
����1/a[i+1]�ĸ���ѡ��,�ܸ���Ϊ1/a[i].
case 2:a[i]<a[i+1] ͬ��.
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
