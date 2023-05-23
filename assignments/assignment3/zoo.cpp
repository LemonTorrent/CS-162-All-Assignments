/******************************************************
** Program: zoo.cpp
** Author: Nicole Yarbrough
** Date: 05/10/2020
** Description: This contains the definitions of the functions listed in zoo.h
** Input: none
** Output: none
******************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "zoo.h"
#include "animal.h"
#include "tiger.h"
#include "blackbear.h"
#include "sealion.h"

using namespace std;

/*******************************************************************
** Function: Zoo::Zoo()
** Description: The constructor for Zoo
** Parameters: None
*******************************************************************/ 
Zoo::Zoo(){
    //starting properties of the first round of the zoo:
    money = 100000;
    month = 1;

    month_revanue_bonus = 0;
    type_food = 2;

    //tiger stuff
    num_tigers = 0;
    adult_tigers_bought = 0;
    tigers = NULL;

    //sea lion stuff
    num_sealions = 0;
    adult_sealions_bought = 0;
    sealions = NULL;
    
    //bear stuff
    num_bears = 0;
    adult_bears_bought = 0;
    blackbears = NULL;
}

/*******************************************************************
** Function: Zoo::play_again()
** Description: gets user input on whether they would like to play again. If they don't,
** function returns false. Otherwise, food expenses for the upcoming month are paid and 
** function returns true.
** Parameters: money
*******************************************************************/ 
bool Zoo::play_again(int money){
    string temp = "";
    if (money <= 0){ //game play stops if the zoo does not have any money.
        cout << "The game has ended. You have " << money << " dollars!" << endl;
        return false;
    }
    
    do{     //error handle user's choice to continue game or quit
        cout << "Would you like to play again? Enter 0 to quit, or 1 to continue play." << endl;
        cin >> temp;
    } while (temp != "0" && temp != "1");

    if (temp == "0")
        return false;   //user doesn't want to continue play
    
    pay_food();     //user chooses which food to feed animals the next month, pays for food
    return true;        //user wants to continue play
}

/*******************************************************************
** Function: Zoo::aging_animal()
** Description: adds one month to the age of all animal
** Parameters: none
*******************************************************************/ 
void Zoo::aging_animals(){
    int current_age;

    //Adds 1 month to the age of all tigers
    for (int i = 0; i < num_tigers; i++){
        current_age = tigers[i].get_age();
        tigers[i].set_age(current_age + 1);
    }

    //Add 1 month to the age of all bears
    for (int i = 0; i < num_bears; i++){
        current_age = blackbears[i].get_age();
        blackbears[i].set_age(current_age + 1);
    }

    //Add 1 month to the age of all sea lions
    for (int i = 0; i < num_sealions; i++){
        current_age = sealions[i].get_age();
        sealions[i].set_age(current_age + 1);
    }
}

/*******************************************************************
** Function: Zoo::start_turn()
** Description: adds one month to the age of all animals, prints month,
** money, and zoo's contents to the screen
** Parameters: none
*******************************************************************/ 
void Zoo::start_turn(){
    // calculates number of adult, baby, and adolescent tigers
    int adult_tigers = get_adult_tigers();
    int baby_tigers = get_baby_tigers();
    int adolescent_tigers = num_tigers - baby_tigers - adult_tigers;

    // calculates number of adult, baby, and adolescent bears
    int adult_bears = get_adult_bears();
    int baby_bears = get_baby_bears();
    int adolescent_bears = num_bears - baby_bears - adult_bears;

    // calculates number of adult, baby, and adolescent sea lions
    int adult_sealions = get_adult_sealions();
    int baby_sealions = get_baby_sealions();
    int adolescent_sealions = num_sealions - baby_sealions - adult_sealions;

    // prints month, money, and amount of animals to the screen
    cout << "Month " << month << endl;
    cout << "You have $" << money << " in the bank." << endl;
    cout << "Tigers: " << adult_tigers << " adults, " << baby_tigers << " babies, and " << adolescent_tigers << " adolescents." << endl;
    cout << "Blackbears: " << adult_bears << " adults, " << baby_bears << " babies, and " << adolescent_bears << " adolescents." << endl;
    cout << "Sea Lions: " << adult_sealions << " adults, " << baby_sealions << " babies, and " << adolescent_sealions << " adolescents." << endl;
}

/*******************************************************************
** Function: Zoo::turn()
** Description: executes the actions that occur each turn: a random event,
** buying an animal, calculating revanue, and animals getting older.
** Parameters: none
*******************************************************************/ 
void Zoo::turn(){
    bool another_turn;

    do{     //Player will play 1 or more rounds of the game.
        start_turn();
        if (month > 1)
            rand_event();   //random event occurs
        buy_animal();   //user gets choice to buy an animal
        revanue();      //calculates revanue from the month
        another_turn = play_again(money);   //asks user if they would like to play again
        month += 1;     //month count increases by 1 month for the next turn
        aging_animals();    //animals are all 1 month older
        month_revanue_bonus = 0;    //resets bonus to 0
        cout << endl;
    } while (another_turn == true);     // continue while user wants to continue play and they have enough money

    cout << "Thank you for playing!" << endl;
}

/*******************************************************************
** Function: Zoo::tiger_revanue()
** Description: calculates revanue from tigers
** Parameters: none
*******************************************************************/ 
int Zoo::tiger_revanue(){
    int month_revanue = 0;
    
    for (int i = 0; i < num_tigers; i++){       //goes through all of the tigers in the array
        if (tigers[i].get_age() < 6){           //calculates revanue of babies
            month_revanue += (tigers[i].get_cost() * .2);
        } else {                                //calculates revanue of adolescents and adults
            month_revanue += (tigers[i].get_cost() * .1);
        }
    }

    return month_revanue;
}

/*******************************************************************
** Function: Zoo::bear_revanue()
** Description: calculates revanue from bears
** Parameters: none
*******************************************************************/ 
int Zoo::bear_revanue(){
    int month_revanue = 0;

    for (int j = 0; j < num_bears; j++){        //goes through all bears in array
        if (blackbears[j].get_age() < 6){       //calculates revanue of babies
            month_revanue += (blackbears[j].get_cost() * .2);
        } else {                                //calculates revanue of adolescents and adults
            month_revanue += (blackbears[j].get_cost() * .1);
        }
    }

    return month_revanue;    
}

/*******************************************************************
** Function: Zoo::aging_animal()
** Description: calculates revanue from sea lions
** Parameters: none
*******************************************************************/ 
int Zoo::sealion_revanue(){
    int month_revanue = 0;

    for (int k = 0; k < num_sealions; k++){     //goes through all sea lions in array
        if (sealions[k].get_age() < 6){         //calculates revanue of babies
            month_revanue += (sealions[k].get_cost() * .4);
        } else {                                //calculates revanue of adolescents and adults
            month_revanue += (sealions[k].get_cost() * .2);
        }
    }

    return month_revanue;
}

/*******************************************************************
** Function: Zoo::aging_animal()
** Description: adds revanue from bears, tigers, and sea lions, prints
** month revanue and bonus, adds revanue and bonus to money.
** Parameters: none
*******************************************************************/ 
void Zoo::revanue(){
    int month_revanue = 0;

   month_revanue += tiger_revanue();        //adds tiger revanue to monthly revanue
   month_revanue += bear_revanue();         //adds bear revanue to montly revanue
   month_revanue += sealion_revanue();      //adds sealion revanue to monthly revanue

    cout << "Month revanue = " << month_revanue << endl;
    cout << "Month revanue bonus = " << month_revanue_bonus << endl;

    money += month_revanue;                 //adds month revanue to money
    money += month_revanue_bonus;           //adds bonus to money
}

/*******************************************************************
** Function: Zoo::calculate_base_food()
** Description: calculates base food cost for 1 unit of normal food, 
** returns cost of food
** Parameters: none
*******************************************************************/ 
int Zoo::calculate_base_food(){
    float food_cost_change = 1.0;

    if (month == 1){
        base_food_cost = 80;        // sets food cost on the first turn to 80
        return 80;
    }
    
    food_cost_change = (rand() % 41 + 80);      // gets random value between 80 and 120
    base_food_cost *= float(food_cost_change * .01);    // adjusts food cost based on random value

    return base_food_cost;
}

/*******************************************************************
** Function: Zoo::get_food_choice()
** Description: gets user's choice of food for the upcoming month
** also prints the price and effect of each type of food. Returns food
** choice.
** Parameters: none
*******************************************************************/ 
string get_food_choice(){
    string input;

    do{
        do{
            cout << "Enter 1 for cheap food, 2 for normal food, 3 for premium ";
            cout << "food, or 4 for an explanation of each type of food" << endl;
            cin >> input;
        } while (input != "1" && input != "2" && input != "3" && input != "4");     // error handle user input

        if (input == "4"){
            cout << "Cheap food costs half the cost of normal food but makes ";
            cout << "animals twice as likely to get sick. Premium food costs ";
            cout << "twice as much as normal food, but animals are half as ";
            cout << "likely to get sick." << endl;

            cout << "The cost to feed each animal is the cost per food unit ";
            cout << "times the amount of food units that they will eat." << endl;
        }

    } while (input != "1" && input != "2" && input != "3");     // error handle user input,  continue until user chooses food type

    return input;
}

/*******************************************************************
** Function: Zoo::food_choice()
** Description: returns factor to multiply food cost by
** Parameters: none
*******************************************************************/ 
float Zoo::food_choice(){
    string input = get_food_choice();   // gets food choice

    if (input == "1"){
        type_food = 1;
        return 0.5;                     // cheap food costs .5 of normal
    } else if (input == "2"){
        type_food = 2;
        return 1;                       // normal food costs normal price
    } else {
        type_food = 3;
        return 2;                       // premium food costs double normal price
    }
}

/*******************************************************************
** Function: Zoo::feed_tigers()
** Description: calculates cost to feed tigers
** Parameters: food_price
*******************************************************************/ 
void Zoo::feed_tigers(int food_price){
    int cost_tiger_food = 0;

    for (int i = 0; i < num_tigers; i++){
        cost_tiger_food += tigers[i].get_food_eaten();  // gets number of food each tiger eats
    }

    money -= cost_tiger_food * food_price;              // subtracts cost to feed tigers from money
}

/*******************************************************************
** Function: Zoo::feed_bears()
** Description: calculates cost to feed bears
** Parameters: food_price
*******************************************************************/ 
void Zoo::feed_bears(int food_price){
    int cost_bear_food = 0;

    for (int i = 0; i < num_bears; i++){
        cost_bear_food += blackbears[i].get_food_eaten();   // gets number of food each bear eats
    }

    money -= cost_bear_food * food_price;               // subtracts cost to feed bears from money
}

/*******************************************************************
** Function: Zoo::feed_sealions()
** Description: calculates cost to feed sea lion
** Parameters: food_price
*******************************************************************/ 
void Zoo::feed_sealions(int food_price){
    int cost_sealion_food = 0;

    for (int i = 0; i < num_sealions; i++){
        cost_sealion_food += sealions[i].get_food_eaten();      // gets number of food each sea lion eats
    }

    money -= cost_sealion_food * food_price;            // subtracts cost to feed sea lions from money
}

/*******************************************************************
** Function: Zoo::pay_food()
** Description: prints feeding information to screen, calls functions
** to feed animals
** Parameters: none
*******************************************************************/ 
void Zoo::pay_food(){
    int total_cost, basic_food = calculate_base_food();
    float choice_food;

    cout << "The cost for a single unit of basic food is $" << basic_food << endl;
    choice_food = food_choice();

    total_cost = choice_food * basic_food;  // calculates cost for chosen food

    cout << "That will be $" << total_cost << " per unit of food." << endl;
    
    feed_tigers(total_cost);    // pays for food for tigers
    feed_bears(total_cost);     // pays for food for bears
    feed_sealions(total_cost);  // pays for food for sea lions

    cout << "After paying for food for the next month, you have $" << money << " remaining" << endl;
}

/*******************************************************************
** Function: Zoo::aging_animal()
** Description: generates random event in response to feeding animals
** cheap food. Returns event
** Parameters: none
*******************************************************************/ 
int Zoo::cheap_rand_event(){    //cheap food chosen, twice the risk for sickness
    int event;  //random event
    srand(time(NULL));

    if (num_tigers + num_sealions + num_bears > 0){ //checks if there are animals in the zoo
        if (get_adult_bears() > 0 || get_adult_sealions() > 0 ||   // checks if there are adults
        get_adult_tigers() > 0){
            event = rand() % 6 + 1; //all events are possible, random generator between 1-6. 1 = nothing, 2 = visitor boom, 3-5 = sick animal, 6 = baby animal
            if (event == 4 || event == 5)
                return 3;           // returns sick animal if generated number is 
            if (event == 6)
                return 4;           // returns that a baby will be born
        } else {
            event = rand() % 6 + 1; // no adults, only generates events 1-3 (nothing, attendance boom, or sickness)
            if (event == 4 || event == 5 || event == 6)
                return 3;           // returns that an animal is sick
        }
    } else {
        event = rand() % 2 + 1; //no animals (hopefully this won't happen)
    }

    return event;   // returns 1 (nothing happens) or 2 (visitor boom)
}

/*******************************************************************
** Function: Zoo::premium_rand_event()
** Description: generates random event in response to feeding animals
** premium food. Returns event.
** Parameters: none
*******************************************************************/ 
int Zoo::premium_rand_event(){
    int event;  //random event
    srand(time(NULL));

    // 1,2 = nothing, 3,4 = visitor boom, 5 = sick animal, 6,7 = baby born

    if (num_tigers + num_sealions + num_bears > 0){ //checks if there are animals in the zoo
        if (get_adult_bears() > 0 || get_adult_sealions() > 0 ||   // checks if there are adults
        get_adult_tigers() > 0){
            event = rand() % 7 + 1; //all events are possible, random generator between 1-4
        } else {
            event = rand() % 5 + 1; // no adults, only generates random number 1-3
        }
    } else {
        event = rand() % 4 + 1; //no animals (hopefully this won't happen)
    }

    if (event == 1 || event == 2)       // nothing happens
        return 1;
    if (event == 3 || event == 4)       // attendance boom
        return 2;
    if (event == 5)                     // sick animal
        return 3;
    if (event == 6 || event == 7)       // baby born
        return 4;
}

/*******************************************************************
** Function: Zoo::aging_animal()
** Description: generates random event when animals are fed normal food.
** Returns event.
** Parameters: none
*******************************************************************/ 
int Zoo::normal_rand_event(){
    int event;  //random event

    srand(time(NULL));

    if (num_tigers + num_sealions + num_bears > 0){ //checks if there are animals in the zoo
        if (get_adult_bears() > 0 || get_adult_sealions() > 0 ||   // checks if there are adults
        get_adult_tigers() > 0){
            event = rand() % 4 + 1; //all events are possible, random generator between 1-4
        } else {
            event = rand() % 3 + 1; // no adults, only generates random number 1-3
        }
    } else {
        event = rand() % 2 + 1; //no animals (hopefully this won't happen)
    }

    // event 1 = nothing happens
    // event 2 = attendance boom
    // event 3 = sick animal
    // event 4 = baby is born

    return event;
}

/*******************************************************************
** Function: Zoo::rand_event_generator()
** Description: calls function respective to type of food user fed their
** animals
** Parameters: none
*******************************************************************/ 
int Zoo::rand_event_generator(){
    int event;  //stores type of event

    if (type_food == 1) {           //if user chooses cheap food
        event = cheap_rand_event();
    } else if (type_food == 3){     //if user chooses premium food
        event = premium_rand_event();
    } else {    //if type_food is at default value or normal food is chosen
        event = normal_rand_event();
    }

    return event;
}

/*******************************************************************
** Function: Zoo::aging_animal()
** Description: adds baby tiger to tiger array
** Parameters: none
*******************************************************************/ 
void Zoo::tiger_born(){
    int num_cubs = 3;
    Tiger temp_tiger(0);
    Tiger* temp_tiger_location = tigers;    // stores current array address in temporary location

    num_tigers += num_cubs;                 // increases number of tigers by 1

    tigers = new Tiger [num_tigers];        // creates new dynamic tiger array
    for (int i = 0; i < num_tigers - num_cubs; i++){        // fills new array with data from old array
        tigers[i] = temp_tiger_location[i];
    }

    delete [] temp_tiger_location;          // deletes old array
    
    for (int j = num_tigers - num_cubs; j < num_tigers; j++){
        tigers[j] = temp_tiger;    // adds baby tiger to tiger array
    }
}

/*******************************************************************
** Function: Zoo::bear_born()
** Description: adds baby bear to black bear array
** Parameters: none
*******************************************************************/ 
void Zoo::bear_born(){
    int num_cubs = 2;
    BlackBear temp_bear(0);
    BlackBear* temp_bear_location = blackbears; // stores current array address in temporary location

    num_bears += num_cubs;  // increases number of bears

    blackbears = new BlackBear [num_bears];     // creates new bear array

    for (int i = 0; i < num_bears - num_cubs; i++){
        blackbears[i] = temp_bear_location[i];      // copies old bear data to new bear array
    }

    delete [] temp_bear_location;       // deletes old array
    
    for (int j = num_bears - num_cubs; j < num_bears; j++){
        blackbears[j] = temp_bear;  // adds bear cub to array
    }
}

/*******************************************************************
** Function: Zoo::sealion_born()
** Description: adds baby sea lion to sea lion array
** Parameters: none
*******************************************************************/ 
void Zoo::sealion_born(){
    SeaLion temp_sealion(0);
    SeaLion* temp_sealion_location = sealions;  // stores old sea lion array address in temporary location

    num_sealions += 1;      // adds 1 to number of sea lions

    sealions = new SeaLion [num_sealions];      // creates new sea lion array
    for (int i = 0; i < num_sealions - 1; i++){     // adds old sea lion data to new sea lion array
        sealions[i] = temp_sealion_location[i];
    }

    delete [] temp_sealion_location;        // delete old array
    
    sealions[num_sealions - 1] = temp_sealion;   // adds baby sealion to array
}

/*******************************************************************
** Function: Zoo::get_baby_tigers()
** Description: calculates and returns number of baby tigers
** Parameters: none
*******************************************************************/ 
int Zoo::get_baby_tigers(){
    int baby_tigers = 0;

    for (int i = 0; i < num_tigers; i++){
        if (tigers[i].get_age() < 6)
            baby_tigers += 1;       // counts number of baby tigers
    }

    return baby_tigers;
}

/*******************************************************************
** Function: Zoo::get_baby_bearss()
** Description: calculates and returns number of baby bears
** Parameters: none
*******************************************************************/
int Zoo::get_baby_bears(){
    int baby_bears = 0;

    for (int i = 0; i < num_bears; i++){
        if (blackbears[i].get_age() < 6)
            baby_bears += 1;        // counts number of baby bears
    }

    return baby_bears;
}

/*******************************************************************
** Function: Zoo::get_baby_sealions()
** Description: calculates and returns number of baby sea lions
** Parameters: none
*******************************************************************/ 
int Zoo::get_baby_sealions(){
    int baby_sealions = 0;

    for (int i = 0; i < num_sealions; i++){
        if (sealions[i].get_age() < 6)
            baby_sealions += 1;     // counts number of baby sea lions
    }

    return baby_sealions;
}

/*******************************************************************
** Function: Zoo::get_adult_tigers()
** Description: calculates and returns number of adult tigers
** Parameters: none
*******************************************************************/ 
int Zoo::get_adult_tigers(){
    int adult_tigers = 0;

    for (int i = 0; i < num_tigers; i++){
        if (tigers[i].get_age() >= 48)
            adult_tigers += 1;      // counts number of adult tigers
    }

    return adult_tigers;
}

/*******************************************************************
** Function: Zoo::get_adult_bearss()
** Description: calculates and returns number of adult bears
** Parameters: none
*******************************************************************/ 
int Zoo::get_adult_bears(){
    int adult_bears = 0;

    for (int i = 0; i < num_bears; i++){
        if (blackbears[i].get_age() >= 48)
            adult_bears += 1;       // counts number of adult bears
    }

    return adult_bears;
}

/*******************************************************************
** Function: Zoo::get_adult_sealions()
** Description: calculates and returns number of adult sea lions
** Parameters: none
*******************************************************************/ 
int Zoo::get_adult_sealions(){
    int adult_sealions = 0;

    for (int i = 0; i < num_sealions; i++){
        if (sealions[i].get_age() >= 48)
            adult_sealions += 1;        // counts number of adult sea lions
    }

    return adult_sealions;
}

/*******************************************************************
** Function: Zoo::baby_born()
** Description: chooses adult to give birth to baby
** Parameters: none
*******************************************************************/ 
void Zoo::baby_born(){
    int adult_tigers = get_adult_tigers(), adult_bears = get_adult_bears(),     //uses functions to calculate number of adults of each species
    adult_sealions = get_adult_sealions();

    int chosen_adult = rand() % (adult_tigers + adult_bears + adult_sealions) + 1;  //randomly chooses an adult to give birth to babies
    
    if (chosen_adult <= adult_tigers){      //checks if chosen adult is a tiger
        cout << "Congratulations! One of your tigers has given birth to three healthy tiger cubs!" << endl;
        tiger_born();
    } else if (chosen_adult <= adult_tigers + adult_bears){     //checks if chosen adult is bear
        cout << "Congratulations! One of your bears has given birth to two healthy bear cubs!" << endl;
        bear_born();
    } else {        //checks if chosen adult is sea lion
        cout << "Congratulations! One of your sea lions has given birth to a healthy sea lion pup!" << endl;
        sealion_born();
    }
}

/*******************************************************************
** Function: Zoo::get_medicine_cost()
** Description: gets cost to treat sick animal
** Parameters: chosen_animal
*******************************************************************/ 
int Zoo::get_medicine_cost(const int chosen_animal){
    int animal_index;
    
    if (chosen_animal < num_tigers){
        cout << "One of your tigers is sick." << endl;
        animal_index = chosen_animal;
        if (tigers[animal_index].get_age() < 6)     // calculates cost of medicine for baby tiger
            return tigers[animal_index].get_cost();
        return tigers[animal_index].get_cost() / 2; // calculates cost of medicine for adult/adolescent tiger

    } else if (chosen_animal < num_tigers + num_bears){
        cout << "One of your black bears is sick." << endl;
        animal_index = chosen_animal - num_tigers;
        if (blackbears[animal_index].get_age() < 6)     // calculates cost of medicine for baby bear
            return blackbears[animal_index].get_cost();
        return blackbears[animal_index].get_cost() / 2;     // calculate cost of medicine for adult/adolescent bear

    } else {
        cout << "One of your sea lions is sick." << endl;
        animal_index = chosen_animal - num_tigers - num_bears;
        if (sealions[animal_index].get_age() < 6)       // calculates cost of medicine for baby sea lion
            return sealions[animal_index].get_cost();
        return sealions[animal_index].get_cost() / 2;   // calculates cost of medicine for adult/asolescent sea lion
    }
}

/*******************************************************************
** Function: Zoo::dying_tiger()
** Description: removes dying tiger from array
** Parameters: animal_index
*******************************************************************/ 
void Zoo::dying_tiger(const int animal_index){
    Tiger* temp_tiger_location = tigers;    // stores location of old array

    tigers = new Tiger [num_tigers - 1];    // makes new array

    // copies tigers from old array before dying tiger
    int i = 0;
    while (i < animal_index){
        tigers[i] = temp_tiger_location[i];
        i++;
    }

    // copies tigers from old array after dying tiger
    for (int j = animal_index + 1; j < num_tigers; j++){
        tigers[i] = temp_tiger_location[j];
        i++;
    }

    delete [] temp_tiger_location;      // deletes old array
    num_tigers -= 1;

}

/*******************************************************************
** Function: Zoo::dying_bear()
** Description: removes dying bear from array
** Parameters: animal_index
*******************************************************************/ 
void Zoo::dying_bear(const int animal_index){
    BlackBear* temp_bear_location = blackbears;     // stores location of old array

    blackbears = new BlackBear [num_bears - 1];     // makes new array

    // copies bears from old array to before dying bear
    int i = 0;
    while (i < animal_index){
        blackbears[i] = temp_bear_location[i];
        i++;
    }

    // copies bears from old array after dying bear
    for (int j = animal_index + 1; j < num_bears; j++){
        blackbears[i] = temp_bear_location[j];
        i++;
    }

    delete [] temp_bear_location;       // deletes old array
    num_bears -= 1;
}

/*******************************************************************
** Function: Zoo::dying_sealion()
** Description: removes dying sea lion from array
** Parameters: animal_index
*******************************************************************/ 
void Zoo::dying_sealion(const int animal_index){
    SeaLion* temp_sealion_location = sealions;      // stores location of old array

    sealions = new SeaLion [num_sealions - 1];      // /makes new array

    // copies sea lions from old array to before dying sea lion
    int i = 0;
    while (i < animal_index){
        sealions[i] = temp_sealion_location[i];
        i++;
    }

    // copes sea lions from old array after dying sea lion
    for (int j = animal_index + 1; j < num_sealions; j++){
        sealions[i] = temp_sealion_location[j];
        i++;
    }

    delete [] temp_sealion_location;        // deletes old array
    num_sealions -= 1;
}

/*******************************************************************
** Function: Zoo::dying animal()
** Description: calls function to remove dying animal based on index
** of chosen animal
** Parameters: chosen_animal
*******************************************************************/ 
void Zoo::dying_animal(const int chosen_animal){
    int animal_index;
    if (chosen_animal < num_tigers){
        animal_index = chosen_animal;
        dying_tiger(animal_index);
    } else if (chosen_animal < num_tigers + num_bears){
        animal_index = chosen_animal - num_tigers;
        dying_bear(animal_index);
    } else {
        animal_index = chosen_animal - num_tigers - num_bears;
        dying_sealion(animal_index);
    }
}

/*******************************************************************
** Function: Zoo::sick_animal()
** Description: determines whether you have enough money to treat animal.
** If so, removes cost from money. If not, animal dies
** Parameters: none
*******************************************************************/ 
void Zoo::sick_animal(){
    int medicine_cost, chosen_animal = rand() % (num_tigers + num_bears + num_sealions);

    medicine_cost = get_medicine_cost(chosen_animal);
    cout << "Cost = " << medicine_cost << endl;

    if (medicine_cost > money){
        cout << "You don't have enough money to treat this animal. RIP" << endl;
        dying_animal(chosen_animal);
    } else {
        cout << "Paying $" << medicine_cost << " to heal animal..." << endl;
        money -= medicine_cost;
    }
}

/*******************************************************************
** Function: Zoo::attendance_boom()
** Description: calculates bonus for attendance boom at zoo
** Parameters: none
*******************************************************************/ 
void Zoo::attendance_boom(){
    int rand_bonus = rand() % 251 + 150;
    month_revanue_bonus = rand_bonus * num_sealions;

    cout << "There has been a boom in attendance at your zoo!" << endl;
    cout << "Each sealion gets an additional $" << rand_bonus << " resulting in $" << month_revanue_bonus << " of a bonus." << endl;

}

/*******************************************************************
** Function: Zoo::get_baby_tigers()
** Description: calls random event generator then respective event
** Parameters: none
*******************************************************************/ 
void Zoo::rand_event(){
    int event = rand_event_generator();

    if (event == 1){
        return;  //nothing happens
    } else if (event == 2){
        attendance_boom();
    } else if (event == 3){
        sick_animal();
    } else {
        baby_born();
    }

}

/*******************************************************************
** Function: Zoo::buy_tiger()
** Description: buys tiger, adds tiger to tiger array, subtracts cost 
** from money
** Parameters: none
*******************************************************************/ 
void Zoo::buy_tiger(){
    Tiger temp_tiger(48);
    Tiger* temp_tiger_location = tigers;
    num_tigers += 1;

    tigers = new Tiger [num_tigers];
    for (int i = 0; i < num_tigers - 1; i++){
        tigers[i] = temp_tiger_location[i];
    }

    delete [] temp_tiger_location;
    
    tigers[num_tigers - 1] = temp_tiger;

    money -= tigers[num_tigers - 1].get_cost(); // subtract cost of animal from money
    adult_tigers_bought += 1; // adds 1 to the total adult tigers bought
}

/*******************************************************************
** Function: Zoo::buy_bear()
** Description: buys bear, adds bear to array, pays for bear
** Parameters: none
*******************************************************************/ 
void Zoo::buy_bear(){
    BlackBear temp_bear(48);
    BlackBear* temp_bear_location = blackbears;

    num_bears += 1;

    blackbears = new BlackBear [num_bears];
    for (int i = 0; i < num_bears - 1; i++){
        blackbears[i] = temp_bear_location[i];
    }

    delete [] temp_bear_location;
    
    blackbears[num_bears - 1] = temp_bear;

    money -= blackbears[num_bears - 1].get_cost(); // subtract cost of animal from money
    adult_bears_bought += 1;    // adds 1 to the total adult bears bought
}

/*******************************************************************
** Function: Zoo::buy_sealion()
** Description: buys sea lion, adds sea lion to zoo, removes cost
** from money
** Parameters: none
*******************************************************************/ 
void Zoo::buy_sealion(){
    SeaLion temp_sealion(48);
    SeaLion* temp_sealion_location = sealions;

    num_sealions += 1;

    sealions = new SeaLion [num_sealions];
    for (int i = 0; i < num_sealions - 1; i++){
        sealions[i] = temp_sealion_location[i];
    }

    delete [] temp_sealion_location;
    
    sealions[num_sealions - 1] = temp_sealion;
    money -= sealions[num_sealions - 1].get_cost(); // subtract cost of animal from money

    adult_sealions_bought += 1;     // adds 1 to the total adult sealions bought
}

/*******************************************************************
** Function: Zoo::check_purchase()
** Description: checks whether user has already bought max amount of animal
** Parameters: animal_choice
*******************************************************************/ 
bool Zoo::check_purchase(string animal_choice){
    if (animal_choice == "1"){
        if (adult_tigers_bought == 2){
            cout << "You have already bought the maximum amount of tigers" << endl;
            return false;
        }
        return true;
    } else if (animal_choice == "2"){
        if (adult_bears_bought == 2){
            cout << "You have already bought the maximum amount of bears" << endl;
            return false;
        }
        return true;
    } else if (animal_choice == "3"){
        if (adult_sealions_bought == 2){
            cout << "You have already bought the maximum amount of sea lions" << endl;
            return false;
        }
    }
    return true;
}

/*******************************************************************
** Function: Zoo::choose animal()
** Description: gets and error handles user input to buy animal
** Parameters: none
*******************************************************************/ 
string Zoo::choose_animal(){
    string animal_choice = "";
    bool can_choose = true;

    do{
        do{
            cout << "Enter 1 to buy a tiger, 2 to buy a bear, 3 to buy a sea lion, or 4 to change your mind and not purchase an animal. " << endl;
            cin >> animal_choice;

        } while (animal_choice != "1" && animal_choice != "2" && animal_choice != "3" && animal_choice != "4");

        can_choose = check_purchase(animal_choice);
    } while (can_choose == false);

    return animal_choice;
}

/*******************************************************************
** Function: Zoo::buy_animal()
** Description: gets and error handles whether user would like to buy
** animal, gets user's choice of animal to buy, calls respective function
** Parameters: none
*******************************************************************/ 
void Zoo::buy_animal(){
    string buy_animal, animal_choice;
    do{
    cout << "Would you like to buy an animal? Enter 0 for no and 1 for yes" << endl;
    cin >> buy_animal;
    } while (buy_animal != "0" && buy_animal != "1");
    
    if (buy_animal == "1"){
        animal_choice = choose_animal();
        if (animal_choice == "1"){
            buy_tiger();
        } else if (animal_choice == "2"){
            buy_bear();
        } else if (animal_choice == "3"){
            buy_sealion();
        }

        cout << "Money after puchase: $" << money << endl;
    }
}

/*******************************************************************
** Function: Zoo::~Zoo()
** Description: deconstructor for Zoo
** Parameters: none
*******************************************************************/ 
Zoo::~Zoo(){
    delete [] tigers;       //deletes dynamic array holding tigers
    tigers = NULL;          //sets tiger pointer to null
    delete [] blackbears;   //deletes dynamic array holding bears
    blackbears = NULL;      //sets bear pointer to null
    delete [] sealions;     //deletes dynamic array holding sealions
    sealions = NULL;        //sets sealion pointer to null
}