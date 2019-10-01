#include <iostream>

using namespace std;

int main()
{

    double numero1, numero2, numero3;

    cout << "tres numeros ? " << endl;
    cin >> numero1 >> numero2 >> numero3;

    int maior = numero1;
    int menor = numero1;

    cout << "alinea a)" << endl;

    if (numero2 >= maior)
    {
        maior = numero2;
    }
    if (numero3 >= maior)
    {
        maior = numero3;
    }
    if (numero2 <= menor)
    {
        menor = numero2;
    }
    if (numero3 <= menor)
    {
        menor = numero3;
    }

    cout << "maior --> " << maior << endl;
    cout << "menor --> " << menor << endl;

    cout << "alinea b)" << endl;

    int numeros[3];
    numeros[0] = numero1;
    numeros[1] = numero2;
    numeros[2] = numero3;
    int aux;

    for (int i = 0; i < 2; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (numeros[j - 1] > numeros[j])
            {
                aux = numeros[j];
                numeros[j] = numeros[j - 1];
                numeros[j - 1] = aux;
            }
        }
    }

    cout << "Valores ordenados descrecente :" << endl;

    for (int i = 2; i >= 0; i--)
    {
        cout << numeros[i] << endl;
    }

    cout << " alinea c" << endl;

    double l1, l2, l3;

    cout << "Três valores double " << endl;
    cin >> l1 >> l2 >> l3;

    double lados[3];
    lados[0] = l1;
    lados[1] = l2;
    lados[2] = l3;

    for (int i = 0; i < 2; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (lados[j - 1] > lados[j])
            {
                aux = lados[j];
                lados[j] = lados[j - 1];
                lados[j - 1] = aux;
            }
        }
    }

    if((lados[0]+ lados[1])<=lados[2]){
        cout << " Nao é possivel construir um triangulo com estes comprimentos para os lados" << endl;
    }
    else{
        cout << " é possivel construir um triangulo com estes comprimentos para os lados" << endl;
    }

    cout << " FIM" << endl;

    return 0;
}