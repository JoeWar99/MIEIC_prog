#include <iostream>
#include <cmath>

using namespace std;



int main(){
    double a, b, c;
    double binomio;
    double x1, x2;
    double x1_real, x1_imaginario;
    double x2_real, x2_imaginario;

    cout << "Quais os valores para a , b e c"<< endl;
    cin >> a >> b >> c;
     
    binomio = pow(b,2)- 4 * a*c;
    
    if(binomio > 0 ){
        cout << "Tem como solucao dois numeros reais distintos como solucao" << endl;
        x1 = (-b+sqrt(binomio))/(2 * a);
        x2 = (-b-sqrt(binomio))/(2 * a);
        cout << "Soluçao 1 : " << x1 << endl;
        cout << "Solucao 2 : " << x2 << endl;
    }
    else if(binomio == 0){
        cout << "Tem como solução um número real repetido como solução" << endl;
        x1 = (-b+sqrt(binomio))/(2 * a);
        x2 = (-b-sqrt(binomio))/(2 * a);
        cout << "Soluçao 1 : " << x1 << endl;
        cout << "Solucao 2 : " << x2 << endl;
    }
    else if(binomio < 0){
        cout << "Nenhuma das duas soluçoes é um numero real" << endl;
        x1_real = -b/(2*a);
        x1_imaginario = sqrt(-binomio)/(2*a);
        x2_real = -b/(2*a);
        x2_imaginario = -sqrt(-binomio)/(2*a);   
        cout << "Soluçao 1 : " << x1_real << " + " << x1_imaginario << "i"<<endl;
        cout << "Solucao 2 : " << x2_real << " + " << x2_imaginario << "i"<<endl;
    }



    






    
}