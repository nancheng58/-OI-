#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
long long aa[200001];
struct node
{
    int left,right;
    long long sum,ad;
};
node t[1000001];
void build(int i,int a,int b)
{
    t[i].left=a;
    t[i].right=b;
    t[i].ad=0;
    if(a==b)
    {
      t[i].sum=aa[a];
      return;
      }
    int mid=(a+b)/2;
    if(b>a)
    {
      build(2*i,a,mid);
      build(2*i+1,mid+1,b);
      }
    t[i].sum=t[2*i].sum+t[2*i+1].sum;
    return;
}
void tj(int i,int a,int b,int k)
{
    if(t[i].left==a&&t[i].right==b)
    {
      t[i].ad+=k;
      return;
      }
    t[i].sum+=(b-a+1)*k;
    int mid=(t[i].left+t[i].right)/2;
    if(b<=mid)
      tj(2*i,a,b,k);
    if(a>mid)
      tj(2*i+1,a,b,k);
    if(b>mid&&a<=mid)
    {
      tj(2*i,a,mid,k);
      tj(2*i+1,mid+1,b,k);
      }
    return;
}
long long qq(int i,int a,int b)
{
    int mid=(t[i].left+t[i].right)/2;
    if(t[i].ad&&t[i].right!=t[i].left)
    {
      tj(2*i,t[i].left,mid,t[i].ad);
      tj(2*i+1,mid+1,t[i].right,t[i].ad);
      }
    t[i].sum+=(t[i].right-t[i].left+1)*t[i].ad;
    t[i].ad=0;
    if(t[i].left==a&&t[i].right==b)
      return t[i].sum;
    t[i].ad=0;
    if(b<=mid)
      return qq(2*i,a,b);
    if(a>mid)
      return qq(2*i+1,a,b);
    if(b>mid&&a<=mid)
      return qq(2*i,a,mid)+qq(2*i+1,mid+1,b);
}
int main()
{
    int n,i,j,tt,q;
    char k;
    cin>>n;
	cin>>q;
    for(i=1;i<=n;i++)
      scanf("%d",&aa[i]);
    build(1,1,n);
    while(q)
    {
      scanf("%c",&k);
      if(k=='\n')
        cin>>k;
	  if(k=='C')
      {
        scanf("%d%d%d",&k,&tt,&j);
        tj(1,k,tt,j);
        }
      else
      {
        scanf("%d%d",&k,&tt);
        cout<<qq(1,k,tt);
        if(q!=1)
          cout<<endl;
        }
      q--;
      }
    return 0;
}
