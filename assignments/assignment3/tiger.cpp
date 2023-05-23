/******************************************************
** Program: tiger.cpp
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This contains the definitions of the tiger constructors
** Input: none
** Output: none
******************************************************/

#include <iostream>
#include "animal.h"
#include "tiger.h"

using namespace std;

/*******************************************************************
** Function: Tiger::Tiger()
** Description: default constructor for Tiger
** Parameters: none
*******************************************************************/ 
Tiger::Tiger(){
    babies = 3;
    cost = 15000;
    food_eaten = 5;
}

/*******************************************************************
** Function: Tiger::Tiger()
** Description: constructor for tiger when age is given
** Parameters: a
*******************************************************************/ 
Tiger::Tiger(int a){
    babies = 3;
    cost = 15000;
    food_eaten = 5;
    age = a;
}