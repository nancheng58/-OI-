/*
�ֿ�.
û���޸ĵĻ����ǿ���O(n)�������Ƴ�ÿ����Ĺ���.
Ȼ��O(1)��ѯ.
��������޸Ĳ�������������Ļ����Ӷȿ��ܻᵽO(n).
Ȼ�����ǿ��Էֿ�O(��n)��ʱ�����������������.
����ÿ����ά��һ�����������ĵ�һ��λ�ú�������е��ƶ�����.
�޸Ĳ�����ʱ��Ҫ�����޸�
����������ƱȽϷ���....
splay����ʽ�ϲ�ʲô���Ժ���д. 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXN 200001 
using namespace std;
int next[MAXN],belong[MAXN],n,m,ans,k[MAXN],len,s[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void slove(int x)
{
	int tot,pos;
	for(int i=(x-1)*len+1;i<=min(n,x*len);i++)
	{
		tot=0,pos=i;//λ��
		while(pos<=n&&belong[pos]==x) tot++,pos+=k[pos];
		s[i]=tot,next[i]=pos;
	}
	return ;
}
int query(int x)
{
	ans=0;
	for(int i=x;i<=n;i=next[i]) ans+=s[i];
	return ans;
}
void _union(int x,int y)
{
	k[x]=y;
	for(int i=x;i>=(belong[x]-1)*len+1;i--)//������� 
	{
		if(i+k[i]>belong[x]*len) s[i]=1,next[i]=i+k[i];
		else s[i]=s[i+k[i]]+1,next[i]=next[i+k[i]];
	}
	return ;
}
int main()
{
	int x,y,z;
	n=read();len=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		belong[i]=(i-1)/len+1;//ÿ���
	}
	for(int i=1;i<=belong[n];i++) slove(i);
	m=read();
	for(int i=1;i<=m;i++)
	{
		z=read(),x=read();x++;
		if(z&1) printf("%d\n",query(x));
		else y=read(),_union(x,y);
	}
	return 0;
}
