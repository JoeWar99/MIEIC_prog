#pragma once
#include <string>
#include <vector>
#include "nice_holidays.hpp"
#include <iostream>
using namespace std;


void erase_right(string &s);
void erase_left(string &s);
void erase_middle(string &s);
void erase(string &s);
void test(vector<int> vec);
void decompose(string &s, char c_separacao, vector<string> &vec);
void decompose_int(string &s, char c_separacao, vector<int> &vec);
void print_date(ostream &n, Date d1);
int fail();
void ignore_n();
void morada_function(vector<string> vec1, Adress &endereco);



