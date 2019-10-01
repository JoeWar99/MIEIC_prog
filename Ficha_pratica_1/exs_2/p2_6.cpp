#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main()
{

    int n;
    int raiz;
    cout << "Qual o numero que deseja ver se é primo ou não ?" << endl;
    cin >> n;

    raiz = sqrt(n);
    for (int i = 2; i < raiz; i++)
    {
        if (n % i == 0)
        {
            cout << "O numero não é primo" << endl;
        }
    }

    for (int i = 2; i < 10000+1; i++)
    {
        for (int j = 2; j <= i; j++)
        {

            if (j == i)
            {
                cout << i << " é primo " << endl;
                break;
            }
            
            else if (i % j == 0)
            {
                cout << i << " não é primo" << endl;
                break;
            }
        }
    }

    return 0;
}