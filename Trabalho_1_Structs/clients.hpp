#pragma once

#include "nice_holidays.hpp"
#include <iostream>


void update_clients_info(Agency &nice_holidays_agency);
void show_client_info(Client c1);
int cliente_position(Agency &nice_holidays_agency, int nif);
void show_all_client_info(Agency nice_holidays_agency);
void show_packs_for_a_client(Agency nice_holiday_agency);
void write_clients_to_file(Agency nice_holidays_agency);
bool client_has_pack_with_id(Agency nice_holidays_agency, int id, int nif);
bool check_nif(int nif, Agency nice_holidays_agency);
Client get_client(Agency nice_holidays_agency);
void show_specific_client_info(Agency nice_holidays_agency);
void add_client(Agency &nice_holidays_agency);
void edit_client(Agency &nice_holidays_agency);
void remove_client(Agency &nice_holidays_agency);
void buy_client_a_pack(Agency &nice_holidays_agency);
void remove_pacotes_n_vendidos_when_removing_cliente(Agency &nice_holidays_agency, int nif);