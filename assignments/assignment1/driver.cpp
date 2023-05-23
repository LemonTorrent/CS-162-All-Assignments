/******************************************************
** Program: driver.cpp
** Author: Nicole Yarbrough
** Date: 4/13/2020
** Description: driver file for program that searches 
** spellbook library and prints/saves a list of spellbooks/spells
** that the user can read, contains main function of program
** Input: argc, argv
** Output: None
******************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "./hogwarts.h"

using namespace std;

int main(int argc, char** argv){
    wizard* wiz_db;
    spellbook* spbk_db;
    int num_wiz = 0, num_spbk = 0;
    bool is_student;
    ifstream f;

    if (check_input(f,argc, argv, wiz_db, spbk_db, num_wiz, num_spbk)== true){
        if (login(wiz_db, num_wiz, is_student) == true)
            library_catalog(spbk_db, num_spbk, is_student);
    }

    delete_components(wiz_db, spbk_db, num_wiz, num_spbk);

    return 0;
}
