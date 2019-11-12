#include<iostream>
using namespace std;
int tot;
int main()
{
	int n,a[100000],b[100000],l,i;
	bool t[100000]={0};
	cin>>l>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=a[i];j<=b[i];j++)
		{
			if(!t[j]) t[j]=1;
		}
	}
	for(i=0;i<=l;i++)
	{
		if(!t[i]) tot++;
	}
	cout<<tot;
	return 0;
}

