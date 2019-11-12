#include<iostream>
#include<cstdio>
#define MAXN 1001
using namespace std;
int n,tot,a[MAXN],stack[MAXN];
void slove(int n)
{
	int i=0,stack[MAXN]={0},top=0;
	while(n)//ÕÒÖ¸Êý
	{
		if(n&1)
		stack[++top]=i;
		n>>=1;
		i++;
		
	}
	for(int i=top;i>0;i--)
	{
		if(!stack[i]) printf("2(0)");
		else if(stack[i]==1) printf("2");
		else if(stack[i]==2) printf("2(2)");
		else
		{
			printf("2(");
			slove(stack[i]);
			printf(")");
		}
		if(i>1) printf("+");
	} 
}
int main()
{
	cin>>n;
	slove(n);
	return 0;
}
