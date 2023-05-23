#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./deck.h"


void Deck::create_deck(){   //card* card_deck){
    char suits [4] = {'d','c','h','s'};//"diamond", "club", "heart", "spade"};
    //string ranks [13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king"};
    int index;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 13; j++){
            index = (i*13) + j;
            card_deck[index].set_suit(suits[i]);
            //card_deck[index].set_suit('d');
            //card_deck[index].suite = suite[i];
            card_deck[index].set_rank(j+1);      //ranks[j]);
            //card_deck[index].set_rank(1);
        }
    }
}

void Deck::swap(Card& card_1, Card& card_2){
    Card temp = card_1;
    card_1 = card_2;
    card_2 = temp;
}

void Deck::shuffle_deck(){  //card* card_deck){
    srand (time(NULL));

    for (int i = 0; i < 52; i++){
        int switch_num = rand() % 52;
        swap(card_deck[i], card_deck[switch_num]);
    }
}

void Deck::print_deck(){    //card* card_deck){
    for (int i = 0; i < 52; i++){
        cout << card_deck[i].get_rank()
            << card_deck[i].get_suit() << endl;
    }
}

