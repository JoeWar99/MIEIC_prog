#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double peso, custo;
    int n = 0;
    cout << "Qual o peso da mercadoria?"<< endl;
    cin >> peso;

    if(peso < 500){
        custo = 5;
    }
    else if(peso>=500 && peso<=1000){
        if(peso>=600){
            n = ((int)peso - 500)/100;
        }
        cout << n << endl,
        custo = 5 + 1.5 * n;
    }
    else if(peso > 1000){
        if(peso >= 1250){
            n = ((int)peso - 1000)/250;
        }
        custo = 12.5 + 5 * n;
    }

    cout << " Custo do transporte da mercadoria " << custo << endl;









    return 0;
}