#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

double funcao(double x)
{
    return pow(x, 2);
}
double funcao1(double x)
{
    return sqrt(4 - pow(x, 2));
}

double integraTR(double g(double), double a, double b, int n)
{

    double integral;
    double h = (b - a) / n;

    for (int i = 1; i <= n; i++)
    {
        integral = integral + (h / 2.0) * (g(a + (i - 1) * h) + g(a + i * h));
    }

    return integral;
}

int main()
{

    int n;
    int a, b;
    cout << " Funcao g(x)" << endl; 
    a = 0;
    b = 10;
    n = 2;
    while (n <= 128)
    {
        cout << integraTR(funcao, a, b, n) << endl;
        n = n * 2;
    }
    n = 2;
    a = -2;
    b = 2;
    cout << " Funcao h(x)" <<endl;
    while (n <= 128)
    {
        cout << integraTR(funcao1, a, b, n) << endl;
        n = n * 2;
    }


    return 0;
}
