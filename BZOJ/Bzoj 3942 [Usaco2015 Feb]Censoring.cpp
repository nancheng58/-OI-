/*
kmp+栈模拟.
先将t串自匹配.
然后将s与t串匹配.
又是fail数组的套路题orz. 
*/
#include<cstring>
#include<cstdio>
#define MAXN 1000001
using namespace std;
int l1,l2,top,next[MAXN],fail[MAXN];
char s1[MAXN],s2[MAXN],ans[MAXN];
void slove()
{
	int p;
	for(int i=2;i<=l1;i++)
	{
		p=next[i-1];
		while(p&&s2[i]!=s2[p+1]) p=next[p];
		if(s2[i]==s2[p+1]) p++;
		next[i]=p;
	}
}
void kmp()
{
	int p;
	for(int i=1;i<=l1;i++)
	{
		ans[++top]=s1[i];
		p=fail[top-1];
		while(p&&ans[top]!=s2[p+1]) p=next[p];
		if(ans[top]==s2[p+1]) p++;
		fail[top]=p;
		if(p==l2) top-=l2;
	}
	for(int i=1;i<=top;i++) printf("%c",ans[i]);
}
int main()
{
	scanf("%s",s1+1);l1=strlen(s1+1);
	scanf("%s",s2+1);l2=strlen(s2+1);
	slove();kmp();
	return 0;
}
