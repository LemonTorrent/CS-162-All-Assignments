/******************************************************
** Program: sealion.h
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This is the header file that contains the sea lion class
** Input: None
** Output: None
******************************************************/

#ifndef SEA_LION
#define SEA_LION

#include <iostream>
#include "animal.h"

using namespace std;

class SeaLion : public Animal{
public:
    // Constructors
    SeaLion();
    SeaLion(int);
};

#endif