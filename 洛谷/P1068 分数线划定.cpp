#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int tot;
int main()
{
	struct da
	{
		int xh;
		int fs;
	}
	data[10000];
	int n,m,s,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>data[i].xh>>data[i].fs;
	}
	for(int i=1;i<=n-1;i++)
	  for(int j=1;j<=n-i;j++)
	  {
	  	if(data[j].fs<data[j+1].fs)
	  	{
	  		t=data[j].fs;
	  		data[j].fs=data[j+1].fs;
	  		data[j+1].fs=t;
	  		s=data[j].xh;
	  		data[j].xh=data[j+1].xh;
	  		data[j+1].xh=s;
		  }
		  if(data[j].fs==data[j+1].fs&&data[j].xh>data[j+1].xh)
		    {
		    	swap(data[j].xh,data[j+1].xh);
			}
	  }
	  int q=floor(m*1.5);
	  int k=data[q].fs;
	  
	  for(int i=1;i<=n;i++)
	   if(data[i].fs>=k)
	   {
	   	tot++;
	   }cout<<k<<" "<<tot<<endl;
	 for(int i=1;i<=n;i++)
	   if(data[i].fs>=k)
	   {
	   	cout<<data[i].xh<<" "<<data[i].fs<<endl;
	   }
	   return 0;
}
