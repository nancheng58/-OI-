#include<iostream>
using namespace std;
int n,x,tot;
int ys()
{
	int i;
	for(i=1;i<=n;i++)
	{
		int k=i;
		while(k)
		{
			int a=k%10;
			if(a==x) tot++;
			k/=10;
		}
	}
 	return tot;
	
}
int main()
{
	cin>>n>>x;
	cout<<ys();
	return 0;
}
