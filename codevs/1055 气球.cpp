/*
无辜70分明明in and out相同 
*/
#include<bits/stdc++.h>
#define MAXN 10001+20
#include<cstring>
#define mod 10013
using namespace std;
map<int,string>g;
struct data
{
	int hash;
	int tot;
	string s;
	char ch;
}
f[MAXN];
int sum;
int hash(string s)
{
	long long tot=0;
	for(int i=0;i<s.length();i++)
	{
		tot+=(s[i]-96);
	}
	return tot%mod;
}
int cmp(const data &x,const data &y)
{
	if(x.tot!=y.tot)
	return x.tot>y.tot;
	if(int (x.ch)!=int (y.ch))
	return int(x.ch)<int(y.ch);
	if(int ((x.s).length())!=int ((y.s).length()))
	return (x.s).length()<(y.s).length();
	
}
int main()
{
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int x=hash(s);
		f[x].s=s;
		f[x].ch=s[0];
		f[x].hash=x;
		f[x].tot++;
		g[x]=s;
	}
	sort(f+1,f+MAXN,cmp);
	for(int i=1;i<=n;i++)
	{
		if(f[i].tot) sum++;
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;i++)
	{
		if(f[i].tot)
		{
		if(f[i].tot!=f[i-1].tot)
		printf("%d\n",f[i].tot);
		cout<<g[f[i].hash];
		printf("\n");
		}
	}
	return 0;
}
