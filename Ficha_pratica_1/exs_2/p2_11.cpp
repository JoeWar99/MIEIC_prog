#include <iostream>
#include <cmath>

using namespace std;

int fatorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fatorial(n - 1);
    }
}

int main()
{

    int n;
     long double pi = 0;
     long double dividendo = 1;
     long double e = 1;
     long double fatorial = 1;
    long double precisao;
    long double anterior = 0;
    
    cout << "Precisao ? " << endl;
    cin >> precisao;
    cout << " numero de vezes" << endl;
    cin >> n;


    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            pi = pi - 4 / dividendo;
        }
        else
        {
            pi = pi + 4 / dividendo;
        }
        if(abs(anterior - pi) < precisao){
            break;
        }

        anterior = pi;

        dividendo = dividendo + 2;
    }
    cout << pi << endl;

    anterior = 0;

    for (int i = 1; i <= n; i++)
    {
        fatorial = fatorial * i;

        e = e + 1 / fatorial;

        if(abs(anterior -e) < precisao){
            break;
        }
        anterior = e;
    }
    cout << "e == " << e << endl;

    cout << " valor do e^-x" << endl;

    double x;
    
    cout << "Qual o x?" << endl;
    cin >> x;

    double ex = 0;
    fatorial = 1;
    anterior = 0;
    
    for (int i = 0; i < n; i++)
    {
        if(i== 0){
            ex = 1;
        }
        else if (i == 1){
            ex = ex - pow(x, i)/fatorial;
        }
        else if (i % 2 == 0)
        {
            ex = ex + pow(x, i)/fatorial;
        }
        else
        {
            ex = ex - pow(x, i)/fatorial;
        }
       /*  if(abs(anterior - ex) < precisao){
            break;
        }
        anterior = ex;*/
        fatorial = fatorial * (i+1);
    }
    cout << ex << endl;

    return 0;
}