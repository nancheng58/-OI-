#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define MANX 10001 
using namespace std;
int tot;
vector<bool>g(1);
//int g[MAXN][MAXN];
int main()
{
	int n;
	char a,b,c;
	g[1]=1; 
	//g.at(1)=1;
	cin>>n;
	for(int i=1;i<=n;i++)
    {
    	cin>>a>>b>>c;
    	int x=a-96;
    	int y=c-96;
		if(g[y]) g[x]=1;
		else g[x]=0; 
    }
    for(int i=1;i<=26;i++)
    {
    	if(g[i]) 
    	cout<<char(i+96)<<" ",tot=1;
    }
    if(!tot)
      cout<<"none";
    return 0;  
}
