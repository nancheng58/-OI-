#include<bits/stdc++.h>
#define MAXN 91
using namespace std;
long long f[MAXN];
int main()
{
	int n;
	f[1]=1;f[2]=2;
	cin>>n;
	for(int i=3;i<=n;i++)  f[i]=f[i-1]+f[i-2];
	cout<<f[n];
	return 0;	
}
