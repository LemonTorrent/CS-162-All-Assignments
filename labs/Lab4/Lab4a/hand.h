/******************************************************************************
 ** Program: hand.h
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This file contains class Hand
 *****************************************************************************/ 


#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "./card.h"

class Hand{
private:
    //int card_capacity, num_cards;

public:
    Card* current_hand;
    int card_capacity, num_cards;


    Hand();
    ~Hand();
    void add_card(Card);
    void set_num_cards(int);
    int find_card(Card);
    void play_card(int, Card&);
    int get_num_cards();
    void print_hand();
    int get_card_index(Card);

};

#endif