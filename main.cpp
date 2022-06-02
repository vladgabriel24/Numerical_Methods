#include <iostream>

using namespace std;

double f(double x)
{
    return x*x;
}

double richardson(int a, int b, int n, int m)
{
    double result=0;

    double h, k;
    double sumh = 0 , sumk = 0;

    h = (double)(b-a)/n;
    k = (double)(b-a)/m;

    for(int i=1; i<n; i++)
        sumh += h*f(a + i*h);

    for(int j=1; j<m; j++)
        sumk += k*f(a + j*k);

    sumk += (f(a) - f(b))/2*k;
    sumh += (f(a) - f(b))/2*h;

    result = sumh + (double)(sumh - sumk)/((k/h)*(k/h) - 1);

    return result;
}

int main()
{
    int a, b;
    int n, m;

    cin>>a>>b>>n>>m;

    cout<<richardson(a,b,n,m);




    return 0;
}
