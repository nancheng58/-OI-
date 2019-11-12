//判断是否回环，若不回环输出回环的节点数
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
int a[10001][10001],last[maxn],earl[maxn],n,e,q[maxn],head,tail,tot,id[maxn];
int main()
{
	cin>>n>>e;
	int x,y,w;
	for(int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
		id[y]++;
	}
	for(int i=1;i<=n;i++)//topo 
	{
		if(!id[i])
		    q[++tail]=i;
	}
	//earl[q]=0;
	while(head<tail)
	{
		int k=q[++head];
		for(int i=1;i<=n;i++)
		{
			
			if(a[k][i]==1)
			{
			    --id[i];
				if(id[i]==0)
				q[++tail]=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(q[i])  tot++;
	}
	if(tot==n) cout<<"o(∩_∩)o";
	else cout<<"T_T"<<endl<<n-tot;
	return 0;
}


