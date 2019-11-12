#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int m,n,tot;
bool flag;
queue<int>s;
int main()
{
	int x;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	  {
	  	flag=0;
	  	cin>>x;
	  	//for(int j=0;j<=s.size();j++)
	  	int n=find(s.cbegin(),s.cend(),x);
		  {
		  //if(x==s[j])
		  	if(n==s.cend())
	  		{
	  			tot++;
	  			flag=1;
			}
			else
			{
				s.push(x);
			}
	  	}
	  	//if(!flag)
	  	if(s.size()>m)
	  	  s.pop();
	  }
	  cout<<tot;
	  return 0;
}
