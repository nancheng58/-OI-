#include <iostream>  
#include <cstdlib>  
#include <cstdio>  
#include<algorithm>  
using namespace std;  
int n,k,a[10001][3],f[10001];  
int main()  
{  
    cin>>n>>k;  
    for(int i=1;i<=k;i++)
	cin>>a[i][1]>>a[i][2];  
    for(int i=n;i>=1;i--)  
    { int po=0;                       //}从后往前，判断在该时刻有没有任务。  
      for(int j=1;j<=k;j++)              
      {  
         if(a[j][1]==i) //f[i] 如果在i时刻开始工作（此时空闲）的最大空闲时间。  
         {po=1;  
            f[i]=max(f[i],f[i+a[j][2]]);}  
      }  
      if(!po)f[i]=f[i+1]+1; //该i时刻没有任何一个任务 空闲时间多一点  
    }  
    cout<<f[1]<<endl;///cout
    return 0;  
}
