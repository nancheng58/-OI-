#include<iostream>
#include<cstdio>
using namespace std;
int n,x,y;
int a[40][40];
int main()
{
	cin>>n;
	int k=1;
	a[1][(n+1)/2]=1;
	for(int i=1;i<=n*n;i++)
	  {
	  	k++;
	  	for(int j=1;j<n;j++)
	  {
	  	if(k-1==a[1][j]) 
		  {
		  	a[n][j+1]=k;
		  	x=n;y=j+1;
		  	break;
		  }
		 
	  }
	  if(a[n][y+1]==k) continue;
	  if(k-1==a[1][n])
	  {
	  	a[2][n]=k;
	  	x=2;y=n;
	  	continue;
	  }
	  if(a[x][y]==k) continue;
	   	for(int j=2;j<=n;j++)
	  {
	  	if(k-1==a[j][n]) 
		  {
		  	a[j-1][1]=k;
		  	x=j-1;y=1;
		  	break;
		  }
	  }if(a[x][y]==k) continue;
	  	if(!a[x-1][y+1]&&y+1<=n)
		   {
		   	a[x-1][y+1]=k;
		   	x=x-1;
		   	y=y+1;
		   	continue;
		   }
	  	else if(!a[x+1][y]&&x+1<=n)
	  	 {
	  	 	a[x+1][y]=k;
	  	 	x=x+1;
	  	 	continue;
		   }
	  }for(int i=1;i<=n;i++)
	  {
	  	
	  	for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		printf("\n");
		}
	  
		return 0;
}
