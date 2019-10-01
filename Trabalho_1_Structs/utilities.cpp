#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <ostream>
#include <sstream>
#include "nice_holidays.hpp"
#include "utilities.hpp"
#include "menu.hpp"
#include "packs.hpp"
#include "clients.hpp"
using namespace std;

void erase_right(string &s)
{
    s.erase(s.find_last_not_of(" ") + 1, s.size());
}
void erase_left(string &s)
{
    s.erase(0, s.find_first_not_of(" "));
}
void erase_middle(string &s)
{
    int pos = 0;
    string name;
    int cnt = 0;

    while (1)
    {
        erase_left(s);
        erase_right(s);
        pos = s.find_first_of(" ");
        if (pos == string::npos)
        {
            break;
        }
        else
        {
            name.append(s.substr(0, pos + 1));
            s.erase(0, pos);
        }
    }
    name.append(s);
    s = name;
}
void erase(string &s)
{
    erase_left(s);
    erase_right(s);
    erase_middle(s);
}

// AUXILIARY FUNCTIONS
void decompose(string &s, char c_separacao, vector<string> &vec)
{

    int pos = 0;
    string aux1;
    s.push_back(c_separacao);
    istringstream aux_stream;

    while (pos != string::npos)
    {
        pos = s.find(c_separacao);
        if (pos == string::npos)
            break;
        aux1 = s.substr(0, pos);
        s.erase(0, pos + 1);
        erase(aux1);
        vec.push_back(aux1);
    }
}

void decompose_int(string &s, char c_separacao, vector<int> &vec)
{
    istringstream aux_stream;
    vector<string> vec1;
    decompose(s, c_separacao, vec1);
    int aux;
    for (int i = 0; i < vec1.size(); i++)
    {
        aux_stream.str(vec1.at(i));
        aux_stream >> aux;
        vec.push_back(aux);
        aux_stream.clear();
    }
}
void test(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << "    ";
    }
    cout << endl;
}

void print_date(ostream &n, Date d1)
{
    n << d1.ano << "/" << d1.mes << "/" << d1.dia << endl;
}

void ignore_n()
{
    cin.ignore(1000, '\n');
}
int fail()
{
    if (cin.fail())
    {
        cin.clear();
        ignore_n();
        return -1;
    }
    else{
        ignore_n();
        return 0;
    }

}
void morada_function(vector<string> vec1, Adress &endereco)
{
    istringstream aux_stream;
    endereco.nome_rua = vec1.at(0);
    aux_stream.str(vec1.at(1));
    aux_stream >> endereco.numero_porta;
    endereco.numero_andar = vec1.at(2);
    endereco.codigo_postal = vec1.at(3);
    endereco.localidade = vec1.at(4);
}
