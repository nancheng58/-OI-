/*
博弈题.
  首先令d=gcd(p,q),如果d不整除n,由扩展欧几里得显然无解。
  有解的情况:
  ① p=q ：显然先手必胜。 
  ② p>q&&n<p ：先手第一次数量加p，后手可以把数量变成n%q，这样先手永远无法取石子，后手必胜。 
  ③ p>q&&n>=p ：如果先手第一次取完石子，石子数量大于p，后手还是可以把数量变成n%q，后手必胜；
       否则，先手取成n mod p -> 后手+q -> 先手?p -> 后手+q -> ……，如果n%(p-q)=0，则先手必胜。
  ④ p<q&&n<p ：先手第一次把数量变成n+p，如果n+p<q，就变成了第二种情况，否则是第三种情况。
  ⑤ p<q&&n>=p ：那么先手可以把石子变成n%p，就变成了第二种情况。 
粘的zjk的2333. 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int t,n,p,q;
int gcd(int x,int y)
{
    if(!y) return x;
    return gcd(y,x%y);
}
bool check(int a,int b,int x)
{
    if(x%a<b&&(x%a)%(a-b)==0) return true;
    return false;
}
void slove()
{
    int g=gcd(p,q);
    if(n%g){printf("R\n");return ;}//1 
    p/=g,q/=g,n/=g;
    if(p==q) {printf("E\n");return ;}//2
    if(p>q&&n<p) {printf("P\n");return;}//3
    if(p>q&&n>=p)//4
    {
        if(check(p,q,n)) {printf("E\n");return ;}
        else {printf("P\n");return ;}
    }
    if(p<q&&n<p)//5
    {
        if(n+p<q) {printf("E\n");return ;}
        else if(check(q,p,n+p)) {printf("P\n");return ;}
        else  {printf("E\n");return ;}
    }
    if(p<q&&n>=p)  {printf("E\n");return ;}//6
    return ;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&p,&q,&n);
        slove();
    }
    return 0;
}
