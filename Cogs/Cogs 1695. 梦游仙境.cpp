/*
���X�m���ĵ�һ���ֿ���.
һ��ʼû�뵽��ô��.
��ž��Ƕ���jumpֵ>sqrt(n)��ѯ�ʱ�������.
����jumpֵ<=sqrt(n)��ѯ����һ��Ԥ����.
sum[i][j]��ʾ��i��,���(���±��)Ϊj�ĵ��ǰ׺�𰸹���.
��ѯ��ʱ�����Ǳ�֤����Ծ�����ͬ�ĵ�ı����������
���Ҳ�ѯ��[l,r]�й��׵������˵�ض���ͬһ���������������.
so ǰ׺��ֱ������Ϳ���.
���Ӷ�O(q��n). 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXN 100001
#define MAXM 320
#define LL long long
using namespace std;
int n,m,K,a[MAXN],s[MAXM][MAXN],g[MAXM][MAXN];
LL sum[MAXM][MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void pre()
{
	int pos;
	for(int i=1;i<=K;i++)//ö�����ĳ���. 
	{
	  pos=0;
	  for(int j=1;j<=i;j++)//ö���������(��Ȼ����i�����). 
	    for(int k=j;k<=n;k+=i)//��.
		{
			g[i][k]=++pos;
		  	s[i][pos]=a[k];
		}
	  for(int j=1;j<=n;j++) sum[i][j]=sum[i][j-1]+(LL)s[i][j];
	}
}
LL slove1(int l,int r,int jump)
{
	LL tot=0;
	for(int i=l;i<=r;i+=jump) tot+=a[i];
	return tot;
}
LL slove2(int l,int r,int jump)
{
	int ll=l,rr=r-(r-l)%jump;
	if(!jump||ll>=rr) return a[ll];
	ll=g[jump][ll],rr=g[jump][rr];
	return sum[jump][rr]-sum[jump][ll-1];
}
int main()
{
	freopen("XTTMYXJ.in","r",stdin);
	freopen("XTTMYXJ.out","w",stdout);
	int x,y,z;
	n=read(),m=read();K=sqrt(n);
	for(int i=1;i<=n;i++) a[i]=read();
	pre();
	while(m--)
	{
		x=read(),y=read(),z=read();
		if(z>K)  printf("%lld\n",slove1(x,y,z));
		else printf("%lld\n",slove2(x,y,z));
	}
	return 0;
}
