#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000010
using namespace std;
int n,k,h[maxn],f[maxn],Q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&h[i]);
	scanf("%d",&Q);
	while(Q--)
	  {
	  	scanf("%d",&k);
	  	memset(f,127/3,sizeof(f));
	  	f[1]=0;
	  	for(int i=1;i<=n;i++)
	  	  for(int j=i-k;j<i;j++)
	  	    {
	  	      if(j<=0)continue;
			  if(h[i]>=h[j])f[i]=min(f[i],f[j]+1);
			  if(h[i]<h[j])f[i]=min(f[i],f[j]);
			}
		printf("%d\n",f[n]);
	  }
	return 0;
}
