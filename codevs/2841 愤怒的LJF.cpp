#include<iostream>
#include<cstdio>
using namespace std;
int tot,d[1001],w[1001],c[1001],f[100001];
int main()
{
	int n,m,t,p,s;
	cin>>n>>m>>t>>p>>s;
	for(int i=1;i<=n;i++)
	  cin>>c[i]>>d[i]>>w[i];
	for(int i=1;i<=n;i++)
	   for(int j=t;j>=0;j--)
	     {
	     	if(p>=d[i])
	     	  f[j]=max(f[j],f[j-c[i]]+w[i]);
	     }
   	int tot=m+f[t];
	if(tot>s)
	  {
	  	cout<<"YES"<<endl;
	  }
	else cout<<"NO"<<endl;
	cout<<tot;
	return 0;
}
