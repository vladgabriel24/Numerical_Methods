#include <iostream>

double Gauss(const int n, double A[][4], double B[], double X[])
{
    double m, d;

    for(int i=1; i<=n-1; i++)
    {
        for(int k=i+1; k<=n; k++)
        {
            m = A[k][i]/A[i][i];

            for(int j=i; j<=n; j++) A[k][j] -= m*A[i][j];

            B[k] -= m*B[i];
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) std::cout<<A[i][j];
        std::cout<<'\n';
    }

    d = 1;
    if(A[n][n] == 0) return 0;

    for(int i=1; i<=n; i++) d *= A[i][i];

    for(int i=n; i>=1; i--)
    {
        X[i] = B[i];
        for(int j=n; j>=i+1; j--) X[i] -=A[i][j]*X[j];

        X[i] /= A[i][i];
    }

    return d;
}

int main()
{

    int n = 3;
    double A[][4] = {{0,0,0,0}, {0,3,-1.5,1}, {0,-1,2,3.3},{0,1.2,-4,2}};
    double B[] = {0,1,2,3};
    double X[50];

    int d = Gauss(n,A,B,X);

    for(int i=1; i<=n; i++) std::cout<<X[i]<<' ';


    return 0;
}