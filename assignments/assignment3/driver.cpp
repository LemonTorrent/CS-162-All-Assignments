/******************************************************
** Program: driver.cpp
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This is the driver file for the zoo game.
** Input: none
** Output: none
******************************************************/

#include <iostream>
#include "animal.h"
#include "tiger.h"
#include "blackbear.h"
#include "sealion.h"
#include "zoo.h"

using namespace std;

/*******************************************************************
** Function: main()
** Description: creates zoo, starts game
** Parameters: none
*******************************************************************/ 
int main(){
    Zoo zoo;
    zoo.turn();

    return 0;
}