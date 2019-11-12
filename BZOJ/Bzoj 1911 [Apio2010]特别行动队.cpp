/*
б���Ż�.
������һ��y>x,��y�ľ���ֵ��x��.
����
f[y]+a*(sum[y]-sum[i])*(sum[y]-sum[i])-b*(sum[y]-sum[i])
 > f[x]+a*(sum[x]-sum[i])*(sum[x]-sum[i])-b*(sum[x]-sum[i]).
�����:(f[y]+a*sum[y]*sum[y]-b*sum[y])-(f[x]+a*sum[x]*sum[x]-b*sum[x]) 
>2*a*(sum[j]-sum[k])*sum[i].
so  (f[y]+a*sum[y]*sum[y]-b*sum[y])-(f[x]+a*sum[x]*sum[x]-b*sum[x])/[(sum[j]-sum[k])*a*2]
<sum[i]
��ע��aС��0����
�����֪,sum[i]�ǵ���������,
so ��������Ǹ�����<sum[i],��һ��<sum[i+1].
������ʱx�ľ���ֵ����Ӱ���.
�����õ�������ά��һ����͹����,
�ö���Ԫ�ظ��´𰸼���.
*/
#include<iostream>
#include<cstdio>
#define MAXN 1000001
#define LL long long
using namespace std;
LL f[MAXN],n,sum[MAXN],a,b,c,q[MAXN],head,tail;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
double F(int x)
{
	return f[x]+a*sum[x]*sum[x]-b*sum[x];
}
double check(int x,int y)
{
	 return double(F(y)-F(x))/double((sum[y]-sum[x])*a*2);
}
void slove()
{
	for(int i=1;i<=n;i++)
	{
		while(head<tail&&check(q[head],q[head+1])<sum[i]) head++;
		f[i]=f[q[head]]+a*(sum[i]-sum[q[head]])*(sum[i]-sum[q[head]])+b*(sum[i]-sum[q[head]])+c;
		while(head<tail&&check(q[tail],i)<check(q[tail-1],q[tail])) tail--;
		q[++tail]=i;
	}
	cout<<f[n];
}
int main()
{
	int x;
	n=read();
	a=read(),b=read(),c=read();
	for(int i=1;i<=n;i++) x=read(),sum[i]=sum[i-1]+x;
	slove();
	return 0;
}
