/*
����.
��n<=kʱ,��Ȼ���ֱ�ʤ.
����n=k+1ʱ���ֱذ�.
n����[k+2,2k+1]ʱ,���ܻص�n=k+1��״̬,�������ֱ�ʤ.
ͬ�� n=2(k+1),3(k+1)ʱ���ֱذ�......
���� k+1|nʱ���ֱذ�
�������ֱ�ʤ.
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
