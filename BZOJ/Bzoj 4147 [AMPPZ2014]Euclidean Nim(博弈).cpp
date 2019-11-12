/*
������.
  ������d=gcd(p,q),���d������n,����չŷ�������Ȼ�޽⡣
  �н�����:
  �� p=q ����Ȼ���ֱ�ʤ�� 
  �� p>q&&n<p �����ֵ�һ��������p�����ֿ��԰��������n%q������������Զ�޷�ȡʯ�ӣ����ֱ�ʤ�� 
  �� p>q&&n>=p ��������ֵ�һ��ȡ��ʯ�ӣ�ʯ����������p�����ֻ��ǿ��԰��������n%q�����ֱ�ʤ��
       ��������ȡ��n mod p -> ����+q -> ����?p -> ����+q -> ���������n%(p-q)=0�������ֱ�ʤ��
  �� p<q&&n<p �����ֵ�һ�ΰ��������n+p�����n+p<q���ͱ���˵ڶ�������������ǵ����������
  �� p<q&&n>=p ����ô���ֿ��԰�ʯ�ӱ��n%p���ͱ���˵ڶ�������� 
ճ��zjk��2333. 
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
