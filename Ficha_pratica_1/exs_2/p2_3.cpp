#include <iostream>
using namespace std;

int main(){

    char operation;
    double operando1, operando2;
    double resultado;

    cout << "Formato (numero operacoa numero) :  Operandos 1, operação (+ - * /), operando2 ?" << endl;
    cin >> operando1 >>operation >> operando2;
    cout << "tipo de operaçao (+,-,*,/)" << endl;
  
    switch(operation){
        case '+':
            resultado = operando1 + operando2;
            break;
        case '-':
            resultado = operando1 - operando2;
            break;
        case '*':
            resultado = operando1 * operando2;
            break;
        case '/':
            resultado = operando1 / operando2;
            break;
    }

    cout << "Resultado da operação " << resultado << endl;
    



    return 0;
}