/******************************************************
** Program: sealion.cpp
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This contains the definitions of the sea lion constructors
** Input: none
** Output: none
******************************************************/

#include <iostream>
#include "animal.h"
#include "sealion.h"

using namespace std;

/*******************************************************************
** Function: SeaLion::SeaLion()
** Description: default constructor for SeaLion
** Parameters: none
*******************************************************************/ 
SeaLion::SeaLion(){
    babies = 1;
    cost = 800;
    food_eaten = 1;
}

/*******************************************************************
** Function: Sealion::Sealion()
** Description: construcor for SeaLion when age is given
** Parameters: a
*******************************************************************/ 
SeaLion::SeaLion(int a){
    babies = 1;
    cost = 800;
    food_eaten = 1;
    age = a;
}

