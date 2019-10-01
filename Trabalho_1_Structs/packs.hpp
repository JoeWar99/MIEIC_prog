#pragma once

#include "nice_holidays.hpp"
#include <iostream>

void update_Packs_info(Agency &nice_holidays_agency);
void write_packs_to_file(Agency nice_holidays_agency);
void show_Travel_pack_info(TravelPack t1);
void show_all_pack_info(Agency nice_holidays_agency);
int find_travelpack(int id_travel_pack, Agency nice_holidays_agency);
bool check_pack_for_same_id(Agency nice_holidays_agency, int id);
int pacote_position(Agency &nice_holidays_agency, int id);
void show_total_sold_packs(Agency nice_holiday_agency);
void show_specific_pack_info(Agency nice_holiday_agency);
void remove_pack(Agency &nice_holidays_agency);
void edit_pack(Agency &nice_holidays_agency);
void add_pack(Agency &nice_holidays_agency);
void remove_pacote_from_cliente(Agency &nice_holidays_agency, int id);