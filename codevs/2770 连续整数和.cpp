#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int r=n/m;
	//if(m%2==0)
	{
		int t=0;
		int i=r-(m-1)/2;
		while(t!=m)
		{
			cout<<i<<" ";
			i++;
			t++;
		}
		
		return 0;
	}

}
