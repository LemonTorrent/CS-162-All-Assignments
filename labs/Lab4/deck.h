/******************************************************************************
 ** Program: deck.h
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This program contains class Deck
 *****************************************************************************/ 

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "./card.h"

class Deck{
private:
    Card* card_deck;
    int num_cards;

public:
    Deck();
    ~Deck();


    void create_deck();
    void swap(Card&, Card&);
    void shuffle_deck();
    Card draw_card();
    Card view_card(int);
    void print_deck();
    int get_num_cards();


};

#endif