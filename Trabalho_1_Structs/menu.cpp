#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <ostream>
#include "nice_holidays.hpp"
#include "utilities.hpp"
#include "menu.hpp"
#include "packs.hpp"
#include "clients.hpp"
using namespace std;

int menu_principal()
{
    int menu_principal_option;
    cout << "--------------MENU PRINCIPAL------------" << endl;
    cout << "Visualizar Company info                     (1)" << endl;
    cout << "Clientes                                    (2)" << endl;
    cout << "Pacotes                                     (3)" << endl;
    cout << "Nº total e valor total de pacotes vendidos  (4)" << endl;
    cout << "Sair                                        (-1)" << endl;
    cout << "----------------------------------------" << endl;
    cin >> menu_principal_option;
    if (fail() == -1)
    {
        return 0;
    }
    return menu_principal_option;
}
int menu_pacotes()
{
    int menu_pacotes_option;
    cout << "--------------MENU  PACOTES-----------" << endl;
    cout << "Ver info/ pacote                   (1)" << endl;
    cout << "Adicionar Pacote                   (2)" << endl;
    cout << "Alterar Pacote                     (3)" << endl;
    cout << "Remover Pacote                     (4)" << endl;
    cout << "Menu Principal                     (-1)" << endl;
    cout << "--------------------------------------" << endl;
    cin >> menu_pacotes_option;
    if (fail() == -1)
    {
        return 0;
    }
    return menu_pacotes_option;
}
int menu_clientes()
{
    int menu_cliente_option;
    cout << "------------------------MENU  CLIENTES-------------------" << endl;
    cout << "Ver info/ Todos os Clientes                           (1)" << endl;
    cout << "Ver info/ Cliente específico                          (2)" << endl;
    cout << "Ver Pacotes info dos pacotes comprados por um cliente (3)" << endl;
    cout << "Adicionar Cliente                                     (4)" << endl;
    cout << "Alterar Cliente                                       (5)" << endl;
    cout << "Remover Cliente                                       (6)" << endl;
    cout << "Comprar Pacote para Cliente                           (7)" << endl;
    cout << "Menu Principal                                        (-1)" << endl;
    cout << "---------------------------------------------------------" << endl;
    cin >> menu_cliente_option;
    if (fail() == -1)
    {
        return 0;
    }
    return menu_cliente_option;
}

void menu_specific_pack_info()
{
    cout << "----------Menu Specific pack info--------------" << endl;
    cout << "Todos disponiveis                          (1)" << endl;
    cout << "Todos relativos a um destino               (2)" << endl;
    cout << "Todos entre duas datas                     (3)" << endl;
    cout << "Todos relativos a um destino e entre datas (4)" << endl;
    cout << "sair                                       (-1)" << endl;
    cout << "-----------------------------------------------" << endl;
}

void menu_edit_pack_destinations()
{
    cout << "------Menu edit_pack_destinations--------" << endl;
    cout << "Acrescentar destino turistico         (1)?" << endl;
    cout << "Eliminar destino turistico            (2)" << endl;
    cout << "Eliminar todos os destinos turisticos (3)" << endl;
    cout << "Visualizar info pacote                (4)" << endl;
    cout << "sair                                  (-1)" << endl;
    cout << "-----------------------------------------" << endl;
}

void menu_edit_pack()
{
    cout << "------Menu edit pack-------" << endl;
    cout << "O que quer alterar ?" << endl;
    cout << "ID                    (1)" << endl;
    cout << "Destinos turisticos   (2)" << endl;
    cout << "Data de partida       (3)" << endl;
    cout << "Data de fim           (4)" << endl;
    cout << "Preço                 (5)" << endl;
    cout << "N max de pessoas      (6)" << endl;
    cout << "N de bilhetes vendidos(7)" << endl;
    cout << "sair                  (-1)" << endl;
    cout << "---------------------------" << endl;
}
void menu_edit_client(int nif)
{
    cout << "---MENU EDIT CLIENT----------" << endl;
    cout << "NIF CLIENTE  ---->" << nif << endl;
    cout << "O que quer alterar ?" << endl;
    cout << "Nome                       (1)" << endl;
    cout << "Nif                        (2)" << endl;
    cout << "Endereço                   (3)" << endl;
    cout << "Lista_de_pacotes_comprados (4)" << endl;
    cout << "ver info cliente           (5)" << endl;
    cout << "sair                       (-1)" << endl;
    cout << "-----------------------------" << endl;
}
void menu_buy_client_a_pack()
{
    cout << endl << "------Menu Compra Pacotes--------" << endl;
    cout << "Introduzir ID do pacote ?     (1)" << endl;
    cout << "Visualizar pacotes            (2)" << endl;
    cout << "sair                          (-1)" << endl;
    cout << "---------------------------------" << endl;
}
void menu_edit_client_pacotes_comprados(int nif)
{
    cout << "-----MENU EDIT CLIENT PACOTES-----------" << endl;
    cout << "NIF CLIENTE  ---->" << nif << endl;
    cout << "Adicionar id do pacote que quer     (1)?" << endl;
    cout << "Remover algum pacote dos comprados  (2)?" << endl;
    cout << "Remover todos os pacotes comprados  (3)?" << endl;
    cout << "Visualizar todos os pacotes         (4)?" << endl;
    cout << "sair                                (-1)?" << endl;
    cout << "----------------------------------------" << endl;
}
