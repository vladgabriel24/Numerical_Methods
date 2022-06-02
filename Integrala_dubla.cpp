#include <iostream>

double f(double x, double y)
{
    return x*y;
}

double Formula_cubat_trapez(double (*p)(double, double), double a, double b, double c, double d, double n, double m)
{
    double h = (b-a)/n;
    double k = (b-a)/m;

    double sum = 0;

    for(double i = 0; i<=n-1; i++)
    {
        for(double j = 0; j<=m-1; j++)
            sum += f(a+i*h, c+j*k) + f(a+(i+1)*h, c+j*k) + f(a+i*h, c+(j+1)*k) + f(a+(i+1)*h, c+(j+1)*k);
    }

    return (k*h)*sum/4;
}

int main()
{
    double (*p)(double,double);

    p = f;

    std::cout<<Formula_cubat_trapez(f,1.0, 2.0, 3.0, 4.0, 2.0, 2.0);

    return 0;
}