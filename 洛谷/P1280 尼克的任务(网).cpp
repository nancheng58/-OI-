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
    { int po=0;                       //}�Ӻ���ǰ���ж��ڸ�ʱ����û������  
      for(int j=1;j<=k;j++)              
      {  
         if(a[j][1]==i) //f[i] �����iʱ�̿�ʼ��������ʱ���У���������ʱ�䡣  
         {po=1;  
            f[i]=max(f[i],f[i+a[j][2]]);}  
      }  
      if(!po)f[i]=f[i+1]+1; //��iʱ��û���κ�һ������ ����ʱ���һ��  
    }  
    cout<<f[1]<<endl;///cout
    return 0;  
}
