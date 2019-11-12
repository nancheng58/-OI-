#include<iostream>
using namespace std;
string s;
int tot,k,a[1001];
bool b=0;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		b=0;
		int l=s.length();
		for(int j=0;j<l;j++)
		  {
		  	if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z');
		  	else
			  {
			  	b=1;
			  	break;
			}
		  }
		  if(!b)
		  {
		  	tot++;
		  	a[++k]=i;
		}
	}
	cout<<tot<<endl;
	for(int i=1;i<=k;i++)
	  cout<<a[i]<<" ";
	return 0;
}
