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


void update_clients_info(Agency &nice_holidays_agency)
{
    Client c1;
    string morada;
    string lixo;
    string pacotes_comprados;
    istringstream aux_stream;
    int pos;
    vector<string> vec1;
    fstream f;
    string s2;
    f.open(nice_holidays_agency.ficheiro_clientes);

    while (!f.eof())
    {
        getline(f, c1.nome);
        f >> c1.nif;
        f.ignore(1000, '\n');
        f >> c1.numero_pessoas_agregado;
        f.ignore(1000, '\n');

        getline(f, morada);
        decompose(morada, '/', vec1);
        morada_function(vec1, c1.endereco);

        getline(f, pacotes_comprados);
        if (pacotes_comprados.size() > 0)
        {
            decompose_int(pacotes_comprados, ';', c1.lista_de_pacotes_comprados);
        }
        getline(f, lixo);

        vec1.clear();
        nice_holidays_agency.lista_de_clientes.push_back(c1);
        c1.lista_de_pacotes_comprados.clear();
    }
    f.close();
}
void show_client_info(Client c1)
{
    cout << "--------------CLIENT INFO-------------------" << endl;
    cout << "Name                   : " << c1.nome << endl;
    cout << "NIF                    : " << c1.nif << endl;
    cout << "Agregado               : " << c1.numero_pessoas_agregado << endl;
    cout << "Morada -> Rua          : " << c1.endereco.nome_rua << endl;
    cout << "       -> Nº porta     : " << c1.endereco.numero_porta << endl;
    cout << "       -> Nº andar     : " << c1.endereco.numero_andar << endl;
    cout << "       -> Codigo P/    : " << c1.endereco.codigo_postal << endl;
    cout << "       -> Localidade   : " << c1.endereco.localidade << endl;
    cout << "ID de Travel Packs ad/ : ";
    for (int i = 0; i < c1.lista_de_pacotes_comprados.size(); i++)
    {
        cout << c1.lista_de_pacotes_comprados.at(i);
        if (i != c1.lista_de_pacotes_comprados.size() - 1)
        {
            cout << " ; ";
        }
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;
}

int cliente_position(Agency &nice_holidays_agency, int nif)
{
    for (int i = 0; i < nice_holidays_agency.lista_de_clientes.size(); i++)
    {
        if (nif == nice_holidays_agency.lista_de_clientes.at(i).nif)
        {
            return i;
        }
        else if (i == nice_holidays_agency.lista_de_clientes.size() - 1)
        {
            return -1;
        }
    }
    return -1;
}
void show_all_client_info(Agency nice_holidays_agency)
{
    if (nice_holidays_agency.lista_de_clientes.size() == 0)
    {
        cout << "Atualizar Travel Packs Primeiro\n";
    }
    else
    {
        for (int i = 0; i < nice_holidays_agency.lista_de_clientes.size(); i++)
        {
            show_client_info(nice_holidays_agency.lista_de_clientes.at(i));
        }
    }
}

void show_packs_for_a_client(Agency nice_holiday_agency)
{
    int nif;
    cout << "Nif do cliente ?" << endl;
    cin >> nif;
    fail();
    int position = cliente_position(nice_holiday_agency, nif);
    int pacotes;

    if (position != -1)
    {
        for (int i = 0; i < nice_holiday_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.size(); i++)
        {
            pacotes = pacote_position(nice_holiday_agency, nice_holiday_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.at(i));
            if (pacotes != -1)
            {
                show_Travel_pack_info(nice_holiday_agency.lista_de_pacotes.at(pacotes));
            }
        }
    }
    else
    {
        cout << "Erro cliente nºao existe !!" << endl;
    }
}

void write_clients_to_file(Agency nice_holidays_agency)
{

    std::ofstream out;
    out.open(nice_holidays_agency.ficheiro_clientes);

    for (int i = 0; i < nice_holidays_agency.lista_de_clientes.size(); i++)
    {
        //show_client_info(nice_holidays_agency.lista_de_clientes.at(i));
        if (i != 0)
        {
            out << "::::::::::" << endl;
        }
        out << nice_holidays_agency.lista_de_clientes.at(i).nome << endl;
        out << nice_holidays_agency.lista_de_clientes.at(i).nif << endl;
        out << nice_holidays_agency.lista_de_clientes.at(i).numero_pessoas_agregado << endl;
        out << nice_holidays_agency.lista_de_clientes.at(i).endereco.nome_rua << " / ";
        out << nice_holidays_agency.lista_de_clientes.at(i).endereco.numero_porta << " / ";
        out << nice_holidays_agency.lista_de_clientes.at(i).endereco.numero_andar << " / ";
        out << nice_holidays_agency.lista_de_clientes.at(i).endereco.codigo_postal << " / ";
        out << nice_holidays_agency.lista_de_clientes.at(i).endereco.localidade << endl;
        for (int j = 0; j < nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.size(); j++)
        {
            out << nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.at(j);
            if (j != nice_holidays_agency.lista_de_clientes.at(i).lista_de_pacotes_comprados.size() - 1)
            {
                out << " ; ";
            }
        }
        out << endl;
    }
    out.close();
}

bool client_has_pack_with_id(Agency nice_holidays_agency, int id, int nif)
{

    int position;
    position = cliente_position(nice_holidays_agency, nif);

    for (int i = 0; i < nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.size(); i++)
    {
        if (nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.at(i) == id)
        {
            return true;
        }
    }
    return false;
}


bool check_nif(int nif, Agency nice_holidays_agency)
{
    for (int i = 0; i < nice_holidays_agency.lista_de_clientes.size(); i++)
    {
        if (nif == nice_holidays_agency.lista_de_clientes.at(i).nif)
        {
            return true;
        }
    }
    return false;
}

Client get_client(Agency nice_holidays_agency)
{
    int nif_cliente;
    cout << "Nif do Cliente?" << endl;
    Client c1;
    cin >> nif_cliente;
    fail();

    for (int i = 0; i < nice_holidays_agency.lista_de_clientes.size(); i++)
    {
        if (nif_cliente == nice_holidays_agency.lista_de_clientes.at(i).nif)
        {
            c1 = nice_holidays_agency.lista_de_clientes.at(i);
            return c1;
        }
    }
    return c1;
}

void show_specific_client_info(Agency nice_holidays_agency)
{
    int nif_cliente;
    cout << "Nif do Cliente ?";
    cin >> nif_cliente;
    fail();

    for (int i = 0; i < nice_holidays_agency.lista_de_clientes.size(); i++)
    {
        if (nif_cliente == nice_holidays_agency.lista_de_clientes.at(i).nif)
        {
            show_client_info(nice_holidays_agency.lista_de_clientes.at(i));
            break;
        }
        else if (i == nice_holidays_agency.lista_de_clientes.size() - 1)
        {
            cout << "Não Há nenhum cliente com o nif :   " << nif_cliente << endl;
        }
    }
}



void add_client(Agency &nice_holidays_agency)
{
    Client c1;
    string lista_de_pacotes;
    vector<string> vec1;
    cout << "Nome cliente              : ";
    getline(cin, c1.nome);

    cout << endl;

    cout << "NIF                       : ";
    cin >> c1.nif;

    if (check_nif(c1.nif, nice_holidays_agency))
    {
        cout << "Esse Nif já pertence a outro cliente (Roubo de identidade)" << endl;
        return;
    }
    fail();
    cout << endl;

    cout << "N/ pessoas agregado       : ";
    cin >> c1.numero_pessoas_agregado;
    fail();
    cout << endl;

    cout << "Endereço--->Rua           : ";
    getline(cin, c1.endereco.nome_rua);
    cout << "Endereço--->numero andar  : ";
    getline(cin, c1.endereco.numero_andar);
    cout << "Endereço--->codigo postal: ";
    getline(cin, c1.endereco.codigo_postal);
    cout << "Endereço--->localidade : ";
    getline(cin, c1.endereco.localidade);
    cout << endl;
    c1.lista_de_pacotes_comprados.clear();
    erase(c1.nome);
    erase(c1.endereco.numero_andar);
    erase(c1.endereco.nome_rua);
    erase(c1.endereco.codigo_postal);
    erase(c1.endereco.localidade);

    nice_holidays_agency.lista_de_clientes.push_back(c1);

    cout << endl;
}


void edit_client(Agency &nice_holidays_agency)
{
    int nif;
    int option;
    int aux;
    int position;
    int novo_nif;
    int pacote_id_eliminar;
    int menu_edit_destination;
    int position_pacote;
    int pacote_id_adicionar;

    cout << "Nif do cliente que quer modificar?" << endl;
    cin >> nif;
    fail();

    position = cliente_position(nice_holidays_agency, nif);

    if (position != -1)
    {
        do
        {
            menu_edit_client(nice_holidays_agency.lista_de_clientes.at(position).nif);
            cin >> option;
            fail();
            switch (option)
            {
            case 1:
                cout << "Novo nome ?";
                getline(cin, nice_holidays_agency.lista_de_clientes.at(position).nome);
                break;
            case 2:
                cout << "Novo nif ?";
                cin >> novo_nif;
                fail();
                if (novo_nif != nice_holidays_agency.lista_de_clientes.at(position).nif)
                {
                    if (!check_nif(novo_nif, nice_holidays_agency))
                    {
                        nice_holidays_agency.lista_de_clientes.at(position).nif = novo_nif;
                    }
                    else
                    {
                        cout << "Esse Nif já pertence a outro cliente (Roubo de identidade)" << endl;
                    }
                }
                break;

            case 3:
                cout << "Novo endereço!!" << endl;
                cout << "nome rua? ";
                getline(cin, nice_holidays_agency.lista_de_clientes.at(position).endereco.nome_rua);
                cout << endl;
                cout << "numero porta? ";
                cin >> nice_holidays_agency.lista_de_clientes.at(position).endereco.numero_porta;
                cout << endl;
                fail();
                cout << "Numero andar?  ";
                getline(cin, nice_holidays_agency.lista_de_clientes.at(position).endereco.numero_andar);
                cout << endl;
                cout << "Codigo Postal? ";
                getline(cin, nice_holidays_agency.lista_de_clientes.at(position).endereco.codigo_postal);
                cout << "Localidade ?";
                getline(cin, nice_holidays_agency.lista_de_clientes.at(position).endereco.localidade);
                break;

            case 4:
                do
                {
                    menu_edit_client_pacotes_comprados(nice_holidays_agency.lista_de_clientes.at(position).nif);
                    cin >> menu_edit_destination;
                    fail();
                    switch (menu_edit_destination)
                    {
                    case 1:
                        cout << "Qual o id do pacote a adicionar a lista de pacotes comprados pelo cliente ? " << endl;
                        cin >> pacote_id_adicionar;
                        fail();
                        position_pacote = pacote_position(nice_holidays_agency, pacote_id_adicionar);
                        if (position_pacote != -1)
                        {
                            if (!client_has_pack_with_id(nice_holidays_agency, pacote_id_adicionar, nif))
                            {
                                nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.push_back(pacote_id_adicionar);
                                nice_holidays_agency.lista_de_pacotes.at(position_pacote).n_bilhetes_vendidos++;
                            }
                            else
                            {
                                cout << "cliente já adquiriu o pacote" << endl;
                            }
                        }
                        else
                        {
                            cout << "Pacote não existe tente novamente" << endl;
                        }
                        break;

                    case 2:
                        cout << "Qual o id do pacote que quer eliminar da lista de comprados deste cliente ?" << endl;
                        cin >> pacote_id_eliminar;
                        fail();
                        position_pacote = pacote_position(nice_holidays_agency, pacote_id_eliminar);
                        if (position_pacote != -1)
                        {
                            for (int j = 0; j < nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.size(); j++)
                            {
                                if (pacote_id_eliminar == nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.at(j))
                                {
                                    nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.erase(nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.begin() + j);
                                    break;
                                }
                            }
                            nice_holidays_agency.lista_de_pacotes.at(pacote_id_eliminar).n_bilhetes_vendidos--;
                            if (nice_holidays_agency.lista_de_pacotes.at(pacote_id_eliminar).id < 0)
                            {
                                if (nice_holidays_agency.lista_de_pacotes.at(pacote_id_eliminar).n_bilhetes_vendidos < nice_holidays_agency.lista_de_pacotes.at(pacote_id_eliminar).n_max_pessoas)
                                {
                                    nice_holidays_agency.lista_de_pacotes.at(pacote_id_eliminar).id = nice_holidays_agency.lista_de_pacotes.at(pacote_id_eliminar).id;
                                }
                            }
                        }
                        else
                        {
                            cout << "Pacote não existe na base de dados" << endl;
                        }

                        break;

                    case 3:
                        for (int i = 0; i < nice_holidays_agency.lista_de_pacotes.size(); i++)
                        {
                            for (int j = 0; j < nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.size(); j++)
                            {
                                if (nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.at(j) == nice_holidays_agency.lista_de_pacotes.at(i).id)
                                {
                                    nice_holidays_agency.lista_de_pacotes.at(i).n_bilhetes_vendidos--;
                                    break;
                                }
                            }
                        }
                        nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.clear();
                        break;
                    case 4:
                        show_all_pack_info(nice_holidays_agency);
                        break;
                    }
                } while (menu_edit_destination != -1);
                break;
            case 5:
                show_client_info(nice_holidays_agency.lista_de_clientes.at(position));
                break;
            }
        } while (option != -1);
    }

    else
    {
        cout << "Não Há nenhum cliente com o nif :   " << nif << endl;
    }
}

void remove_client(Agency &nice_holidays_agency)
{
    string nome_cliente;
    int nif;
    int position;

    cout << "Nif do cliente que quer remover?" << endl;
    cin >> nif;
    fail();

    for (int i = 0; i < nice_holidays_agency.lista_de_clientes.size(); i++)
    {
        if (nif == nice_holidays_agency.lista_de_clientes.at(i).nif)
        {
            remove_pacotes_n_vendidos_when_removing_cliente(nice_holidays_agency, nif);
            nice_holidays_agency.lista_de_clientes.erase(nice_holidays_agency.lista_de_clientes.begin() + i);
            break;
        }
        else if (i == nice_holidays_agency.lista_de_clientes.size() - 1)
        {
            cout << "Não Há nenhum cliente com o nome :   " << nome_cliente << endl;
        }
    }
}


void buy_client_a_pack(Agency &nice_holidays_agency)
{
    int nif_cliente;
    int option;
    int aux;
    int pacote_edit_option;
    int pacote_id_aux;
    int position;
    int pacotes_position;

    cout << endl
         << "Nif do Cliente que quer comprar o pacote?  ";
    cin >> nif_cliente;
    fail();

    position = cliente_position(nice_holidays_agency, nif_cliente);

    if (position != -1)
    {

        do
        {
            pacote_edit_option = 0;
            menu_buy_client_a_pack();
            cin >> pacote_edit_option;
            fail();
            if (pacote_edit_option != -1)
            {
                switch (pacote_edit_option)
                {
                case 1:
                    cout << endl
                         << "Qual o id do pacote?" << endl;
                    cin >> pacote_id_aux;
                    fail();
                    pacotes_position = pacote_position(nice_holidays_agency, pacote_id_aux);
                    if (pacotes_position != -1)
                    {
                        if (!client_has_pack_with_id(nice_holidays_agency, pacote_id_aux, nif_cliente))
                        {

                            if (nice_holidays_agency.lista_de_pacotes.at(pacotes_position).n_bilhetes_vendidos == nice_holidays_agency.lista_de_pacotes.at(pacotes_position).n_max_pessoas)
                            {
                                cout << "Pacote com o maximo de clientes - COMPRA INDISPONIVEL" << endl
                                     << endl;
                            }
                            else
                            {
                                nice_holidays_agency.lista_de_pacotes.at(pacotes_position).n_bilhetes_vendidos++;
                                nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.push_back(pacote_id_aux);
                                if (nice_holidays_agency.lista_de_pacotes.at(pacotes_position).n_bilhetes_vendidos == nice_holidays_agency.lista_de_pacotes.at(pacotes_position).n_max_pessoas)
                                {
                                    //cout << "entrei aqui" << endl;
                                    nice_holidays_agency.lista_de_pacotes.at(pacotes_position).id = -nice_holidays_agency.lista_de_pacotes.at(pacotes_position).id;
                                }
                                cout << "Pacote adiquirido com SUCESSO - Boa viagem" << endl
                                     << endl;
                            }
                        }
                        else
                        {
                            cout << "CLIENTE JÁ ADQUIRIU O PACOTE" << endl;
                        }
                    }
                    else
                    {
                        cout << "ID do pacote inválido !!" << endl;
                    }
                    break;

                case 2:
                    show_all_pack_info(nice_holidays_agency);
                    break;
                default:
                    cout << "Opção valida - Tente novamente" << endl;
                    break;
                }
            }
        } while (pacote_edit_option != -1);
    }
    else
    {
        cout << "Não Há nenhum cliente com o nif  :   " << nif_cliente << endl;
    }
}

void remove_pacotes_n_vendidos_when_removing_cliente(Agency &nice_holidays_agency, int nif)
{
    int position;

    position = cliente_position(nice_holidays_agency, nif);

    if (position != -1)
    {
        for (int j = 0; j < nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.size(); j++)
        {
            for (int i = 0; i < nice_holidays_agency.lista_de_pacotes.size(); i++)
            {
                if (nice_holidays_agency.lista_de_clientes.at(position).lista_de_pacotes_comprados.at(j) == nice_holidays_agency.lista_de_pacotes.at(i).id)
                {
                    nice_holidays_agency.lista_de_pacotes.at(i).n_bilhetes_vendidos--;
                }
            }
        }
    }
    else
    {
        cout << "cliente não existe" << endl;
    }
}

