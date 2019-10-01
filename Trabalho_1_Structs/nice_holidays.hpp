#pragma once


#include <vector>
#include <string>

using namespace std;

typedef struct
{
    int ano;
    int mes;
    int dia;
} Date;

typedef struct
{
    int id;
    vector<string> locais_turisticos;
    Date inicio;
    Date fim;
    int preco_pessoa;
    int n_max_pessoas;
    int n_bilhetes_vendidos;
} TravelPack;

typedef struct
{
    string nome_rua;
    int numero_porta;
    string numero_andar;
    string codigo_postal;
    string localidade;
} Adress;

typedef struct
{
    string nome;
    int nif;
    int numero_pessoas_agregado;
    Adress endereco;
    vector<int> lista_de_pacotes_comprados;
} Client;

typedef struct
{
    string nome;
    int nif;
    Adress endereco;
    string url;
    vector<TravelPack> lista_de_pacotes;
    vector<Client> lista_de_clientes;
    string ficheiro_clientes;
    string ficheiro_packs;
    int id_ultimo_pacote;
} Agency;


void update_company_info(Agency &nice_holidays_agency);
void show_company_info(Agency nice_hollidays_agency);

