#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "nice_holidays.hpp"
#include "utilities.hpp"
#include "menu.hpp"
#include "packs.hpp"
#include "clients.hpp"

using namespace std;


// COMPANY FUNCTIONS /// COMPANY FUNCTIONS /// COMPANY FUNCTIONS
void show_company_info(Agency nice_holidays_agency)
{
    cout << "----------------COMPANY INFO------------------" << endl;
    cout << "Name : " << nice_holidays_agency.nome << endl;
    cout << "NIF  : " << nice_holidays_agency.nif << endl;
    cout << "URL  : " << nice_holidays_agency.url << endl;
    cout << "Morada -> Rua        : " << nice_holidays_agency.endereco.nome_rua << endl;
    cout << "       -> Nº porta   : " << nice_holidays_agency.endereco.numero_porta << endl;
    cout << "       -> Nº andar   : " << nice_holidays_agency.endereco.numero_andar << endl;
    cout << "       -> Codigo P/  : " << nice_holidays_agency.endereco.codigo_postal << endl;
    cout << "       -> Localidade : " << nice_holidays_agency.endereco.localidade << endl;
    cout << "----------------------------------------------" << endl;
}
void update_company_info(Agency &nice_holidays_agency)
{

    fstream f;
    string morada;
    vector<string> vec1;
    f.open("agency.txt");

    getline(f, nice_holidays_agency.nome);

    f >> nice_holidays_agency.nif;
    f.ignore(1000, '\n');

    getline(f, nice_holidays_agency.url);

    getline(f, morada);

    decompose(morada, '/', vec1);

    morada_function(vec1, nice_holidays_agency.endereco);

    getline(f, nice_holidays_agency.ficheiro_clientes);
    getline(f, nice_holidays_agency.ficheiro_packs);

    f.close();
}


