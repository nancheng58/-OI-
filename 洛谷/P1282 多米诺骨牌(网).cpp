#include<cstdio>
#include<cstdlib>
using namespace std;
int i,j,k,f[12001],a[1001],n,sum,t,now; 
//now��ʾ����ת�Ĳ�ֵ��a[i]��¼��i��������µ���֮�f[i]��ʾ�ﵽ��ֵΪi-t��״̬�������С����
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
    f[now+t]=1; //�����Ƚ���С����ͳһ����һ�������ж����״̬�Ƿ�ﵽ��
    for (i=0;i<n;i++)
      if (a[i]>0) //��������ۣ�����ֵ��ö��״̬�����෴����Ҫ��
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
    if (f[i]==0) printf("%d",f[j]-1);  //��Ϊ֮ǰͳһ������һ������Ҫ��
      else if (f[j]==0||f[i]<=f[j]) printf("%d",f[i]-1);
}
