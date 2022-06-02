#include <iostream>

double f(double x)
{
    return x*x;
}

double Formula_trapezului(double (*p)(double), double a, double b, double n)
{
    double sum = 0.0;

    double h = (b-a)/n;

    for(double i=a+h ; i<=b-h; i+=h) sum += p(i);

    sum *= h;

    return h*(p(a)+p(b))/2 + sum;

}

double Formula_richardson(double (*p)(double), double a, double b, double n, double m)
{
    double k = (b-a)/n;
    double h = (b-a)/m;

    double I_n = Formula_trapezului(p, a, b, n);
    double I_m = Formula_trapezului(p, a, b, m);

    return I_n + (I_n - I_m)/((k*k/h*h)-1);
}

int main()
{
    double (*p)(double);

    p = &f;

    std::cout<<Formula_trapezului(p,2.0,3.0,1.0)<<'\n';
    std::cout<<Formula_richardson(p, 2.0, 3.0,2.0, 2.0)<<'\n';

    // Formula Simpson (n = 2m)
    std::cout<<Formula_richardson(p, 2.0, 3.0,4.0, 2.0);


    return 0;
}