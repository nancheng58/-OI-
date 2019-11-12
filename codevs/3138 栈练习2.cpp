#include<iostream>
#include<cstdio>
#include<algorithm>
//#include<vector>
#include<stack>

using namespace std;
int main()
{stack<int>g;
	int n;
	cin>>n;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x==1)
		{
			cin>>y;
			g.push(y);
		}
		else
		{
			
			if(g.empty())
			{
				cout<<"impossible!";
				return 0;
			}
			g.pop();
	  
		}
	}
	if(g.empty())
	  cout<<"impossible!";
	else cout<< g.top();
	return 0;
}
