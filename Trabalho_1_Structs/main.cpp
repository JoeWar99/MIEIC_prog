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

void points()
{
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        cout << "..";
        flush(cout);
    }
    cout << endl;
}

void valor_total(Agency nice_hollidays_agency)
{
    int valor_total = 0;
    for (int i = 0; i < nice_hollidays_agency.lista_de_pacotes.size(); i++)
    {
        valor_total = valor_total + nice_hollidays_agency.lista_de_pacotes.at(i).preco_pessoa * nice_hollidays_agency.lista_de_pacotes.at(i).n_bilhetes_vendidos;
    }
    cout << "O valor total dos pacotes vendidos é  :     " << valor_total << "$" << endl;
}
void pacotes_total(Agency nice_hollidays_agency)
{
    int valor_total = 0;
    for (int i = 0; i < nice_hollidays_agency.lista_de_pacotes.size(); i++)
    {
        valor_total = valor_total + nice_hollidays_agency.lista_de_pacotes.at(i).n_bilhetes_vendidos;
    }
    cout << "O numero total dos pacotes vendidos é :     " << valor_total << endl
         << endl;
}

int main()
{

    Agency nice_holidays_agency;
    int menu_principal_option;
    int menu_cliente_option;
    int menu_pacotes_option;
    cout << "Bem vindo à agência de viagens NiceHolidays!!" << endl
         << endl;

    //    points();
    update_company_info(nice_holidays_agency);
    update_clients_info(nice_holidays_agency);
    update_Packs_info(nice_holidays_agency);

    do
    {
        menu_cliente_option = 0;
        menu_principal_option = 0;
        menu_pacotes_option = 0;
        menu_principal_option = menu_principal();

        if (menu_principal_option != -1)
        {
            switch (menu_principal_option)
            {
            case 1:
                show_company_info(nice_holidays_agency);
                break;
            case 2:
                do
                {
                    menu_cliente_option = menu_clientes();
                    if (menu_cliente_option != -1)
                    {
                        switch (menu_cliente_option)
                        {
                        case 1:
                            show_all_client_info(nice_holidays_agency);
                            break;
                        case 2:
                            show_specific_client_info(nice_holidays_agency);
                            break;
                        case 3:
                            show_packs_for_a_client(nice_holidays_agency);
                            break;
                        case 4:
                            add_client(nice_holidays_agency);
                            break;
                        case 5:
                            edit_client(nice_holidays_agency);
                            break;
                        case 6:
                            remove_client(nice_holidays_agency);
                            break;
                        case 7:
                            buy_client_a_pack(nice_holidays_agency);
                            break;

                        default:
                            cout << "Opção Inválida menu de clientes- Tente Novamente" << endl;
                            // fail();
                            break;
                        }
                    }
                } while (menu_cliente_option != -1);
                break;
            case 3:
                do
                {
                    menu_pacotes_option = menu_pacotes();
                    if (menu_pacotes_option != -1)
                    {
                        switch (menu_pacotes_option)
                        {

                        case 1:
                            show_specific_pack_info(nice_holidays_agency);
                            break;
                        case 2:
                            add_pack(nice_holidays_agency);
                            break;
                        case 3:
                            edit_pack(nice_holidays_agency);
                            break;
                        case 4:
                            remove_pack(nice_holidays_agency);
                            break;
                        default:
                            cout << "Opção Inválida Menu de pacotes - Tente Novamente" << endl;
                            // fail();
                            break;
                        }
                    }
                } while (menu_pacotes_option != -1);
                break;
            case 4:
                valor_total(nice_holidays_agency);
                pacotes_total(nice_holidays_agency);
                break;
            default:
                cout << "Opção Inválida Menu Principal- Tente Novamente" << endl;
                break;
            }
        }
    } while (menu_principal_option != -1);

    write_clients_to_file(nice_holidays_agency);
    write_packs_to_file(nice_holidays_agency);
}