#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int x,k=1,y,a[10000],b[10000],n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
    for(int j=1;j<=m;j++)
    {
      cin>>x>>y;
      for(int i=x;i<=y;i++)
        b[k]+=a[i];
		k++;
        
	}
	for(int q=1;q<k;q++)
	  cout<<b[q]<<endl;
	return 0;
	
}
