#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 5001
using namespace std;
int tot,ans,a[MAXN],b[MAXN],n,max1,t1=1,t2=1;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
    return x*f;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)  a[i]=read();
    for(int i=1;i<=n;i++)  b[i]=read();
    sort(a+1,a+n+1,greater<int>());
    sort(b+1,b+n+1,greater<int>());
    int head=1,tail=n,head2=1,tail2=n;
    while(head<=tail)
    {
        //if(t1==n+1||t2==n1+1) break;
        bool flag=false;
        if(b[head2]<a[head]) tot+=200,head++,head2++;
        else if(b[tail2]<a[tail]) tot+=200,tail--,tail2--;
        else 
		{
			if(b[head2]>a[tail])tot-=200;head2++,tail--;	
		}
    }
    printf("%d",tot);
    return 0;
}
