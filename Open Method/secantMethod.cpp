#include<bits/stdc++.h>
using namespace std;
#define eps 1e-4
double get_fx(double x)
{
	return (x-4.0D)*(x-4.0D)*(x+2.0D);
}

void solve(double x0 , double x1)
{
	int it = 0;
	double x2 = x1;
	cout<<fixed<<setprecision(7)<<it++<<" "<<x1<<" "<<get_fx(x0)<<" "<<get_fx(x1)<<endl;
	x1 = x0;
	do
	{
		x0 = x1;
		x1 = x2;
		x2 = x1 - ((get_fx(x1)*(x1-x0))/(get_fx(x1)-get_fx(x0)));
		cout<<fixed<<setprecision(7)<<it++<<" "<<x2<<" "<<get_fx(x1)<<" "<<get_fx(x2)<<" "<<fabs(x2-x1)/fabs(x2)<<endl;
	}
	while((fabs(x2-x1)/fabs(x2))>= eps);
}

int main()
{
	solve(2.5D , -1.0D);
	return 0;
}
