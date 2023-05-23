/******************************************************************************
 ** Program: card.cpp
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This program contains the definition of functions for class Card
 *****************************************************************************/ 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "./card.h"

using namespace std;

/*******************************************************************
** Function: set_suit()
** Description: sets variable suit
** Parameters: card_suit
*******************************************************************/ 
void Card::set_suit(char card_suit){
    suit = card_suit;
}

/*******************************************************************
** Function: get_suit()
** Description: returns variable suit
** Parameters: none
*******************************************************************/ 
char Card::get_suit(){
    return suit;
}

/*******************************************************************
** Function: set_rank()
** Description: sets variable rank
** Parameters: card_rank
*******************************************************************/ 
void Card::set_rank(int card_rank){
    rank = card_rank;
}

/*******************************************************************
** Function: get_rank()
** Description: gets variable rank
** Parameters: None
*******************************************************************/ 
int Card::get_rank(){
    return rank;
}

// The O's

/*******************************************************************
** Function: Card()
** Description: sets default card suit and rank
** Parameters: none
*******************************************************************/ 
Card::Card(){
    suit = 'c';
    rank = '2';

    return;
}

/*******************************************************************
** Function: Card()
** Description: sets suit and rank based off parameters
** Parameters: s, r
*******************************************************************/ 
Card::Card(char s, int r){
    suit = s;
    rank = r;

    return;
}

/*******************************************************************
** Function: Card()
** Description: copies card properties to new card
** Parameters: old_card
*******************************************************************/ 
Card::Card(const Card& old_card){
    suit = old_card.suit;
    rank = old_card.rank;

    return;
}

/*******************************************************************
** Function: Card::operator=()
** Description: copies card properties to new card
** Parameters: old_card
*******************************************************************/ 
Card& Card::operator=(const Card& old_card){
    suit = old_card.suit;
    rank = old_card.rank;

    return *this;
}

/*******************************************************************
** Function: print_card()
** Description: prints card suit and rank
** Parameters: None
*******************************************************************/ 
void Card::print_card(){
    cout << rank << suit << " ";
}