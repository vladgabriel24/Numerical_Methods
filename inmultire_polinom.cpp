#include <iostream>

int main()
{
    int n;
    std::cout<<"Introduceti gradul polinomului:";
    std::cin>>n;

    int* a = new int[n+1];
    std::cout<<"Introduceti coeficientii polinomului:\n";

    for(int i=0; i<=n; i++) std::cin>>a[i];

    int k;
    std::cout<<"Introduceti valoarea lui x:\n";
    std::cin>>k;

    int sum = a[n];
    for(int i = n; i>0; i--)
    {
        sum *= k;
        sum += a[i-1];
    }

    std::cout<<sum<<'\n';

    // calcularea primei derivate a unui polinom
    int sum_derivat = n*a[n];
    for(int i=n; i>=1; i--)
    {
        sum_derivat *= k;
        sum_derivat += (i-1)*a[i-1];
    }

    std::cout<<sum_derivat;

    return 0;
}