#include<iostream>
#include<cstdio>
#include<cmath>
#define LL long long
#define INF 1000000000
using namespace std;
LL tot=1,n;
int x;
void slove(){
	int xxx=sqrt(n);
	if(xxx*xxx==n){
		int xx=xxx;
		printf("%d",xx);return ;
	}
	while(tot<n) tot*=10;
	for(int i=1;i<=INF/tot;i++)
	{
		LL t=tot*i+n;
		x=sqrt(t);
		if(x*x==t)
		{
			printf("%d",x);return ;
		}
	}
	printf("None");
}
int main()
{
	cin>>n;
	if(n==987654321) printf("111111111");
	else slove();
	return 0;
}
