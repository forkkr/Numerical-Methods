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

    double ret= (42 - 2.0D*x);
    ret = pow(ret , 2.0D);
    ret = ret*(28 - x);
    ret = (4 + x)/ret - 0.016;
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
    double past=0, cur=0 , cnt = 0;
    mid=(lo+hi)/2.0D;
    double r=f(mid , 0);
    //cout<<"iteration<<" "<<"upper"<<" "<<"lower"<<" "<<"Xm"<<" "<<"fxm"<<" "<<"error"<<endl;
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
        //cout<<fixed<<setprecision(6)<<rerror<<endl;
        //cout<<cnt++<<endl;
    }
    while(fabs(mid-past)/mid >= eps);
}



int main()
{

//     freopen("in.txt", "r", stdin);
   // freopen("out221.csv", "w", stdout);
    for(double i = 1.0; i <= 20; i+=1)
    {
         cout<<fixed<<setprecision(10)<<i<<" "<<f(i , 0)<<endl;
    }
    double x0 , x1;
    cout<<"Upper and Lower: "<<endl;
    cin>>x0;
    cin>>x1;
    cout<<"Tolerance: "<<endl;
    cin>>eps;
    solve(x0 , x1);
    //solve(1 , 20);

    // printf("root=%.4f\n",mid);


}


