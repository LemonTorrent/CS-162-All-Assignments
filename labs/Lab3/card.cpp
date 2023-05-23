#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./card.h"

using namespace std;

void Card::set_suit(char card_suit){
    suit = card_suit;
}

char Card::get_suit(){
    return suit;
}

void Card::set_rank(int card_rank){
    rank = card_rank;
}

int Card::get_rank(){
    return rank;
}

// The O's

Card::Card(){
    suit = 'c';
    rank = '2';

    return;
}

Card::Card(char s, int r){
    suit = s;
    rank = r;

    return;
}

Card::Card(const Card& old_card){
    suit = old_card.suit;
    rank = old_card.rank;

    return;
}

Card& Card::operator=(const Card& old_card){
    suit = old_card.suit;
    rank = old_card.rank;

    return *this;
}