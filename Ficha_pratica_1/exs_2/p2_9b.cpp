#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int n;
    int soma = 0;
    double media;
    int menor;
    int maior;
    int n_numeros = 0;
    int i= 1;
    cout << "numero de numeros?" << endl;
    cin >> n_numeros;

    while (i <= n_numeros)
    {
        cin >> n;
        if(n_numeros == 0){
            maior = n;
            menor = n;
        }
        if (n == 0)
        {
            break;
        }
        if (n < menor)
        {
            menor = n;
        }
        else if (n > maior)
        {
            maior = n;
        }
        soma = soma + n;
        i++;
    }
    cout << "soma " << soma << endl;
    cout << "media " << soma/n_numeros << endl;
    cout << "menor " << menor << endl;
    cout << "maior " << maior << endl;
    cout << "numero de numeros " << n_numeros << endl;

    return 0;
}