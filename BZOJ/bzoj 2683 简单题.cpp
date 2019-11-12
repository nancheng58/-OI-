/*
CDQ分治.
这题二维数据结构卡内存(CDQ分治基础题.
将x坐标排序,然后树状数组维护y坐标.
然后按照时间分治.
考虑贡献的影响.
推荐2013年集训队作业中许昊然的论文%%%. 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 500001
#define MAXM 200001
using namespace std;
int n,s[MAXN],tot,ans[MAXM*4];
struct data{int x,y,t,o,p,be;}q[MAXM*4],tmp[MAXM*4];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void add(int x,int z)
{
	while(x<=n) s[x]+=z,x+=x&-x;
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
	if(x.x==y.x&&x.y==y.y) return x.p<y.p;
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
void slove(int l,int r)
{
	if(l==r) return ;
	int mid=(l+r)>>1;
	for(int i=l;i<=r;i++)
	{
		if(q[i].t<=mid&&q[i].p==1) add(q[i].y,q[i].o);
		else if(q[i].t>mid&&q[i].p==2)
		{
			ans[q[i].be]+=getsum(q[i].y)*q[i].o;
		}
	}
	for(int i=l;i<=r;i++)
	  if(q[i].t<=mid&&q[i].p==1) add(q[i].y,-q[i].o);
	int ll=l,rr=mid+1;
	for(int i=l;i<=r;i++)
	{
		if(q[i].t<=mid) tmp[ll++]=q[i];
		else tmp[rr++]=q[i];
	}
	for(int i=l;i<=r;i++) q[i]=tmp[i];
	slove(l,mid),slove(mid+1,r);
	return ;
}
int main()
{
	n=read();
	int z,x1,y1,x2,y2,k,t=0;
	while(true)
	{
		z=read();
		if(z==1){
			x1=read(),y1=read(),k=read();
			q[++tot].x=x1,q[tot].y=y1,q[tot].o=k,q[tot].p=1,q[tot].t=tot;
		}
		else if(z==2)
		{
			x1=read(),y1=read(),x2=read(),y2=read();
			q[++tot].x=x1-1,q[tot].y=y1-1,q[tot].o=1,q[tot].p=2,q[tot].t=tot,q[tot].be=++t;
			q[++tot].x=x1-1,q[tot].y=y2,q[tot].o=-1,q[tot].p=2,q[tot].t=tot,q[tot].be=t;
			q[++tot].x=x2,q[tot].y=y1-1,q[tot].o=-1,q[tot].p=2,q[tot].t=tot,q[tot].be=t;
			q[++tot].x=x2,q[tot].y=y2,q[tot].o=1,q[tot].p=2,q[tot].t=tot,q[tot].be=t;
		}
		else break;
	}
	sort(q+1,q+tot+1,cmp);
	slove(1,tot);
	for(int i=1;i<=t;i++) printf("%d\n",ans[i]);
	return 0;
}
