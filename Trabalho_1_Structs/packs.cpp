#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "nice_holidays.hpp"
#include "utilities.hpp"
#include "packs.hpp"
#include <sstream>
#include "nice_holidays.hpp"
#include "utilities.hpp"
#include "menu.hpp"
#include "packs.hpp"
#include "clients.hpp"

using namespace std;


void update_Packs_info(Agency &nice_holidays_agency)
{
    TravelPack t1;
    string locais_turisticos;
    string lixo;
    string aux;
    string pacotes_comprados;
    istringstream aux_stream;
    Date d1;
    string data;
    vector<int> d2;
    vector<string> vec1;

    fstream f;
    f.open(nice_holidays_agency.ficheiro_packs);

    f >> nice_holidays_agency.id_ultimo_pacote;
    getline(f, lixo);

    while (!f.eof())
    {
        f >> t1.id;
        getline(f, lixo);

        getline(f, aux);

        decompose(aux, ';', t1.locais_turisticos);

        d2.clear();
        getline(f, data);
        decompose_int(data, '/', d2);
        d1.ano = d2.at(0);
        d1.mes = d2.at(1);
        d1.dia = d2.at(2);
        t1.inicio = d1;

        d2.clear();
        getline(f, data);
        decompose_int(data, '/', d2);
        d1.ano = d2.at(0);
        d1.mes = d2.at(1);
        d1.dia = d2.at(2);
        t1.fim = d1;

        f >> t1.preco_pessoa;
        getline(f, lixo);
        f >> t1.n_max_pessoas;
        getline(f, lixo);
        f >> t1.n_bilhetes_vendidos;
        getline(f, lixo);

        getline(f, lixo);
        nice_holidays_agency.lista_de_pacotes.push_back(t1);
        t1.locais_turisticos.clear();
    }

    f.close();
}

void write_packs_to_file(Agency nice_holidays_agency)
{

    std::ofstream out;
    out.open(nice_holidays_agency.ficheiro_packs);

    for (int i = 0; i < nice_holidays_agency.lista_de_pacotes.size(); i++)
    {
        //show_Travel_pack_info(nice_holidays_agency.lista_de_pacotes.at(i));
        if (i == 0)
        {
            out << nice_holidays_agency.id_ultimo_pacote << endl;
        }
        else
        {
            out << "::::::::::" << endl;
        }
        out << nice_holidays_agency.lista_de_pacotes.at(i).id << endl;
        for (int j = 0; j < nice_holidays_agency.lista_de_pacotes.at(i).locais_turisticos.size(); j++)
        {
            out << nice_holidays_agency.lista_de_pacotes.at(i).locais_turisticos.at(j);
            if (j != nice_holidays_agency.lista_de_pacotes.at(i).locais_turisticos.size() - 1)
            {
                out << " ; ";
            }
        }
        out << endl;
        print_date(out, nice_holidays_agency.lista_de_pacotes.at(i).inicio);
        print_date(out, nice_holidays_agency.lista_de_pacotes.at(i).fim);

        out << nice_holidays_agency.lista_de_pacotes.at(i).preco_pessoa << endl;
        out << nice_holidays_agency.lista_de_pacotes.at(i).n_max_pessoas << endl;
        out << nice_holidays_agency.lista_de_pacotes.at(i).n_bilhetes_vendidos << endl;
    }
    out.close();
}

void show_Travel_pack_info(TravelPack t1)
{
    cout << "--------------TRAVEL PACK INFO----------------" << endl;
    cout << "ID               : " << t1.id << endl;
    cout << "Locais tur/      : ";
    for (int i = 0; i < t1.locais_turisticos.size(); i++)
    {

        cout << t1.locais_turisticos.at(i);
        if (i == t1.locais_turisticos.size() - 1)
        {
            continue;
        }
        else
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "D/ inicio        : ";
    print_date(cout, t1.inicio);

    cout << "D/ fim           :";
    print_date(cout, t1.fim);
    cout << "Preço p/ pessoa  : " << t1.preco_pessoa << endl;
    cout << "n_max_pessoas    : " << t1.n_max_pessoas << endl;
    cout << "n_bilhetes_ve/   : " << t1.n_bilhetes_vendidos << endl;
    cout << "----------------------------------------------" << endl;
}

void show_all_pack_info(Agency nice_holidays_agency)
{
    if (nice_holidays_agency.lista_de_pacotes.size() == 0)
    {
        cout << "Atualizar Travel Packs Primeiro\n";
    }
    else
    {
        for (int i = 0; i < nice_holidays_agency.lista_de_pacotes.size(); i++)
        {
            show_Travel_pack_info(nice_holidays_agency.lista_de_pacotes.at(i));
        }
    }
}

int find_travelpack(int id_travel_pack, Agency nice_holidays_agency)
{
    for (int i = 0; i < nice_holidays_agency.lista_de_pacotes.size(); i++)
    {
        if (id_travel_pack == nice_holidays_agency.lista_de_pacotes.at(i).id)
        {
            return 0;
        }
    }
    return -1;
}
bool check_pack_for_same_id(Agency nice_holidays_agency, int id)
{

    for (int i = 0; i < nice_holidays_agency.lista_de_pacotes.size(); i++)
    {
        if (id == nice_holidays_agency.lista_de_pacotes.at(i).id)
        {
            return true;
        }
    }
    return false;
}

int pacote_position(Agency &nice_holidays_agency, int id)
{
    for (int i = 0; i < nice_holidays_agency.lista_de_pacotes.size(); i++)
    {
        if (id == nice_holidays_agency.lista_de_pacotes.at(i).id)
        {

            return i;
        }
        else if (i == nice_holidays_agency.lista_de_pacotes.size() - 1)
        {
            return -1;
        }
    }
    return -1;
}
void show_total_sold_packs(Agency nice_holiday_agency)
{
    int sold = 0;

    for (int i = 0; i < nice_holiday_agency.lista_de_pacotes.size(); i++)
    {
        sold = sold + nice_holiday_agency.lista_de_pacotes.at(i).n_bilhetes_vendidos;
    }
    cout << "Travel Packs Vendidos ==  " << sold << endl;
}
void show_specific_pack_info(Agency nice_holiday_agency)
{
    int option;
    string destino;
    Date d1;
    Date d2;
    string data1;
    string data2;
    vector<int> data1_aux;
    vector<int> data2_aux;
    bool menor_data = false;
    bool maior_data = false;

    do
    {
        menu_specific_pack_info();
        cin >> option;
        fail();
        switch (option)
        {
        case 1:
            show_all_pack_info(nice_holiday_agency);
            break;
        case 2:
            cout << "Qual o destino turistico ? " << endl;
            getline(cin, destino);
            erase(destino);
            for (int i = 0; i < nice_holiday_agency.lista_de_pacotes.size(); i++)
            {
                for (int j = 0; j < nice_holiday_agency.lista_de_pacotes.at(i).locais_turisticos.size(); j++)
                {
                    cout << nice_holiday_agency.lista_de_pacotes.at(i).locais_turisticos.at(j) << endl;
                    if (destino == nice_holiday_agency.lista_de_pacotes.at(i).locais_turisticos.at(j))
                    {
                        show_Travel_pack_info(nice_holiday_agency.lista_de_pacotes.at(i));
                        break;
                    }
                }
            }
            break;

        case 3:
            cout << "Primeira Data (AAAA/MM/DD)? " << endl;
            getline(cin, data1);
            erase(data1);
            decompose_int(data1, '/', data1_aux);
            cout << "Segunda Data  (AAAA/MM/DD)?" << endl;
            getline(cin, data2);
            erase(data2);
            decompose_int(data2, '/', data2_aux);
            maior_data = false;
            menor_data = false;

            d1.ano = data1_aux.at(0);
            d1.mes = data1_aux.at(1);
            d1.dia = data1_aux.at(2);
            print_date(cout, d1);
            d2.ano = data2_aux.at(0);
            d2.mes = data2_aux.at(1);
            d2.dia = data2_aux.at(2);
            print_date(cout, d2);

            for (int i = 0; i < nice_holiday_agency.lista_de_pacotes.size(); i++)
            {
                menor_data = false;
                maior_data = false;

                if (d1.ano < nice_holiday_agency.lista_de_pacotes.at(i).inicio.ano)
                {
                    menor_data = true;
                }
                else if (d1.ano == nice_holiday_agency.lista_de_pacotes.at(i).inicio.ano)
                {
                    if (d1.mes < nice_holiday_agency.lista_de_pacotes.at(i).inicio.mes)
                    {
                        menor_data = true;
                    }
                    else if (d1.mes == nice_holiday_agency.lista_de_pacotes.at(i).inicio.mes)
                    {
                        if (d1.dia < nice_holiday_agency.lista_de_pacotes.at(i).inicio.dia)
                        {
                            menor_data = true;
                        }
                    }
                }

                if (d2.ano > nice_holiday_agency.lista_de_pacotes.at(i).fim.ano)
                {
                    maior_data = true;
                }
                else if (d2.ano == nice_holiday_agency.lista_de_pacotes.at(i).fim.ano)
                {
                    if (d2.mes > nice_holiday_agency.lista_de_pacotes.at(i).fim.mes)
                    {
                        maior_data = true;
                    }
                    else if (d2.mes == nice_holiday_agency.lista_de_pacotes.at(i).fim.mes)
                    {
                        if (d2.dia > nice_holiday_agency.lista_de_pacotes.at(i).fim.dia)
                        {
                            maior_data = true;
                        }
                    }
                }
                if (maior_data && menor_data)
                {
                    show_Travel_pack_info(nice_holiday_agency.lista_de_pacotes.at(i));
                }
            }

            break;
        case 4:
            cout << "Primeira Data (AAAA/MM/DD)? " << endl;
            getline(cin, data1);
            erase(data1);
            decompose_int(data1, '/', data1_aux);
            cout << "Segunda Data  (AAAA/MM/DD)?" << endl;
            getline(cin, data2);
            erase(data2);
            decompose_int(data2, '/', data2_aux);
            maior_data = false;
            menor_data = false;

            d1.ano = data1_aux.at(0);
            d1.mes = data1_aux.at(1);
            d1.dia = data1_aux.at(2);
            //print_date(cout, d1);
            d2.ano = data2_aux.at(0);
            d2.mes = data2_aux.at(1);
            d2.dia = data2_aux.at(2);
            // print_date(cout, d2);

            cout << "Qual o destino turistico ? " << endl;
            getline(cin, destino);
            erase(destino);

            for (int i = 0; i < nice_holiday_agency.lista_de_pacotes.size(); i++)
            {

                if (d1.ano < nice_holiday_agency.lista_de_pacotes.at(i).inicio.ano)
                {
                    menor_data = true;
                }
                else if (d1.ano == nice_holiday_agency.lista_de_pacotes.at(i).inicio.ano)
                {
                    if (d1.mes < nice_holiday_agency.lista_de_pacotes.at(i).inicio.mes)
                    {
                        menor_data = true;
                    }
                    else if (d1.mes == nice_holiday_agency.lista_de_pacotes.at(i).inicio.mes)
                    {
                        if (d1.dia < nice_holiday_agency.lista_de_pacotes.at(i).inicio.dia)
                        {
                            menor_data = true;
                        }
                    }
                }

                if (d2.ano > nice_holiday_agency.lista_de_pacotes.at(i).fim.ano)
                {
                    maior_data = true;
                }
                else if (d2.ano == nice_holiday_agency.lista_de_pacotes.at(i).fim.ano)
                {
                    if (d2.mes > nice_holiday_agency.lista_de_pacotes.at(i).fim.mes)
                    {
                        maior_data = true;
                    }
                    else if (d2.mes == nice_holiday_agency.lista_de_pacotes.at(i).fim.mes)
                    {
                        if (d2.dia > nice_holiday_agency.lista_de_pacotes.at(i).fim.dia)
                        {
                            maior_data = true;
                        }
                    }
                }
                if (maior_data && menor_data)
                {

                    for (int j = 0; j < nice_holiday_agency.lista_de_pacotes.at(i).locais_turisticos.size(); j++)
                    {
                        //cout << nice_holiday_agency.lista_de_pacotes.at(i).locais_turisticos.at(j) << endl;
                        if (destino == nice_holiday_agency.lista_de_pacotes.at(i).locais_turisticos.at(j))
                        {
                            show_Travel_pack_info(nice_holiday_agency.lista_de_pacotes.at(i));
                            break;
                        }
                    }
                }
            }
            break;
        default:
            break;
        }
    } while (option != -1);
}

void remove_pack(Agency &nice_holidays_agency)
{
    int id_pacote;
    int option;
    int position;

    cout << "Qual o id do pacote que quer eliminar?";
    cin >> id_pacote;
    fail();

    if ((position = pacote_position(nice_holidays_agency, id_pacote)) != -1)
    {
        remove_pacote_from_cliente(nice_holidays_agency, id_pacote);
        nice_holidays_agency.lista_de_pacotes.erase(nice_holidays_agency.lista_de_pacotes.begin() + position);
        cout << "Pacote elminado com sucesso" << endl;
    }
    else
    {
        cout << "Esse pacote não existe! Falha na remoção" << endl;
    }
}
void edit_pack(Agency &nice_holidays_agency)
{

    string nome_cliente;
    int option;
    int aux;
    int id;
    int old_id;
    int new_id;
    int position;
    int menu_destinations_option;
    string novo_destino;
    int n__pessoas_max;

    TravelPack t1;
    Date d1;
    vector<int> d2;
    string data;
    string locais_turisticos;
    int dias_data_inicio;
    int dias_data_fim;
    int n_bilhetes_vendidos;

    cout << "ID do pacote que quer alterar?" << endl;
    cin >> id;
    fail();

    position = pacote_position(nice_holidays_agency, id);
    if (position != -1)
    {
        do
        {
            menu_edit_pack();
            cin >> option;
            fail();
            switch (option)
            {
            case 1:
                old_id = nice_holidays_agency.lista_de_pacotes.at(position).id;

                cout << "Novo ID ?";
                cin >> new_id;
                fail();

                if (!check_pack_for_same_id(nice_holidays_agency, new_id))
                {

                    for (int i = 0; i < nice_holidays_agency.lista_de_clientes.size(); i++)
                    {
                        for (int j = 0; j < nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.size(); j++)
                        {
                            if (old_id == nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.at(j))
                            {
                                nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.at(j) = new_id;
                            }
                        }
                    }
                    nice_holidays_agency.lista_de_pacotes.at(position).id = new_id;
                }
                else
                {
                    cout << "Outro pacote já tem esse id , tente novamente !!!" << endl;
                }
                break;
            case 2:
                do
                {
                    menu_edit_pack_destinations();
                    cin >> menu_destinations_option;
                    fail();

                    switch (menu_destinations_option)
                    {
                    case 1:
                        cout << "Qual o novo destino ? " << endl;
                        getline(cin, novo_destino);
                        erase(novo_destino);
                        nice_holidays_agency.lista_de_pacotes.at(position).locais_turisticos.push_back(novo_destino);

                        break;
                    case 2:
                        cout << "Qual o destino a apagar ?" << endl;
                        getline(cin, novo_destino);
                        erase(novo_destino);
                        for (int i = 0; i < nice_holidays_agency.lista_de_pacotes.at(position).locais_turisticos.size(); i++)
                        {
                            if (nice_holidays_agency.lista_de_pacotes.at(position).locais_turisticos.at(i) == novo_destino)
                            {
                                nice_holidays_agency.lista_de_pacotes.at(position).locais_turisticos.erase(nice_holidays_agency.lista_de_pacotes.at(position).locais_turisticos.begin() + i);
                                break;
                            }
                        }
                        break;
                    case 3:
                        nice_holidays_agency.lista_de_pacotes.at(position).locais_turisticos.clear();
                        break;
                    case 4:
                        show_Travel_pack_info(nice_holidays_agency.lista_de_pacotes.at(position));
                        break;
                    }

                } while (menu_destinations_option != -1);

                break;
            case 3:
                cout << "Data de inicio (AAAA/MM/DD)" << endl;
                getline(cin, data);
                decompose_int(data, '/', d2);
                d1.ano = d2.at(0);
                d1.mes = d2.at(1);
                d1.dia = d2.at(2);
                t1.inicio = d1;

                break;

            case 4:
                cout << "Data de fim (AAAA/MM/DD)" << endl;
                d2.clear();
                getline(cin, data);
                decompose_int(data, '/', d2);
                d1.ano = d2.at(0);
                d1.mes = d2.at(1);
                d1.dia = d2.at(2);
                t1.fim = d1;
                break;
            case 5:
                cout << "NOVO Preço do pacote" << endl;
                cin >> nice_holidays_agency.lista_de_pacotes.at(position).preco_pessoa;
                fail();
                break;
            case 6:
                cout << "NOVO N max pessoas" << endl;
                cin >> n__pessoas_max;
                fail();
                if (nice_holidays_agency.lista_de_pacotes.at(position).id < 0 && n__pessoas_max > nice_holidays_agency.lista_de_pacotes.at(position).n_max_pessoas)
                {
                    nice_holidays_agency.lista_de_pacotes.at(position).id = -nice_holidays_agency.lista_de_pacotes.at(position).id;
                }
                nice_holidays_agency.lista_de_pacotes.at(position).n_max_pessoas = n__pessoas_max;
                break;
            case 7:
                cout << "NOVO N bilhetes vendidos" << endl;
                cin >> n_bilhetes_vendidos;
                fail();
                if (n_bilhetes_vendidos < nice_holidays_agency.lista_de_pacotes.at(position).n_max_pessoas)
                {
                    nice_holidays_agency.lista_de_pacotes.at(position).n_bilhetes_vendidos = n_bilhetes_vendidos;
                }
                else if (n_bilhetes_vendidos == nice_holidays_agency.lista_de_pacotes.at(position).n_max_pessoas)
                {
                    nice_holidays_agency.lista_de_pacotes.at(position).id = -nice_holidays_agency.lista_de_pacotes.at(position).id;
                    nice_holidays_agency.lista_de_pacotes.at(position).n_bilhetes_vendidos = n_bilhetes_vendidos;
                }
                else
                {
                    cout << "o numero de bilhetes vendidos ultrapassa o de n maximo de bilhetes" << endl;
                }
                break;
            }
        } while (option != -1);
    }
    else
    {
        cout << "Não há nenhum pacote com id  " << id << endl;
    }
}

void add_pack(Agency &nice_holidays_agency)
{
    TravelPack t1;
    Date d1;
    vector<int> d2;
    string data;
    string locais_turisticos;
    int dias_data_inicio;
    int dias_data_fim;

    cout << "Id do pack                : ";
    cin >> t1.id;
    fail();

    for (int i = 0; i < nice_holidays_agency.lista_de_pacotes.size(); i++)
    {
        if (t1.id == nice_holidays_agency.lista_de_pacotes.at(i).id || t1.id == -nice_holidays_agency.lista_de_pacotes.at(i).id)
        {
            cout << "ID do pacote já se encontra no sistema , tente com outro id";
            break;
        }
    }
    cout << "Destinos turisticos (separados por virgula : " << endl;
    getline(cin, locais_turisticos);
    decompose(locais_turisticos, ',', t1.locais_turisticos);

    cout << "Data de inicio (AAAA/MM/DD)" << endl;
    getline(cin, data);
    decompose_int(data, '/', d2);
    d1.ano = d2.at(0);
    d1.mes = d2.at(1);
    d1.dia = d2.at(2);
    t1.inicio = d1;

    cout << "Data de fim (AAAA/MM/DD)" << endl;
    d2.clear();
    getline(cin, data);
    decompose_int(data, '/', d2);
    d1.ano = d2.at(0);
    d1.mes = d2.at(1);
    d1.dia = d2.at(2);
    t1.fim = d1;

    if (t1.fim.ano < t1.inicio.ano)
    {
        cout << "data de inicio ou fim da viagem erradas" << endl;
        return;
    }
    else if (t1.fim.ano == t1.inicio.ano)
    {
        if (t1.fim.mes < t1.inicio.mes)
        {
            cout << "data de inicio ou fim da viagem erradas" << endl;
            return;
        }
        else if (t1.fim.mes == t1.inicio.mes)
        {
            if (t1.fim.dia < t1.inicio.dia)
            {
                cout << "data de inicio ou fim da viagem erradas" << endl;
                return;
            }
        }
    }

    cout << "Valor de um bilhete (preço unitario) ?  ";
    cin >> t1.preco_pessoa;
    fail();

    if (t1.preco_pessoa < 0)
    {
        cout << "O valor de um bilhete não pode ser negativo" << endl;
        return;
    }

    cout << "Numero maximo de pessoas (preço unitario) ?  ";
    cin >> t1.n_max_pessoas;
    fail();

    if (t1.n_max_pessoas <= 0)
    {
        cout << "O valor maximo de pessoas não pode ser 0 ou negativo" << endl;
        return;
    }

    t1.n_bilhetes_vendidos = 0;
    nice_holidays_agency.lista_de_pacotes.push_back(t1);
}
void remove_pacote_from_cliente(Agency &nice_holidays_agency, int id)
{

    for (int i = 0; i < nice_holidays_agency.lista_de_clientes.size(); i++)
    {
        for (int j = 0; j < nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.size(); j++)
        {
            if (nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.at(j) == id)
            {
                nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.erase(nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.begin() + j);
            }
        }
    }
}

