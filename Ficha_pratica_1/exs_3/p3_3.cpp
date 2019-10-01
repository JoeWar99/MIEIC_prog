#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double sqrt_raiz(double n, double precision, int max_iteracoes)
{

    double rq = 1, rqn;
    double dif;
    int i = 0;

 

    while (i < max_iteracoes)
    {
        rqn = (rq + n / rq) / 2.0;
        dif = n - pow(rqn, 2);

        if (abs(rqn - rq) < precision)
        {
            break;
        }
        rq = rqn;

        i++;
    }
    return rqn;
}
int main()
{

    double n;
    double precision;
    double max_iter;
    double n1;
    cout << "precision ? " << endl;
    cin >> precision;
    cout << "Qual o n?" << endl;
    cin >> n;
    cout << "Qual o nº max de iteracoes?" << endl;
    cin >> max_iter;

    n1 =  sqrt_raiz(n, precision, max_iter);

    cout << "A raiz é " << n1 << endl;
    
    cout << "Valor returnado pela funcao sqrt " << sqrt(n) << endl;

    return 0;
}