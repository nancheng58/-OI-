/*
����. 
����sg����.
��Ȼ1~9���Ǳ�ʤ̬.
��Ȼ�������������С.
���һ��״̬�ĺ��״̬�бذ�̬,
��ô�����Ǳ�ʤ̬.
������Ǳذ�̬.
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
