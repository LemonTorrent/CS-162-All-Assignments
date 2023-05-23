#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./card.h"

#ifndef DECK_H
#define DECK_H

using namespace std;
//#include <iostream>

class Deck{
private:
    Card card_deck[52];
    //Card* card_deck

public:
    void create_deck(); //card*);
    void swap(Card&, Card&);
    void shuffle_deck();    //card*);
    void print_deck();  //card*);

};

#endif

