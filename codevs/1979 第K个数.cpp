#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAXN 10001
using namespace std;
int a[MAXN];
bool jd(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	int x=a[n+1-m]-a[m];
	if(jd(x)&&x>0)
	  cout<<"YES"<<endl;
	else
	  cout<<"NO"<<endl;
	cout<<x;
	return 0;    
}
