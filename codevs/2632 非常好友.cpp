#include<iostream>
#include<cstdio>
using namespace std;
int jd(int n)
{
	int tot=0;
	for(int i=1;i<n;i++)
	if(n%i==0) tot+=i;
	return tot;
}
int main()
{
	int n,x,i;
	cin>>n;
	for(i=n;;i++)
	{
		x=jd(i);//ÅÐ¶¨ 
		if(jd(x)==i)//·´ÅÐ¶¨ 
		  break;
	}
	cout<<i<<" "<<x;
	return 0;
}
