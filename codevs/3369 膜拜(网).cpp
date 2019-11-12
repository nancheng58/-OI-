
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int sum1[3001],sum2[3001],f[3001];
int mi(int a,int b)
{
    if(a<b)
      return a;
    else
      return b;
}
int ab(int a)
{
    if(a>0)
      return a;
    else
      return -a;
}
int main()
{
    int n,m,i,j,k,t;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
      cin>>t;
      if(t==1)
      {
        sum1[i]=sum1[i-1]+1;
        sum2[i]=sum2[i-1];
        }
      if(t==2)
      {
        sum1[i]=sum1[i-1];
        sum2[i]=sum2[i-1]+1;
        }
      }
    for(i=1;i<=n;i++)
    {
      f[i]=i;
      for(j=i;j>=0;j--)
        if(sum1[i]-sum1[j]==i-j||sum2[i]-sum2[j]==i-j||ab(sum2[i]-sum2[j]-sum1[i]+sum1[j])<=m)
          f[i]=mi(f[j]+1,f[i]);
      }
    cout<<f[n];
    return 0;
}
