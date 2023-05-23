/******************************************************
** Program: tiger.h
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This is the header file that contains the tiger class
** Input: None
** Output: None
******************************************************/

#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include "animal.h"

using namespace std;

class Tiger : public Animal{
public:
    Tiger();
    Tiger(int);
};

#endif