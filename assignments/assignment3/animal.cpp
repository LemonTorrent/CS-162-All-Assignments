/******************************************************
** Program: animal.cpp
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This contains the definitions of the tiger constructors,
** getters, and setters
** Input: none
** Output: none
******************************************************/

#include <iostream>
#include "animal.h"

using namespace std;

/*******************************************************************
** Function: Animal::Animal()
** Description: default animal constructor
** Parameters: none
*******************************************************************/ 
Animal::Animal(){

}

/*******************************************************************
** Function: Animal::Animal()
** Description: constructor when age is given
** Parameters: a
*******************************************************************/ 
Animal::Animal(int a){

}

/*******************************************************************
** Function: Animal::set_age()
** Description: sets animal age
** Parameters: a
*******************************************************************/ 
void Animal::set_age(int a){
    age = a;
}

/*******************************************************************
** Function: Animal::get_age()
** Description: returns animal age
** Parameters: none
*******************************************************************/ 
int Animal::get_age() const{
    return age;
}

/*******************************************************************
** Function: Animal::get_cost()
** Description: returns cost
** Parameters: none
*******************************************************************/ 
int Animal::get_cost() const{
    return cost;
}

/*******************************************************************
** Function: Animal::get_babies()
** Description: returns babies
** Parameters: none
*******************************************************************/ 
int Animal::get_babies() const{
    return babies;
}

/*******************************************************************
** Function: Animal::get_food_eaten()
** Description: returns food eaten
** Parameters: none
*******************************************************************/ 
int Animal::get_food_eaten() const{
    return food_eaten;
}

/*******************************************************************
** Function: Animal::get_revanue()
** Description: returns revanue
** Parameters: none
*******************************************************************/ 
int Animal::get_revanue() const{
    return revanue;
}