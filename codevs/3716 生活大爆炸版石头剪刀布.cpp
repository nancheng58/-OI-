#include<bits/stdc++.h>
#define MAXN 40001
using namespace std;
int a[MAXN],b[MAXN],m,n1,n2,tota,totb;
int main()
{
	cin>>m>>n1>>n2;
	for(int i=1;i<=n1;i++)  cin>>a[i];
	for(int i=1;i<=n2;i++)  cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		a[n1+i]=a[i];
		b[n2+i]=b[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]==0)
		{
			if(b[i]==2||b[i]==3) tota++;
			else if(b[i]==1||b[i]==4) totb++;
		}
		if(a[i]==1)
		{
			if(b[i]==0||b[i]==3) tota++;
			else if(b[i]==2||b[i]==4) totb++;
		}
		if(a[i]==2)
		{
			if(b[i]==1||b[i]==4) tota++;
			else if(b[i]==0||b[i]==3) totb++;
		}
		if(a[i]==3)
		{
			if(b[i]==2||b[i]==4) tota++;
			else if(b[i]==0||b[i]==1) totb++;
		}
		if(a[i]==4)
		{
			if(b[i]==0||b[i]==1) tota++;
			else if(b[i]==2||b[i]==3) totb++;
		}
	}
	cout<<tota<<" "<<totb;
	return 0;
}
