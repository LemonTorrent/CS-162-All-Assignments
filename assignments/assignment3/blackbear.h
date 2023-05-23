/******************************************************
** Program: blackbear.h
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This is the header file that contains the black bear class
** Input: None
** Output: None
******************************************************/

#ifndef BLACK_BEAR
#define BLACK_BEAR

#include <iostream>
#include "animal.h"

using namespace std;

class BlackBear : public Animal{
public:
    // Constructors:
    BlackBear();
    BlackBear(int);
};

#endif