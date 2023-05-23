/******************************************************************************
 ** Program: card.h
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This file contains class Card
 *****************************************************************************/ 

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>


using namespace std;

class Card{
private:
    char suit;
    int rank;

public:
    Card();
    Card(char, int);
    Card(const Card&);
    Card& operator=(const Card& old_card);

    void set_suit(char);
    char get_suit();
    void set_rank(int);
    int get_rank();
    void print_card();
};

#endif