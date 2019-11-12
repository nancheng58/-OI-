/*
单调栈+模拟 
从左到右依次读取当前牛的高度，
从栈顶开始把高度小于或等于当前牛的高度的那些元素删除，
此时栈中剩下的元素的数量就是可以看见当前牛的其他牛的数量.
把这个数量加在一起，
就可以得到最后的答案了.
*/
#include<bits/stdc++.h>
#define INF 1000000001
using namespace std;
stack<int>s;
int n,h,tot;
int main()
{
	cin>>n; 
	s.push(INF);
	for(int i=1;i<=n;i++){
		tot+=s.size()-1;
		scanf("%d",&h);
		while(h>s.top()) s.pop();
		s.push(h);}
	printf("%d",tot);
	return 0;
}
