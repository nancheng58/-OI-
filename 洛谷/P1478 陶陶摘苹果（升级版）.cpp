#include<iostream>
using namespace std;
struct data
{
	int h;
	int v;
} 
s[5001];
int f[1001];
int main()
{
	int n,m,aa,bb,tot;
	cin>>n>>m;
	cin>>aa>>bb;
	tot=aa+bb;
	for(int i=1;i<=n;i++)
	  cin>>s[i].h>>s[i].v;
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=s[i].v;j--)
	{
		if(tot>=s[i].h)
		f[j]=max(f[j],f[j-s[i].v]+1);
	}
	cout<<f[m];
	return 0;
}
