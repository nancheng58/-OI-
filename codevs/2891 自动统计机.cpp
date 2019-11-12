#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double tot,a[10001];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	tot/=n;
	printf("%.6lf\n",tot);
	sort(a+1,a+n+1);
	if(n%2==0)
	  printf("%.6lf\n",(a[n/2]+a[n/2+1])/2);
	else 
	  printf("%.6lf\n",a[n/2+1]);
	return 0;
}
