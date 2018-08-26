#include<bits/stdc++.h>
using namespace std;


#define eps 1e-4

double get_fx(double x)
{
	//cout<<(x-4.0D)*(x-4.0D)*(x+2.0D)<<" "<<x<<endl;
	return (x-4.0D)*(x-4.0D)*(x+2.0D);
}

double get_f1x(double x)
{
	return 2.0D*(x-4.0D)*(x+2.0D) + (x-4.0D)*(x-4.0D);
}

void solve(double x)
{
	int it = 0;
	double x1 = x;
	cout<<fixed<<setprecision(12)<<it++<<" "<<x<<" "<<get_fx(x)<<" "<<get_f1x(x)<<endl;
	do
	{
		x = x1;
		x1 = x - get_fx(x)/(get_f1x(x));
		cout<<fixed<<setprecision(12)<<it++<<" "<<x1<<" "<<get_fx(x1)<<" "<<get_f1x(x1)<<" "<<fabs(x1-x)/fabs(x1)<<endl;
	}
	while(fabs((x1-x)/fabs(x1))>= eps);
}

int main()
{
	solve(-2.3D);
	return 0;
}
