#include<string>
#include<iostream>
#include"name.h"
using namespace std;
struct PHONE_BOOK
{
private:
    char* first_name;
    char* last_name;
    char* father_s_name;
    char* phone_number;
    string* find_family;
public:
PHONE_BOOK();
void write_to_file();
void enter_fio();
void enter_number();
void enter_find_word();
~PHONE_BOOK();
};
