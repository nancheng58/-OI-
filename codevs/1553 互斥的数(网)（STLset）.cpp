#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<set>
#define MAXN 100001
int a[MAXN],tot;
using namespace std;
set<long long>f;
int main()
{
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);  
	for(int i=1;i<=n;i++)
	  {
	  	if(!f.count(a[i]))
	  	{
	  		tot++;
	  		f.insert(a[i]*m); 
		}
	}
	cout<<tot;
	return 0;  
}
