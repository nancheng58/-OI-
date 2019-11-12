/*
kmp.
找循环节n-next[n].
只能感性的认识.
先记住吧. 
不会证明orz.
*/
#include<iostream>
#include<cstdio>
#define MAXN 1000001
using namespace std;
int l1,ans,next[MAXN];
char s[MAXN];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void kmp()
{
	int p=0;
	for(int i=2;i<=l1;i++)
	{
		while(p&&s[i]!=s[p+1]) p=next[p];
		if(s[i]==s[p+1]) p++;
		next[i]=p;
	}
	printf("%d",l1-next[l1]);
}
int main()
{
	scanf("%d",&l1);
	scanf("%s",s+1);
	kmp();
	return 0;
}
