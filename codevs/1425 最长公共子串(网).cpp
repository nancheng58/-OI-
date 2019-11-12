#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 50;
int n,h = 0,t = 0,s;
string q[maxn];
string lcs(string a,string b)
{
	string c = "";
	int i = a.size(),j = b.size();
	int dp[maxn][maxn];
	memset(dp,0,sizeof(dp));
	for(int r1 = 1;r1 <= i;r1++){
		for(int r2 = 1;r2 <= j;r2++){
			if(a[r1] == b[r2])//ÈôÏàµÈ 
			{
				dp[r1][r2] = dp[r1 - 1][r2 - 1] + 1; 
			}
			else
			{
			dp[r1][r2] = max(dp[r1 - 1][r2],dp[r1][r2 - 1]);
}
}
}
int rec = dp[i][j] - 1;
for(int r1 = 1;r1 <= i;r1++)
{
for(int r2 = 1;r2 <= j;r2++)
{
	
}
}
i--;
j--;
while(i >= 0 && j >= 0)
{
	if(a[i] == b[j]){
	c.insert(c.begin(),a[i]);
	rec--;
	i--;
	j--;
}	else{
   if(i == 0) j--;
    else if(j == 0) i--;
    else{
        if(dp[i-1][j] < dp[i][j-1]) j--;
        else i--;
            }
}
}
return c;
}
int main()
{
	cin>>n;
	s = t = n;
	for(int i = h;i < t;i++)
	{
	cin>>q[i];
	}
	while(s > 1)
	{
	q[t] = lcs(q[h],q[h + 1]);
	t++;
	h = h + 2;
	s--;
	}
	while(q[h] == "") h--;
	cout<<q[h];
	return 0;
}


