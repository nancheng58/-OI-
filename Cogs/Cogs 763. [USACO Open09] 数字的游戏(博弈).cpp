/*
博弈. 
递推sg函数.
显然1~9都是必胜态.
显然操作后数都会变小.
如果一个状态的后继状态有必败态,
那么它就是必胜态.
否则就是必败态.
*/
#include<iostream>
#include<cstdio>
#define MAXN 1000001
using namespace std;
int n,max1,min1,sg[MAXN];
void pre()
{
    for(int i=1;i<=9;i++) sg[i]=1;
    for(int i=10;i<=MAXN-1;i++)
    {
        int x=i;
        min1=10,max1=0;
        while(x)
        {
            int xx=x%10;
            x/=10;
            if(xx) min1=min(xx,min1);
            if(xx) max1=max(max1,xx);
        }
        if(!sg[i-min1]||!sg[i-max1]) sg[i]=1;
        else sg[i]=0;
    }
}
int main()
{
    freopen("cdgame.in","r",stdin);
    freopen("cdgame.out","w",stdout);
    int x;
    pre();scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(sg[x]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
