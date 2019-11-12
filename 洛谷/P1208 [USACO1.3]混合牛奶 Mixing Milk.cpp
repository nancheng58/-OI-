#include<iostream>
#include<algorithm>
using namespace std;
const int M=5005;
long n;
int m;
long sum=0;
struct data
{
    int p;
    long a;
}f[M];
void solve()
{
    for (int i=1; i<=m; i++)
    {
        if (n==0) break;
        if (f[i].a<=n)
        {
            n=n-f[i].a;
            sum+=f[i].a*f[i].p;    
        } 
        else 
        {
           sum+=f[i].p*n;
           n=0;
        }
    }
}
int cmp(const data & a,const data & b)
{
    return a.p<b.p;
}

void init()
{
    cin>>n;
    cin>>m;
    for (int i=1; i<=m ;i++)
    cin>>f[i].p>>f[i].a;    
    sort(f+1,f+m+1,cmp);
}
int main()
{
    init();
    solve();
    cout<<sum<<endl;
    return 0;
}
