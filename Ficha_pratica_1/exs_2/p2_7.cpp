#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

    float x0, xn, incremento;
    int n_iteracoes;

    cout << "Gama de valores [x0 ...... xn]??" << endl;
    cin >> x0 >> xn;
    cout << "Valor de delta_x (incremento)"<<endl;
    cin >> incremento;


    n_iteracoes = (xn-x0)/incremento;

    

    for(int i = 0; i  <= n_iteracoes; i ++){
        if(i == 0){
            cout << "ang " << setw(15) << "sen " << setw(15) << " cos " << setw(15) << " tan "<< endl;
        }
        cout << i << setw(15) <<  sin((((i*incremento)+x0)*M_PI/2)/90) << setw(15) << cos((((i*incremento)+x0)*M_PI/2)/90) << setw(15) << tan((((i*incremento)+x0)*M_PI/2)/90) << endl;
    }
    return 0;
}