#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool readFracc(int &numerator, int &denominator)
{

    char op;

    cout << "N op D   ?" << endl;

    cin >> numerator >> op >> denominator;

    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }

    if (op != '/')
    {
        cout << "erro , estrutura N op D" << endl;
        return false;
    }
    return true;
}

void writeFracc(int numerator, int denominator)
{

    cout << numerator << "/" << denominator << endl;
}

int euclides(int a, int b)
{
    int q = 0;
    int r = 0;

    /*   b = qa + r   */
    do
    {

        q = b / a;
        r = b % a;

        b = a;
        if (r)
            a = r;

    } while (r != 0);

    return a;
}
void reduceFracc(int &numerator, int &denominator)
{
    int numerator1;

    numerator1 = numerator / euclides(numerator, denominator);
    denominator = denominator / euclides(numerator, denominator);
    numerator = numerator1;
}
void multiplicacao(int numerator, int denominator, int numerator1, int denominator1, int &resultado_num, int &resultado_den)
{

    resultado_num = numerator1 * numerator;
    resultado_den = denominator * denominator1;
}
void divisao(int numerator, int denominator, int numerator1, int denominator1, int &resultado_num, int &resultado_den)
{

    resultado_num = numerator * denominator1;
    resultado_den = denominator * numerator1;
}

void soma(int numerator, int denominator, int numerator1, int denominator1, int &resultado_num, int &resultado_den)
{
    int numerator_aux;
    int denominator_aux;

    if (denominator == denominator1)
    {
        resultado_num = numerator + numerator1;
        resultado_den = denominator;
    }
    else
    {
        denominator_aux = denominator * denominator1;
        numerator = numerator * denominator1;
        numerator1 = numerator1 * denominator;
        denominator = denominator_aux;
        denominator1 = denominator_aux;
        resultado_num = numerator + numerator1;
        resultado_den = denominator_aux;
    }
}
void sub(int numerator, int denominator, int numerator1, int denominator1, int &resultado_num, int &resultado_den)
{
    int numerator_aux;
    int denominator_aux;

    if (denominator == denominator1)
    {
        resultado_num = numerator - numerator1;
        resultado_den = denominator;
        cout << resultado_den << endl;
        

    }
    else
    {
        denominator_aux = denominator * denominator1;
        numerator = numerator * denominator1;
        numerator1 = numerator1 * denominator;
        denominator = denominator_aux;
        denominator1 = denominator_aux;
        resultado_num = numerator - numerator1;
        resultado_den = denominator_aux;
    }
}

int main()
{

    int numerator, denominator;
    int numerator1, denominator1;
    int resultado_num, resultado_den;

    int op;

    while (1)
    {

        if(readFracc(numerator, denominator) == false || readFracc(numerator1, denominator1) == false){
            continue;
        }


        cout << "operaçao : soma(1), subtraçao (2), divisao (3), multiplocaçao (4)" << endl;
        cin >> op;

        if (op == 1)
        {
            soma(numerator, denominator, numerator1, denominator1, resultado_num, resultado_den);
            reduceFracc(resultado_num,resultado_den);
            writeFracc(resultado_num, resultado_den);
        }
        else if (op == 2)
        {
            sub(numerator, denominator, numerator1, denominator1, resultado_num, resultado_den);
            reduceFracc(resultado_num,resultado_den);
            writeFracc(resultado_num, resultado_den);
        }
        else if (op == 3)
        {
            divisao(numerator, denominator, numerator1, denominator1, resultado_num, resultado_den);
            reduceFracc(resultado_num,resultado_den);
            writeFracc(resultado_num, resultado_den);
        }
        else if (op == 4)
        {
            multiplicacao(numerator, denominator, numerator1, denominator1, resultado_num, resultado_den);
            reduceFracc(resultado_num,resultado_den);
            writeFracc(resultado_num, resultado_den);
        }
        else
        {
            cout << "erro" << endl;
        }
    }

    return 0;
}