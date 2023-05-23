/******************************************************
** Program: animal.h
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This is the header file that contains the animal class
** Input: None
** Output: None
******************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Animal{
protected:
    int age;            // age in months
    int cost;           // cost to buy animal
    int babies;         // number of babies each animal can have at once
    int food_eaten;     // food units consumed per month
    int revanue;        // revanue per animal

public:
    // constructors:
    Animal();
    Animal(int);        //takes age as input

    // setters
    void set_age(int a);

    // getters
    int get_age() const;
    int get_cost() const;
    int get_babies() const;
    int get_food_eaten() const;
    int get_revanue() const;
};

#endif