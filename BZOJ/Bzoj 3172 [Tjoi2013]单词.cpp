/*
fail��.
һ��ʼû�����AC�Զ�����ô��.
ԭ����fail������.
��Ϊfailָ����һ���ܺõ�����
����ĳ���ִ��ĺ�׺����failָ��λ�õ�ǰ׺.
��ô��Ȼ��p����� > p->fail .
����bfs��ʱ����һ���Ѿ�����õ���ȹ�ϵ.
��ô���ǵ�����Ӱѹ���ת�Ƹ������и�����ǰ׺���ͺ���.
��ôĳ���ַ����𰸵Ĺ��׾���Դ��������.
case 1:��ô�ǰ׺��ͬ���ִ�����.
case 2:��ô�ǰ׺��ͬ���ִ�����.
����case 1,���ǿ����ڽ�trie��ʱ��ֱ�������.
	case 2 ����ͳһ�ѹ���ת�Ƹ�ǰ׺��. 
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
