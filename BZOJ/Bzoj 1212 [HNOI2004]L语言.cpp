/*
AC自动机+DP.
令f[i]表示能否匹配到i位置.
如果f[i]能匹配,则f[i-word_len]能匹配.
转移就好. 
*/
#include<queue>
#include<cstdio>
#include<cstring>
#define MAXN 210
using namespace std;
int n,m,len[MAXN],fail[MAXN],f[1100000],tot=1,l,lastmark,pos[MAXN];
struct data{int x[27],b;}tree[MAXN];
bool mark[MAXN];
char s[1100000];
queue<int>q;
void add(int t)
{
	int now=1;l=strlen(s+1);len[t]=l;
	for(int i=1;i<=l;i++)
	{
		int x=s[i]-96;
		if(!tree[now].x[x]) tree[now].x[x]=++tot;
		now=tree[now].x[x];
	}
	tree[now].b=1;pos[now]=t;
	return ;
}
void get_fail()
{
	for(int i=1;i<=26;i++) tree[0].x[i]=1;
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();q.pop(); 
		for(int i=1;i<=26;i++)
		{
			if(!tree[now].x[i]) continue;
			int k=fail[now];
			while(!tree[k].x[i]) k=fail[k];
			k=tree[k].x[i];
			fail[tree[now].x[i]]=k;
			q.push(tree[now].x[i]);
		}
	}
	return ;
}
void Mark()
{
	l=strlen(s);int now=1;
	for(int i=0;i<l;i++)
	{
		int x=s[i]-96;
		while(!tree[now].x[x]) now=fail[now];
		now=tree[now].x[x];
		int k=now;
		while(k)
		{
			f[i+1]|=f[i-len[pos[k]]+1];
			k=fail[k];
		}
	}
}
int main()
{
	freopen("language.in","r",stdin);
	freopen("language.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s+1),add(i);
	get_fail();
	while(m--)
	{
		lastmark=0;
		memset(f,0,sizeof f);
		memset(mark,0,sizeof mark);
		scanf("%s",s);
		f[0]=1;Mark();
		for(int i=strlen(s);i>=0;i--)
		  if(f[i]) {printf("%d\n",i);break;}
	}
	return 0;
}
