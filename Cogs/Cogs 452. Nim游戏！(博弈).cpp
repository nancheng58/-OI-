/*
������������֮һ.
����a1^a2^a3^......an=0 ʱ���ֱذ�.
���Ǻܻ�֤,ֻ������n�ǳ�С��Ȼ���ҹ���.
*/
#include<iostream>
#include<cstdio>
using namespace std;
int t,n,x,ans;
int main()
{
    freopen("nim!.in","r",stdin);
    freopen("nim!.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ans=ans^x;
        }
        if(!ans) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
