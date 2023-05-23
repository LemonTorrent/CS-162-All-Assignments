/******************************************************************************
 ** Program: player.h
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This file contains class Plaer as well as declarations for get_int()
 ** is_int(), and print_computer_hand()
 *****************************************************************************/ 

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "./card.h"
#include "./deck.h"
#include "./hand.h"

//#include "./game.h"

using namespace std;

class Player{
private:
    //Hand hand;
    string name;

public:
    Hand hand;

    Player();
    Player(string);
    void game_turn(Card&, Deck&);
    void computer_turn(Card&, Deck&);
    void wild_8(Card&);
    void change_suit(Card&);
    void wild_suit(Card&, int);


    void set_name(const string);
    string get_name();

    int player_input(Card, Deck&);


};

int get_int(string);
bool is_int(string);
void print_computer_hand(Hand&);
void get_player_input(string&, int&, bool&);
void player_input_error(string&, int&, bool&, Card, Deck&, Hand&);


#endif