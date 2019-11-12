/*
经过多次试验： 
scanf大法好(快哭了) 
*/
#include<iostream>
#include<cstdio>
#define MAXN 1000001
using namespace std;
int n,m,tot;
struct data
{
	int lch;
	int rch;
	int val;
}
tree[MAXN];
void Add_tree(int &now,int x)//建树 
{
	if(!now)
	{
		tot++;
		now=tot;
		tree[now].val=x;
		return;
	}
	if(x<tree[now].val) Add_tree(tree[now].lch,x);
	if(x>tree[now].val) Add_tree(tree[now].rch,x);
}
bool find(int now,int x)//递归查找
{
	if(tree[now].val==x)
	  return 1;
	if(x<tree[now].val) 
	{
		if(tree[now].lch)
		find(tree[now].lch,x);
		else return 0;
	}
	if(x>tree[now].val) 
	{
		if(tree[now].rch)
		find(tree[now].rch,x);
		else return 0;
	}
}
int main()
{
	int x,root=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		Add_tree(root,x);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		printf("%d ",find(root,x));
	}
	return 0;
} 
