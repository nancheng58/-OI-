/*
gcd.
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,x,y,sum;
int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')  x=x*10+ch-48,ch=getchar();
	return x*f;
}
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main()
{
	int s,d;
	n=read();d=read();
	for(int i=2;i<=n;i++){
		s=read();
		d=gcd(s,d);
	}
	if(d<0) d*=-1;
	printf("%d",d);
	return 0;
}
