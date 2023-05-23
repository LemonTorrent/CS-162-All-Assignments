#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./card.h"
#include "./deck.h"

using namespace std;

int main(){
    Deck card_deck;
    card_deck.create_deck();
    card_deck.print_deck();
    cout << endl;
    cout << endl;
    card_deck.shuffle_deck();
    card_deck.print_deck();

    return 0;
}