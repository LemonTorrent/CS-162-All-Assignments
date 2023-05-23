/******************************************************************************
 ** Program: hand.cpp
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This file contains the definition of functions from hand.h
 *****************************************************************************/ 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "./card.h"
#include "./hand.h"

using namespace std;

/*******************************************************************
** Function: Hand()
** Description: Creates dynamic array to store cards
** Parameters: none
*******************************************************************/ 
Hand::Hand(){
    cout << "Creating hand" << endl;
    card_capacity = 52;
    current_hand = new Card [card_capacity];

    return;
}

/*******************************************************************
** Function: set_num_cards()
** Description: sets number of cards in hand at the moment
** Parameters: num
*******************************************************************/ 
void Hand::set_num_cards(const int num){
    cout << "setting number of cards" << endl;
    num_cards = num;
}

/*******************************************************************
** Function: ~Hand()
** Description: deletes dynamic array
** Parameters: none
*******************************************************************/ 
Hand::~Hand(){
    cout << "Deleting hand" << endl;
    delete [] current_hand;
}

/*******************************************************************
** Function: add_card()
** Description: adds card to hand
** Parameters: new_card
*******************************************************************/ 
void Hand::add_card(const Card new_card){
    
    current_hand[num_cards] = new_card;

    num_cards += 1;
}

/*******************************************************************
** Function: get_num_cards()
** Description: returns number of cards in hand at that moment
** Parameters: none
*******************************************************************/ 
int Hand::get_num_cards(){
    return num_cards;
}

/*******************************************************************
** Function: get_card_index()
** Description: gets index of card, used to check if there is a card that matches
** Parameters: card
*******************************************************************/ 
int Hand::get_card_index(Card card){

    for (int i = 0; i < num_cards; i++){
        cout << current_hand[i].get_suit() << " " << card.get_suit() << endl;
        cout << current_hand[i].get_rank() << " " << card.get_rank() << endl;
        if (current_hand[i].get_suit() == card.get_suit() || current_hand[i].get_rank() == card.get_rank() || current_hand[i].get_rank() == 8){
            return i;
        }
    }

    return -1;
}

/*******************************************************************
** Function: play_card()
** Description: Takes card from hand and puts in discard pile
** Parameters: none
*******************************************************************/ 
void Hand::play_card(int index, Card& discard_pile){
    print_hand();

    discard_pile = current_hand[index];

    for (int i = index; i < num_cards - 1; i++){
        current_hand[i] = current_hand[i+1];
    }

    num_cards -= 1;

    print_hand();
}

/*******************************************************************
** Function: print_hand()
** Description: prints hand, self explanatory
** Parameters: none
*******************************************************************/ 
void Hand::print_hand(){
    for (int i = 0; i < num_cards; i++){
        current_hand[i].print_card();
        if (i > 0 && (i % 7) == 0 && i != num_cards - 1){
            cout << endl;
        }
    }

    cout << endl << endl;
}

/*******************************************************************
** Function: find_card()
** Description: finds a card in hand that can be played, if not, returns -1
** Parameters: discard_pile
*******************************************************************/ 
int Hand::find_card(Card discard_pile){

    for (int i = 0; i < num_cards; i++){

        if (current_hand[i].get_suit() == discard_pile.get_suit()){
            return i;
        }
        if (current_hand[i].get_rank() == discard_pile.get_rank() || current_hand[i].get_rank() == 8){
            return i;
        }


    }
    return -1;
}