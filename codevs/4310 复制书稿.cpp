#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[501],f[1001][1001],tot,ansn[501],ll;
int can(int s)
{
	int size=1,sum=0;
	int i;
	for(i=1;i<=n;i++)
	  {
	  	sum=sum+a[i];
	  	if(sum>s)
	  	  {
	  	  	sum=a[i];
	  	  	size++;
		  }
	  }
	if(size>m)return 1;
	else return 0;
}
int main()
{
	int i,j,ans;
	cin>>n>>m;
	if(n==0&&m==0)
	  {
	  	cout<<endl;
	  	return 0;
	  }
    for(i=1;i<=n;i++)
	  {
	  	cin>>a[i];
	  	tot=tot+a[i];
	  }
	int l,r=tot,mm;
	l=*max_element(a+1,a+n+1);
	while(l<=r)
	  {
	  	int mm=(l+r)/2;
	  	if(can(mm))l=mm+1;
	  	else 
		  {
		    r=mm-1;
		  	ans=mm;
		  }
      }
    int anss=ans;
    cout<<1<<" ";
    for(i=n;i>=1;i--)
      {
      	if(anss-a[i]<0)
      	  {
      	  	ansn[++ll]=i;
      	  	anss=ans-a[i];
		  }
      	else anss-=a[i];
	  }
	for(i=ll;i>=1;i--)
	  cout<<ansn[i]<<endl<<ansn[i]+1<<" ";
	cout<<n;
	return 0;
}
