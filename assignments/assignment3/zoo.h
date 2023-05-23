/******************************************************
** Program: header.h
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This contains the Zoo class and declarations
** of its functions and variables
** Input: none
** Output: none
******************************************************/

#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include "animal.h"
#include "tiger.h"
#include "blackbear.h"
#include "sealion.h"

using namespace std;

class Zoo {
private:
    int money;                      // amount of money the zoo has
    int month;                      // what month it is
    int month_revanue_bonus;        // money bonus from boom in attendance
    int base_food_cost;             // cost for 1 unit of normal food
    int type_food;                  // stores type of food chosen between months

    // zoo tiger properties:
    int num_tigers;                 // number of tigers
    Tiger* tigers;                  // array that stores the zoo's tigers
    int adult_tigers_bought;        // number of tigers that the user has bought, can buy a maximum of 2

    // zoo sea lion properties:
    int num_sealions;               // number of sea lions
    SeaLion* sealions;              // array that stores the zoo's sea lions
    int adult_sealions_bought;      // number of sea lions that user has bought, can buy maximum of 2

    // black bear properties:
    int num_bears;                  // number of black bears
    BlackBear* blackbears;          // array that stores the zoo's black bears
    int adult_bears_bought;         // number of black bears that the user has bought, can buy maximum of 2

public:
    // Constructors:
    Zoo();
    ~Zoo();

    void start_turn();              // prints zoo information at beginning of turn
    void turn();                    // executes the actions that must occur each month/turn
    int rand_event_generator();     // generates a random event
    void rand_event();              // performs the random event

    void aging_animals();           // increases all animal ages by 1 month

    int get_baby_tigers();          // returns number of baby tigers
    int get_baby_bears();           // returns number of baby bears
    int get_baby_sealions();        // returns number of baby sea lions

    int get_adult_tigers();         // returns number of adult tigers
    int get_adult_bears();          // returns number of adult bears
    int get_adult_sealions();       // returns number of adult sea lions

    void baby_born();               // selects adult to have baby
    void tiger_born();              // adds 3 baby tigers to tiger array
    void bear_born();               // adds 2 baby bears to bear array
    void sealion_born();            // adds 1 baby sea lion to sealion array

    void sick_animal();             // randomly chooses sick animal, finds whether user can pay for medicine
    int get_medicine_cost(const int);       // calculates cost of medicine
    void dying_animal(const int);           // finds the species of the dying animal
    void dying_tiger(const int);            // removes tiger from tiger array
    void dying_bear(const int);             // removes bear from black bear array
    void dying_sealion(const int);          // removes sea lion from sea lion array

    void attendance_boom();         // calculates bonus from attendance boom

    void buy_tiger();               // buys tiger and adds to tiger array
    void buy_bear();                // buys bear and adds to black bear array
    void buy_sealion();             // buys sea lion and adds to sea lion array
    void buy_animal();              // error handles user input if they want to buy animal
    string choose_animal();         // gets user input for animal to buy
    bool check_purchase(string);    // checks whether user has already bought maximum amount of animal

    void revanue();                 // calculates revanue for the month
    int tiger_revanue();            // calculates tiger revanue
    int bear_revanue();             // calculates bear revanue
    int sealion_revanue();          // calculates sea lion revanue

    void pay_food();                // pays for food
    int calculate_base_food();      // calculates base cost for 1 unit of normal food
    float food_choice();            // returns factor to multiply normal food cost by
    int cheap_rand_event();         // calculates random event after feeding animals cheap food
    int premium_rand_event();       // calcualtes random event after feeding animals premium food
    int normal_rand_event();        // calculates random event after feeding animals normal food

    void feed_tigers(int);          // feed tigers and remove cost from money
    void feed_bears(int);           // feed bears and remove cost from money
    void feed_sealions(int);        // feed sea lions and remove cost from money

    bool play_again(int);           // get user input on whether they would like to play again
};

string get_food_choice();       // get food choice from user

#endif