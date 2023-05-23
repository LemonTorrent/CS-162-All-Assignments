/******************************************************************************
 ** Program: deck.cpp
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This file contains the definition for functions defined in deck.h
 *****************************************************************************/ 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "./card.h"
#include "./deck.h"

/*******************************************************************
** Function: Deck()
** Description: creates dynamic card_deck, sets number of cards
** Parameters: none
*******************************************************************/ 
Deck::Deck(){
    num_cards = 52;

    card_deck = new Card [52];
    create_deck();
}

/*******************************************************************
** Function: create_deck()
** Description: sets suit and rank of all cards in deck
** Parameters: none
*******************************************************************/ 
void Deck::create_deck(){
    char suits [4] = {'d','c','h','s'};// {"diamond", "club", "heart", "spade"};

    int index;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 13; j++){
            index = (i*13) + j;
            card_deck[index].set_suit(suits[i]);
            card_deck[index].set_rank(j+1);
        }
    }
    //cout << "num_cards" << num_cards << endl;
}

/*******************************************************************
** Function: swap()
** Description: swaps cards
** Parameters: card_1, card_2
*******************************************************************/ 
void Deck::swap(Card& card_1, Card& card_2){
    Card temp = card_1;
    card_1 = card_2;
    card_2 = temp;
}

/*******************************************************************
** Function: shuffle_deck()
** Description: shuffles deck
** Parameters: none
*******************************************************************/ 
void Deck::shuffle_deck(){
    srand (time(NULL));

    for (int i = 0; i < 52; i++){
        int switch_num = rand() % 52;
        swap(card_deck[i], card_deck[switch_num]);
    }
    //cout << "num cards = " << num_cards << endl;
}

/*******************************************************************
** Function: draw_card()
** Description: draws card from deck
** Parameters: none
*******************************************************************/ 
Card Deck::draw_card(){
    Card drawn_card;
    int index = num_cards-1;
    
    drawn_card = card_deck[index];
    num_cards -= 1;

    return drawn_card;
}

/*******************************************************************
** Function: print_deck()
** Description: prints all the cards in the deck
** Parameters: none
*******************************************************************/ 
void Deck::print_deck(){
    for (int i = 0; i < 52; i++){
        cout << card_deck[i].get_rank()
            << card_deck[i].get_suit() << endl;
    }
}

/*******************************************************************
** Function: ~Deck()
** Description: deconstructor for deck
** Parameters: none
*******************************************************************/ 
Deck::~Deck(){
    delete [] card_deck;
}

/*******************************************************************
** Function: get_num_cards()
** Description: returns number of cards
** Parameters: none
*******************************************************************/ 
int Deck::get_num_cards(){
    //cout << "num_cards = " << num_cards << endl;
    return num_cards;
}