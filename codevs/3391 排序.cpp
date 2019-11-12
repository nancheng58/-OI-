#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	struct data
	{
		string ch;
		double a;
	}
	data[10001];
	int n,t;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	   cin>>data[i].ch>>data[i].a;	
	}
	for(int i=1;i<=n-1;i++)
	  for(int j=1;j<=n-i;j++)
	  {
	  	if(data[j].a<data[j+1].a)
	  	{
	  		t=data[j].a;
	  		data[j].a=data[j+1].a;
	  		data[j+1].a=t;
	  		s=data[j].ch;
	  		data[j].ch=data[j+1].ch;
	  		data[j+1].ch=s;
		  }
		  if(data[j].a==data[j+1].a&&data[j].ch>data[j+1].ch)
		  {
		  	swap(data[j].ch,data[j+1].ch);
		  }
	  }
	  for(int i=1;i<=n;i++)
	  {
	  	cout<<data[i].ch<<" "<<data[i].a<<endl;
	  }
	  return 0;
	
}
