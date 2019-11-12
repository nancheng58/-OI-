/*
博弈.
当n<=k时,显然先手必胜.
否则n=k+1时先手必败.
n属于[k+2,2k+1]时,总能回到n=k+1的状态,所以先手必胜.
同理 n=2(k+1),3(k+1)时先手必败......
所以 k+1|n时先手必败
否则先手必胜.
*/
#include<cstdio>
#define LL unsigned long long
using namespace std;
LL t,n,k;
inline LL read()
{
    LL x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
    return x;
}
int main()
{
    freopen("tstones.in","r",stdin);
    freopen("tstones.out","w",stdout);
    t=read();
    while(t--)
    {
        n=read(),k=read();
        if(n%(k+1)==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
