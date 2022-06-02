#include <iostream>
#include <iomanip>
#include <math.h>

#define NR_MAX_PASI 500

double f(double x) {return exp(2*x)-1.6*x*x-2;}
double f_der(double x) {return 2*exp(2*x)-3.2*x;}

int main()
{
    // variabile necesare algoritmului
    double x0;
    double eps;
    double x1;
    int k = 0;

    // variabile pentru derivare
    double h;
    double der;

    double radacina;

    // initializari
    x0 = 1.05;
    eps = pow(10,-3);
    h = 0.01;

    while(true)
    {
        // utilizez formula derivatei unei functii intr-un anumit punct:
        // f'(ics) = [f(ics + h) - f(ics)]/h

        der = (f(x0+h) - f(x0))/h;

        x1 = x0 - f(x0)/f_der(x0);

        if(abs(x1-x0) >= eps && k<NR_MAX_PASI)
        {
            k++;
            x0 = x1;
        }
        else break;
    }
    
    radacina = x1;

    std::cout<<radacina;

    return 0;
}