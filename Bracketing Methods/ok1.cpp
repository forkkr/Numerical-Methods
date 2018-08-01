#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
double eps = 0.00001;
long long fact(long long n)
{
    long long ret = 1;
    for(long long i = 2; i <= n; i++)
    {
        ret *=i;
    }
    return ret;
}

double f(double x , long long n)
{

    double ret = x/2.0D;
    ret = pow(ret , n);
    double lob , hor;
    double sum = 0.0D;
    for(long long k = 0; k <= 10; k++)
    {
        lob =  pow(-1 , k);
        double tmp = pow(x , 2.0D);
        tmp = tmp/4.0D;
        lob = lob*pow(tmp , k);
        hor = fact(k);
        hor = hor*(fact(n+k));
        sum = sum + (lob/hor);
    }
    ret = ret*sum;
    return ret;
}


void solve(double x0 , double x1)
{
    double lo=-100, hi=0 ,mid;
    if(f(x0 , 0) > 0)
    {
        lo = x0;
        hi = x1;
    }
    else
    {
        lo = x1;
        hi = x0;
    }
    double past=0, cnt = 0;
    mid=(lo+hi)/2.0D;
    double r=f(mid , 0);
    cout<<"iterations "<<"Upper Lower Xm f(Xm) Relative Appr. Error"<<endl;
    cout<<cnt++<<fixed<<setprecision(06)<<" "<<lo<<" "<<hi<<" "<<mid<<" "<<r<<" "<<"N/A"<<endl;
    if(f(mid , 0)*f(lo , 0)>0)
        lo=mid;
    else if(f(mid , 0)*f(hi , 0)>0)
        hi=mid;
    do
    {
        past = mid;
        mid=(lo+hi)/2;
        double r=f(mid , 0);
        if(f(mid , 0)*f(lo , 0)>0)
            lo=mid;
        else if(f(mid , 0)*f(hi , 0)>0)
            hi=mid;
        double rerror= fabs(mid-past)/mid;
        cout<<cnt++<<fixed<<setprecision(06)<<" "<<lo<<" "<<hi<<" "<<mid<<" "<<r<<" "<<rerror<<endl;
       // cout<<fixed<<setprecision(6)<<rerror<<endl;
        //cout<<fixed<<setprecision(6)<<mid<<endl;
        //cout<<cnt++<<endl;
    }
    while(fabs(mid-past)/mid >= eps);
}



int main()
{
    double x0 , x1;
    cout<<"Upper and Lower: "<<endl;
    cin>>x0;
    cin>>x1;
    cout<<"Tolerance: "<<endl;
    cin>>eps;
    solve(x0 , x1);
}
