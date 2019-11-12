#include<bits/stdc++.h>
using namespace std;
const double pi=3.141592654;
int tot;
int main()
{
	double ss,a,b,x=1.0,s=0;
	cin>>a>>b;
	if(b<0) b=-b;
	ss=a*b;
	while(1)
	{
		s+=50.0;
		double r=sqrt(2.0*s/pi);
		//s=x*50.0*x*50.0*0.25*pi;
		if(r>=a&&r>=b) break;
		x++;
	}
	printf("%f",x);
	return 0;
}
