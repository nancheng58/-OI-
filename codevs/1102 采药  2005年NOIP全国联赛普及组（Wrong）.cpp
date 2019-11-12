#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct data
{
	int sj;
	int jz;
}
da[101];
int cmp(const data &x,const data &y)
{
	if(x.jz==y.jz)
	return x.sj<y.sj;
	return x.jz>y.jz;
}
int main()
{
	int t,m,tot=0,sx=0;
	cin>>t>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>da[i].sj>>da[i].jz;
	}
	sort(da+1,da+m+1,cmp);
	/*for(int i=1;i<=m;i++)
	{
		if(sx+da[i].sj<=t)
		{
		tot+=da[i].jz;
		sx=sx+da[i].sj;
		 } 
	}
	cout<<tot;
	*/
	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		cout<<da[i].sj<<" "<<da[i].jz;
		printf("\n");
	}
	return 0;
}
