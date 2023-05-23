/******************************************************
** Program: blackbear.cpp
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This contains the definitions of the black bear constructors
** Input: none
** Output: none
******************************************************/

#include <iostream>
#include "animal.h"
#include "blackbear.h"

using namespace std;

/*******************************************************************
** Function: BlackBear::BlackBear()
** Description: default construtor for BlackBear
** Parameters: none
*******************************************************************/ 
BlackBear::BlackBear(){
    babies = 2;
    cost = 6000;
    food_eaten = 3;
}

/*******************************************************************
** Function: BlackBear::BlackBear()
** Description: constructor for BlackBear when age is given
** Parameters: a
*******************************************************************/ 
BlackBear::BlackBear(int a){
    babies = 2;
    cost = 6000;
    food_eaten = 3;
    age = a;
}
