#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
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
    for(long long k = 1; k <= 10; k++)
    {
        lob =  pow(-1 , k);
        double tmp = pow(x , 2.0D);
        tmp = tmp/4.0D;
        lob = lob*pow(tmp , k);
    //    cout<<lob<<" ehy "<<endl;
        hor = fact(k);
        hor = hor*(fact(n+k));
        sum = sum + (lob/hor);
    }
    ret = ret*sum;
    return ret;
}







int main()
{

//     freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    //cout<<" for n = "<<0<<endl;


   // cout<<" for n = "<<2<<endl;
    for(double x = 0; x <= 10; x+=.1)
    {
        cout<<fixed<<setprecision(10)<<f(x , 2)<<endl;
    }


}
