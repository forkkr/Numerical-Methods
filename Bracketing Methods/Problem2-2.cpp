#include<bits/stdc++.h>
using namespace std;
double eps = 0.00001;


double func(double x)
{
    double ret= (42 - 2.0D*x);
    ret = pow(ret , 2.0D);
    ret = ret*(28 - x);
    ret = (4 + x)/ret - 0.016;
    return ret;
}

//double f(double x)
//{
//    double r= x*x*x - 0.165*x*x +3.993*0.0001;
//    return r;
//}

double find_point(double x0, double x1)
{
    double ret= (func(x0)*(x1-x0))/(func(x0)-func(x1)) + x0;
    return ret;
}

void solve(double x0 , double x1)
{
    double lo , hi;
    if(func(x0) > 0)
    {
        lo = x0;
        hi = x1;
    }
    else
    {
        lo = x1;
        hi = x0;
    }
    double mid=find_point(lo,hi);
    int cnt = 1;
    double r=func(mid);
    cout<<cnt++<<fixed<<setprecision(06)<<" "<<lo<<" "<<hi<<" "<<mid<<" "<<r<<" "<<"N/A"<<endl;
    if(func(mid)*func(lo)>0)
        lo=mid;
    else if(func(mid)*func(hi)>0)
        hi=mid;
    double past = mid;
    do
    {
        past = mid;
        mid=find_point(lo,hi);
        double r=func(mid);
        if(func(mid)*func(lo)>0)
            lo=mid;
        else if(func(mid)*func(hi)>0)
            hi=mid;
        double rerror= fabs(mid-past)/mid;
        cout<<cnt++<<fixed<<setprecision(06)<<" "<<lo<<" "<<hi<<" "<<mid<<" "<<r<<" "<<rerror<<endl;
        //cout<<fixed<<setprecision(6)<<rerror<<endl;
        //cout<<cnt++<<endl;

    }
    while(fabs(mid-past)/mid > eps);
}

int main()
{
    //freopen("out1.txt", "w", stdout);
   // freopen("out211.csv", "w", stdout);

    for(int i = 1; i <= 20; i++)
    {
        cout<<fixed<<setprecision(10)<<func(i)<<endl;
    }
    double x0 , x1;
    cout<<"Upper and Lower: "<<endl;
    cin>>x0;
    cin>>x1;
    cout<<"Tolerance: "<<endl;
    cin>>eps;
    solve(x0 ,x1);
   // solve(1 , 20);
}
