/*
三维偏序.
一维排序,二维CDQ分治,三维树状数组维护.
求三维LIS.
先对x排序,再对c分治处理贡献. 
然后树状数组维护比m小的数的个数.
貌似还可以树状数组套平衡树搞orz.
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 200001
using namespace std;
int n,k,s[MAXN],tot,ans[MAXN],ansrank[MAXN];
struct data
{
    int s,c,m,o,be,sum;
    bool operator ==(const data &x)
    {
        return x.s==s&&x.c==c&&x.m==m; 
    }
}q[MAXN],tmp[MAXN];
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
    return x*f;
}
void add(int x,int z)
{
    while(x<=k) s[x]+=z,x+=x&-x;
    return ;
}
int getsum(int x)
{
    int sum=0;
    while(x>0) sum+=s[x],x-=x&-x;
    return sum;
}
bool cmp(const data &x,const data &y)
{
    if(x.s==y.s&&x.c==y.c) return x.m<y.m;
    if(x.s==y.s) return x.c<y.c;
    return x.s<y.s;
}
bool cmp2(const data &x,const data &y)
{
    if(x.c==y.c) return x.o<y.o;
    return x.c<y.c;
}
void slove(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)>>1,ll=l,rr=mid+1,cut=0;;
    for(int i=l;i<=mid;i++) q[i].o=1,tmp[ll++]=q[i];
    for(int i=mid+1;i<=r;i++) q[i].o=2,tmp[rr++]=q[i];
    //for(int i=l;i<=r;i++) q[i]=tmp[i];
    sort(tmp+l,tmp+r+1,cmp2);
    for(int i=l;i<=r;i++)
    {
        if(tmp[i].o==1) add(tmp[i].m,tmp[i].sum);
        else ans[tmp[i].be]+=getsum(tmp[i].m);
    }
    for(int i=l;i<=r;i++) if(tmp[i].o==1) add(tmp[i].m,-tmp[i].sum);
    slove(l,mid),slove(mid+1,r);
    return ;
}
int main()
{
    int t=0;
    n=read(),k=read();
    for(int i=1;i<=n;i++)
      tmp[i].s=read(),tmp[i].c=read(),tmp[i].m=read(),tmp[i].sum=1;
    sort(tmp+1,tmp+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(tmp[i]==tmp[i-1]) q[tot].sum++;
        else q[++tot]=tmp[i],q[tot].be=++t;
    }
    sort(q+1,q+tot+1,cmp);
    slove(1,tot);
    for(int i=1;i<=tot;i++) ansrank[ans[q[i].be]+q[i].sum-1]+=q[i].sum;
    for(int i=0;i<n;i++) printf("%d\n",ansrank[i]);
    return 0;
}
