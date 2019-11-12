#include<iostream>
using namespace std;
int main()
{
	bool q[100]={0};
	int a[100],n,m,i,t=0,z=0,chu=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	   a[i]=i;
	while(n!=z)
	{
		t++;
		if(t==n+1) t=1;//圈 
		if(q[t]==0)//活着的 
		{chu++;//计数 
		if(chu==m)
		{cout<<t<<" ";
		 q[t]=1;
		 chu=0;
		 z++;
		}
	}}
	return 0;
}
