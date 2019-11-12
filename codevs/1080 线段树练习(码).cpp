#include<iostream>
#include<cstdio>
#define MAXN 1000000
using namespace std;
int sum[(MAXN<<1)+1];
int tot,l1,l2,w,m,n,z,x;
void up(int o,int l,int r)
{
	if(l==r)
	{
		sum[o]+=z;
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid) up(o*2,l,mid);
	else up(o*2+1,mid+1,r);
	sum[o]=sum[2*o]+sum[2*o+1];
}
void cz(int o,int l,int r)
{
	if(l>r)
	  return;
	if(l1<=l&&r<=l2)
	{
		tot+=sum[o];
		return ;
	  }
	int mid=(l+r)/2;
	if(l1<=mid) cz(o*2,l,mid);
	if(mid<l2) cz(o*2+1,mid+1,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  {
	  	cin>>z;
	  	x=i;
	  	up(1,1,n);
	  }
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>w;
		if(w==1)
		{
			cin>>x>>z;
			up(1,1,n);
		}
		else
		{
			cin>>l1>>l2;
			tot=0;
			cz(1,1,n);
			cout<<tot;
			printf("\n");
		}
	  }  
}
