/*
fail树.
一开始没想出用AC自动机怎么做.
原来是fail树处理.
因为fail指针有一个很好的性质
就是某个字串的后缀等于fail指向位置的前缀.
那么显然的p的深度 > p->fail .
我们bfs的时候有一个已经处理好的深度关系.
那么我们倒序相加把贡献转移给文章中给定的前缀串就好了.
那么某个字符串答案的贡献就来源于两部分.
case 1:与该串前缀相同的字串个数.
case 2:与该串前缀不同的字串个数.
对于case 1,我们可以在建trie的时候直接算出来.
	case 2 我们统一把贡献转移给前缀串. 
*/
#include<cstring>
#include<cstdio>
#define MAXN 1000010
using namespace std;
int n,m,tot=1,l,fail[MAXN],ans[MAXN],p[201],q[MAXN];
char s[MAXN];
struct data{int x[27],b;}tree[MAXN];
void add(int t)
{
	l=strlen(s+1);int now=1;
	for(int i=1;i<=l;i++)
	{
		int x=s[i]-96;
		if(!tree[now].x[x]) tree[now].x[x]=++tot;
		now=tree[now].x[x];
		ans[now]++;
	}
	tree[now].b++;p[t]=now;
	return ;
}
void Build_fail()
{
	for(int i=1;i<=26;i++) tree[0].x[i]=1;
	int now=1,head=0,tail=0;
	q[++tail]=1;
	while(head<tail)
	{
		int now=q[++head];
		for(int i=1;i<=26;i++)
		{
			if(!tree[now].x[i]) continue;
			int k=fail[now];
			while(!tree[k].x[i]) k=fail[k];
			k=tree[k].x[i];
			fail[tree[now].x[i]]=k;
			q[++tail]=tree[now].x[i];
		}
	}
	for(int i=tail;i>=1;i--) ans[fail[q[i]]]+=ans[q[i]];
	return ;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s+1),add(i);
	Build_fail();
	for(int i=1;i<=n;i++) printf("%d\n",ans[p[i]]);
	return 0;
}
