/******************************************************************************
 ** Program: game.h
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This file contains class Game as well as the declaration of print_discard()
 *****************************************************************************/ 

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "./card.h"
#include "./deck.h"
#include "./hand.h"
#include "./player.h"

class Game{
private:
    Deck deck_of_cards;
    Player players[2];
    Card discard_card;

public:
    Game();
    void play();
    bool is_winner();
    bool is_draw();
};

void print_discard(Card);

#endif