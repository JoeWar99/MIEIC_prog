#include <iostream>
#include <cmath>

using namespace std;
int main()
{   
    int numero_original;
    int numero;
    double n1, n2, n3;
    cin >> numero;
    double n0;
    int numero1;
    numero_original = numero;
    
    n3  = numero/10.0;
    n3  = n3 - (int)n3;
    n3  = n3 * 10;
    numero = numero - n3;
    n2 = numero /100.0;
    n2 = n2 - (int)n2;
    n2 = n2 * 10;
    numero = numero - n2 * 10;
    n1 = numero/1000.0;
    n1 = n1 - (int)n1;
    n1 = n1 * 10;
    numero = numero - n1 * 100;
    n0 = numero/10000.0;
    n0 = n0 -(int)n0;
    n0 = n0 * 10;


    numero1 = n0 + n1 * 10 + n2 * 100 + n3 * 1000;

    if(numero1==numero_original){
        cout << " é capicua" << endl;
    }
    else{
        cout << "não é capicua" << endl;
    }

    //alinea b)
    cin >> numero;
    numero_original = numero;
    int numero_algarismo = 0;
    int i = 10;

   
    while(true){
        if((numero/(i)) > 1){
            numero_algarismo++;
            i = i * 10;
        }
        else{
            numero_algarismo++;
            break;
        }
    }
    cout << numero_algarismo <<endl;

    double vetor[numero_algarismo];
    int posicao = 0;
    i = 10;
    while(true){
        if(numero != 0){
            vetor[posicao]= numero/i;
            vetor[posicao]= vetor[posicao]- (int)vetor[posicao];
            vetor[posicao]= vetor[posicao] * 10;
            numero = numero - vetor[posicao] * i;
            posicao++;
            i = i *10;
        }
        else{
            break;
        }
        
    }
    int o = 1;
    numero1  = 0;
    for(int i = numero_algarismo-1; i >= 0; i--){
        if(i == numero_algarismo){
            numero1  = numero1 + vetor[i];
        }
        else{
            numero1 = numero1 + vetor[i]*10*o;
            o++;
        }
    }
    for(int t = 0; t < numero_algarismo; t++){
        cout << vetor[t];
    }
    cout << numero1;
    
    if(numero1 == numero_original){
        cout << "é capicua" << endl;
    }
    else{
        cout << " nao é capicua" << endl;
    }
    


  
    return 0;
}