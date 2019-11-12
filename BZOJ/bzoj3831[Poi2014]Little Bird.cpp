#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1000001
using namespace std;
int f[MAXN],h[MAXN],n,m,k,q[MAXN];
int read()
{
	char ch=getchar();int f=1,x=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)  h[i]=read();
	m=read();
	while(m--)
	{
	  	k=read();
	  	int tail=1,head=1;
	  	q[tail]=1; 
		for(int i=2;i<=n;i++)
	  	{
	  		while(head<=tail&&i-q[head]>k) head++;
	  		if(h[i]>=h[q[head]]) f[i]=f[q[head]]+1;
	  		else f[i]=f[q[head]];
			while(f[i]<=f[q[tail]]&&head<=tail){
				if(f[i]==f[q[tail]]&&h[i]<h[q[tail]]) break;
				tail--;
			}
			q[++tail]=i;
	  	}
	  	printf("%d\n",f[n]);
	}
	return 0;
}
