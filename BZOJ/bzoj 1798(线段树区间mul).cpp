/*
第一次写指针版线段树.
区间mul.
设立两个lazy
(1)先乘后加:x*lazy2+lazy1.
(2)先加后乘:(x+lazy1)*lazy2->x*lazy2+lazy1*lazy2.
为了统一操作.
当有乘法lazy时先下放乘法lazy到加法lazy.
求和的话:原来有(sum+lazy1*k)*lazy2=sum*lazy2+k*lazy1*lazy2.
		因有lazy1=lazy1*lazy2,所以有sum=sum*lazy2+k*lazy1.
*/
#include<iostream>
#include<cstdio>
#define MAXN 100001
#define LL long long
using namespace std;
LL n,m,p,cut;
struct data{
	LL sum,bja,bjm;
	int l,r;
	data *lc,*rc;
}tree[MAXN*4];
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
void build(data *k,int l,int r)
{
	k->bjm=1,k->bja=0,k->l=l,k->r=r,k->sum=0;
	if(l==r) {
		k->lc=k->rc=NULL;
		k->sum=read()%p;
		return ;
	}
	int mid=(l+r)>>1;
	k->lc=&tree[++cut];
	build(k->lc,l,mid);
	k->rc=&tree[++cut];
	build(k->rc,mid+1,r);
	if(k->lc!=NULL) k->sum+=k->lc->sum;
	if(k->rc!=NULL) k->sum+=k->rc->sum;
	k->sum%=p;return ;
}
void updata(data *k)
{
	k->lc->bjm=k->lc->bjm*k->bjm%p;
	k->rc->bjm=k->rc->bjm*k->bjm%p;
	k->lc->bja=(k->lc->bja*k->bjm+k->bja)%p;
	k->rc->bja=(k->rc->bja*k->bjm+k->bja)%p;
	k->lc->sum*=k->bjm%p,k->rc->sum*=k->bjm%p;
	k->lc->sum+=(k->lc->r-k->lc->l+1)*k->bja;
	k->rc->sum+=(k->rc->r-k->rc->l+1)*k->bja;
	k->lc->sum%=p,k->rc->sum%=p;
	k->bjm=1;k->bja=0;
	return ;
}
void adda(data *k,int l,int r,int x)
{
	if(l<=k->l&&k->r<=r)
	{
		k->sum+=(k->r-k->l+1)*x;
		k->sum%=p;
		k->bja=(k->bja+x)%p;
		return ;
	}
	if(k->bja||k->bjm!=1) updata(k);
	int mid=(k->l+k->r)>>1;
	if(l<=mid) adda(k->lc,l,r,x);
	if(r>mid) adda(k->rc,l,r,x);
	if(k->lc!=NULL) k->sum=k->lc->sum;
	if(k->rc!=NULL) k->sum+=k->rc->sum;
	k->sum%=p;return ;
}
void addm(data *k,int l,int r,int x)
{
	if(l<=k->l&&k->r<=r)
	{
		k->sum*=x;
		k->sum%=p;
		k->bja=x*k->bja%p;
		k->bjm=k->bjm*x%p;
		return ;
	}
	if(k->bja||k->bjm!=1) updata(k);
	int mid=(k->l+k->r)>>1;
	if(l<=mid) addm(k->lc,l,r,x);
	if(r>mid) addm(k->rc,l,r,x);
	if(k->lc!=NULL) k->sum=k->lc->sum;
	if(k->rc!=NULL) k->sum+=k->rc->sum;
	k->sum%=p;return ;
}
LL query(data *k,int l,int r)
{
	if(l<=k->l&&k->r<=r) return k->sum%p;
	if(k->bja||k->bjm!=1) updata(k);
	int mid=(k->r+k->l)>>1;
	LL tot=0;
	if(l<=mid) tot=(tot+query(k->lc,l,r))%p;
	if(r>mid) tot=(tot+query(k->rc,l,r))%p;
	return tot%p;
}
int main()
{
	int x,y,z,k;
	n=read(),p=read();
	build(tree,1,n);
	m=read();
	while(m--)
	{
		k=read();
		if(k==1)
		{
			x=read(),y=read(),z=read();
			addm(tree,x,y,z);
		}
		else if(k==2)
		{
			x=read(),y=read(),z=read(); 
			adda(tree,x,y,z);
		}
		else {
			x=read(),y=read();
			printf("%lld\n",query(tree,x,y));
		}
	}
	return 0; 
}
