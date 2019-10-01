#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool bissexto(int ano)
{
    if ((ano % 4 == 0) && (ano % 100 != 0))
    {
        return true;
    }
    else if (ano % 4 == 0 && ano % 100 == 0 && ano % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int numero_dias(int ano, int mes)
{

    int dias;

    if (mes == 1)
    {
        dias = 31;
    }
    else if (mes == 2)
    {
        if (bissexto(ano))
        {
            dias = 29;
        }
        else
        {
            dias = 28;
        }
    }
    else if (mes == 3)
    {
        dias = 31;
    }
    else if (mes == 4)
    {
        dias = 30;
    }
    else if (mes == 5)
    {
        dias = 31;
    }
    else if (mes == 6)
    {
        dias = 30;
    }
    else if (mes == 7)
    {
        dias = 31;
    }
    else if (mes == 8)
    {
        dias = 31;
    }
    else if (mes == 9)
    {
        dias = 30;
    }
    else if (mes == 10)
    {
        dias = 31;
    }
    else if (mes == 11)
    {
        dias = 30;
    }
    else if (mes == 12)
    {
        dias = 31;
    }

    return dias;
}

int codigo_mes(int mes, int ano)
{
    int codigo;
    if (bissexto(ano))
    {

        if (mes == 1)
        {
            codigo = 6;
        }
        else if (mes == 2)
        {
            codigo = 2;
        }
        else if (mes == 3)
        {
            codigo = 3;
        }
        else if (mes == 4)
        {
            codigo = 6;
        }
        else if (mes == 5)
        {
            codigo = 1;
        }
        else if (mes == 6)
        {
            codigo = 4;
        }
        else if (mes == 7)
        {
            codigo = 6;
        }
        else if (mes == 8)
        {
            codigo = 2;
        }
        else if (mes == 9)
        {
            codigo = 5;
        }
        else if (mes == 10)
        {
            codigo = 0;
        }
        else if (mes == 11)
        {
            codigo = 3;
        }
        else if (mes == 12)
        {
            codigo = 5;
        }
    }
    else
    {

        if (mes == 1)
        {
            codigo = 0;
        }
        else if (mes == 2)
        {
            codigo = 3;
        }
        else if (mes == 3)
        {
            codigo = 3;
        }
        else if (mes == 4)
        {
            codigo = 6;
        }
        else if (mes == 5)
        {
            codigo = 1;
        }
        else if (mes == 6)
        {
            codigo = 4;
        }
        else if (mes == 7)
        {
            codigo = 6;
        }
        else if (mes == 8)
        {
            codigo = 2;
        }
        else if (mes == 9)
        {
            codigo = 5;
        }
        else if (mes == 10)
        {
            codigo = 0;
        }
        else if (mes == 11)
        {
            codigo = 3;
        }
        else if (mes == 12)
        {
            codigo = 5;
        }
    }
    return codigo;
}

int dia_da_semana(int dia, int mes, int ano)
{

    int dia_semana;
    int a;
    float floor1;
    int s = ano;
    a = ano % 100;

    while (s > 100)
    {
        s = s / 10;
    }

    floor1 = 5 * a / 4.0;
    floor1 = floor(floor1);

    dia_semana = ((int)floor1 + codigo_mes(mes, ano) + dia - 2 * (s % 4) + 7) % 7;

    return dia_semana;
}
int printf_dia_semana(int dia_semana)
{
    if (dia_semana == 0)
    {
        cout << "Sabado" << endl;
    }
    if (dia_semana == 1)
    {
        cout << "Domingo" << endl;
    }
    if (dia_semana == 2)
    {
        cout << "Segunda" << endl;
    }
    if (dia_semana == 3)
    {
        cout << "Terça" << endl;
    }
    if (dia_semana == 4)
    {
        cout << "Quarta" << endl;
    }
    if (dia_semana == 5)
    {
        cout << "Quinta" << endl;
    }
    if (dia_semana == 6)
    {
        cout << "Sexta" << endl;
    }
}
void print_dias_do_mes_do_ano(int mes, int ano)
{
    int j = 0;
    cout << mes << "/" << ano << endl;
    cout << "Dom" << setw(5) << "Seg" << setw(5) << "Ter" << setw(5) << "Qua" << setw(5) << "Qui" << setw(5) << "Sex" << setw(5) << "Sab" << endl;
    for (int i = 1; i <= numero_dias(ano, mes); i++)
    {
        if (i == 1)
        {
            if (dia_da_semana(1, mes, ano) == 0)
            {
                j = 6;
                cout << setw(5 * 6) << " ";
                cout << i << endl;
            }
            else
            {
                j = dia_da_semana(1, mes, ano);
                cout << setw((j - 1) * 5) << " ";
                cout << i << setw(5);
            }
        }
        else
        {
            if (dia_da_semana(i, mes, ano) == 0)
            {
                cout << i;
                cout << endl;
            }

            else
            {
                if (i < 10)
                    cout << i << "    ";
                else
                    cout << i << "   ";
            }
        }
    }
    cout << endl << endl;
    return;
}
void print_meses_do_ano(int ano)
{
    for (int i = 1; i <= 12; i++)
    {
        print_dias_do_mes_do_ano(i, ano);
    }
}

int main()
{

    int ano;
    int mes;
    int dia;
    while (true)
    {
        cout << "Qual o ano ?" << endl;
        cin >> ano;

        print_meses_do_ano(ano);
        cout << endl
             << endl;
    }
    return 0;
}