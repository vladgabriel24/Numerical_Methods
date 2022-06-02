#include <iostream>
#include <math.h>

double f(double x)
{
    return exp(2*x)-1.6*x*x-2;
}

int main()
{
    double ls=0.1;
    double ld=2.2;
    double er= 0.00001;
    double xm, rad;
    int k=0;

    xm = (ls+ld)/2;

    // fabs = float abs()

    while( fabs(ld-ls)>er && f(xm)!=0 )
    {
        k++;

        xm = (ls+ld)/2;

        if( f(xm)*f(ls) < 0) ld=xm;
        else ls=xm;
    }

    rad=xm;

    std::cout<<rad<<'\n';
    std::cout<<"Numarul de pasi este: "<<k<<'\n';
    std::cout<<"Numarul aproximat este:"<<log2(2100)<<'\n';

    std::cout<<f(rad);

    return 0;
}