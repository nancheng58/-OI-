#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int n,l,a[1001],b[1001];
string s; 
int jd()
{
	for(int i=1;i<=l;i++)
      if(a[i]!=a[l-i+1])
	    return false;
  	return true;
}
void  change()
{
	for(int i=1;i<=l;i++)
	  b[i]=a[l-i+1];
	for(int i=1;i<=l;i++)
	  a[i]+=b[i];
	for(int i=1;i<=l;i++)
	{
	  a[i+1]+=a[i]/n;
		a[i]%=n;
	} 
	if(a[l+1]>0) l++;
}
int main()
{
	cin>>n>>s;
	l=s.length();
	for(int i=1;i<=l;i++)//½øÖÆ 
	{
	  if(s[l-i]>='0'&&s[l-i]<='9')
	    a[i]=s[l-i]-'0';
    else a[i]=s[l-i]-'A'+10;
	}
	if(jd())
	  {
	  	cout<<0;
	  	exit(0);
	  } 
	int i=0;
	for(;i<=30;)
	{
		i++;
		change();
		for(int j=1;j<=l;j++)
		  cout<<a[j];
		  cout<<endl;
		if(jd())
		{
			cout<<"STEP="<<i;
			exit(0);
		}
	}  
	cout<<"Impossible!";
	return 0;
}
