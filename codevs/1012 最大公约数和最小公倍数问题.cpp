//最大公约数*最小公倍数=两数之积 
#include <iostream>
#include <cmath>
using namespace std;
int gcd(int m,int n) //求最大公约数 
{
int temp;
do {
temp = m%n;
m = n;
n = temp;
}
while (temp!=0);
return m;
}
int main() 
{
int x,y,k1,k2,a,count = 0;//k1*k2=x/y=a,count计数 
cin>>y>>x;
if(x%y==0)
 {
a = x/y;
for(k1=1;k1<=a;k1++) {
if(a%k1!=0) continue;
else 
k2 = a/k1;
if(gcd(k1,k2)==1) count++;
}
}

cout<<count;
return 0;
}
