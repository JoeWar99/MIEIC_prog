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
    int i= 0;
    cout << "Para terminar pressionar CTRL-D" << endl;


    while (true)
    {
        cin >> n;
        if(cin.fail()){
            if(cin.eof()){
                break;
            }
            else{
                cin.clear();
                cin.ignore(1000, '\n');
                
            }
        }
        if(n_numeros == 0){
            maior = n;
            menor = n;
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
        n_numeros++;
    }
    cout << "soma " << soma << endl;
    cout << "media " << soma/n_numeros << endl;
    cout << "menor " << menor << endl;
    cout << "maior " << maior << endl;
    cout << "numero de numeros " << n_numeros << endl;

    return 0;
}