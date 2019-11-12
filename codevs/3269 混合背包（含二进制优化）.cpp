#include<iostream>
using namespace std;
int i,n,k,l;
int v[201],w[201],m[201],vz[20001],wz[20001],f[200001],tot;
void yh()//二进制优化
{
	for(int i=1;i<=n;i++)
	  {
	  	if(m[i]>1)
		  {
		  	for(int j=1;j<=m[i];j<<=1)
		  	{
		  		vz[++tot]=v[i]*j;
		  		wz[tot]=w[i]*j;
		  		m[i]-=j;
			}
			if(m[i])
			{
				vz[++tot]=v[i]*m[i];
				wz[tot]=w[i]*m[i];
			}
		   } 
		}
}
int main()
{
	int V;
	cin>>n>>V;
	for(i=1;i<=n;++i)
	{
		cin>>v[i]>>w[i]>>m[i];
	}
	yh();
	for(i=1;i<=n;++i)
	{
		if(m[i]==-1)
		{
			for(int j=v[i];j<=V;++j)
			  f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	}
	for(int i=1;i<=tot;i++)
	{
		for(int j=V;j>=vz[i];j--)
		{
			f[j]=max(f[j],f[j-vz[i]]+wz[i]);
		}
	}
	cout<<f[V];
	return 0;
}
