/*
后缀数组.
比较简单.
but 一开始我傻逼的直接跑后缀数组然后输出第balablaba个字符.
没有考虑跨串字符的感受.
这题把串copy一下跑后缀数组就好了.
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 200010
using namespace std;
int n,K,l,m=131,sa[MAXN],c[MAXN],ht[MAXN],t1[MAXN],t2[MAXN],s[MAXN];
char ch[MAXN];
bool cmp(int *y,int a,int b,int k)
{
    int a1=y[a],b1=y[b];
    int a2=a+k>=n?-1:y[a+k];
    int b2=b+k>=n?-1:y[b+k];
    return a1==b1&&a2==b2;
}
void slovesa()
{
    int *x=t1,*y=t2;
    for(int i=0;i<m;i++) c[i]=0;
    for(int i=0;i<n;i++) c[x[i]=s[i]]++;
    for(int i=1;i<m;i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1,p=0;k<=n;k<<=1,m=p,p=0)
    {
        for(int i=n-k;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(int i=0;i<m;i++) c[i]=0;
        for(int i=0;i<n;i++) c[x[y[i]]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y),p=1,x[sa[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(cmp(y,sa[i-1],sa[i],k)) x[sa[i]]=p-1;
            else x[sa[i]]=p++;
        }
        if(p>=n) break;
    }
    for(int i=1;i<n;i++)
	{
		if(sa[i]>=l) continue;
		printf("%c",char(s[sa[i]+l-1]));
	}
}
int main()
{
	scanf("%s",ch);
	l=n=strlen(ch);
	for(int i=0;i<n;i++) s[i]=ch[i];
	for(int i=0;i<n;i++) s[i+n]=ch[i];
	n*=2;s[n++]=0;
	slovesa();
	return 0;
}
