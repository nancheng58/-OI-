#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int ans[1000001],a[1000001],n,len;
int find(int i)
{
int l=0,r=len,num;
while (l!=r)
{
int mid=(l+r)/2;
if (ans[mid]>=a[i]) r=mid;
else l=mid+1;
}
return l;
}
int main()
{
scanf("%d",&n);
for (int i=1;i<=n;i++) scanf("%d",&a[i]);
ans[1]=a[1];  //长度为1的上升子序列的最末元素就是他本身   
len=1;
for (int i=2;i<=n;i++)
if (a[i]>ans[len])  
ans[++len]=a[i];
else 
{
int pos=find(i);
ans[pos]=a[i];
}
printf("%d\n",len);
}
