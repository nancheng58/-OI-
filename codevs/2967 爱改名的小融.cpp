#include<iostream>
using namespace std;
string s[1001];
bool flag=0;
int main()
{
	int n,r,w;
	cin>>n;
	for(int i=1;i<=n;i++)
	  {
	  	flag=0;
	  	cin>>s[i];
	  int l=s[i].length();
	  	for(int j=0;j<=l;j++)
	  {
	  	if(s[i][j]=='R')
	  	  {
	  	  	r=j;
	  	  for(int q=r+1;q<=l;q++)
	  	  {
	  	  	if(flag)
	  	  	  break;
	  	  	if(s[i][q]=='K')
	  	  	  {
	  	  	  	w=q;
	  	  	  for(int z=w+1;z<=l;z++)
	  	  	  {
	  	  	  	if(s[i][z]=='Y')
	  	  	  	{
	  	  	  		cout<<"YES"<<endl;
	  	  	  		flag=1;
	  	  	  		break;
				}
			}
			  }
			}
	  		}
			}
	  if(!flag)
	    cout<<"NO"<<endl;
	  }
	return 0;   
}
