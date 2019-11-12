#include<cstdio>
#include<cstdlib>
using namespace std;
int i,j,k,f[12001],a[1001],n,sum,t,now; 
//now表示不翻转的差值，a[i]记录第i块骨牌上下点数之差，f[i]表示达到差值为i-t的状态所需的最小步数
int main()
{
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        a[i]=j-k;
        if (a[i]<0) t-=a[i];
          else sum+=a[i];
        now+=a[i];
    }
    f[now+t]=1; //这里先将最小步数统一赋上一，方便判断这个状态是否达到过
    for (i=0;i<n;i++)
      if (a[i]>0) //分情况讨论，正负值的枚举状态方向相反，重要！
      {
        for (j=2*a[i];j<=sum+t;j++)
          if (f[j]>0&&(f[j-2*a[i]]==0||f[j-2*a[i]]>f[j]+1))
            f[j-2*a[i]]=f[j]+1;
            }
      else if (a[i]<0)
      {
        for (j=sum+t+2*a[i];j>=0;j--) 
          if (f[j]>0&&(f[j-2*a[i]]==0||f[j-2*a[i]]>f[j]+1))
            f[j-2*a[i]]=f[j]+1;
      }
    i=t; j=t;
while (f[i]==0&&f[j]==0) 
  {
          i++; j--;
    }
    if (f[i]==0) printf("%d",f[j]-1);  //因为之前统一加上了一，所以要减
      else if (f[j]==0||f[i]<=f[j]) printf("%d",f[i]-1);
}
