/*
����ջ+ģ�� 
���������ζ�ȡ��ǰţ�ĸ߶ȣ�
��ջ����ʼ�Ѹ߶�С�ڻ���ڵ�ǰţ�ĸ߶ȵ���ЩԪ��ɾ����
��ʱջ��ʣ�µ�Ԫ�ص��������ǿ��Կ�����ǰţ������ţ������.
�������������һ��
�Ϳ��Եõ����Ĵ���.
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
