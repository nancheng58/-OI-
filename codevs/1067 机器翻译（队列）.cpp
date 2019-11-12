#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int m,n,tot;
bool flag;
int s[10100],head,tail;
//queue<int>s;
int main()
{
	int x;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	  {
		cin>>x;
		flag=0;
		for(int j=head+1;j<=tail;j++)
		{
			if(s[j]==x)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			tail++;
			s[tail]=x;
			tot++;
			if(tail-head>m)
			{
			  head++;
			}
		      
		}
		
	}
	cout<<tot;
	return 0;
}
