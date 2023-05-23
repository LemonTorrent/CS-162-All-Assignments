/******************************************************************************
 ** Program: game.cpp
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This program 
 ** Input: 
 ** Output: 
 *****************************************************************************/ 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "./card.h"
#include "./hand.h"
#include "./player.h"
#include "./deck.h"
#include "./game.h"

/*******************************************************************
** Function: Game()
** Description: Initializes Game with deck and player names
** Parameters: None
*******************************************************************/
Game::Game(){
    Card drawn_card;    // stores card drawn when drawing for player's hands
    deck_of_cards.shuffle_deck(); // shuffles deck
    players[0].set_name("Human");   // sets players' names
    players[1].set_name("Computer");

    for (int i = 0; i < 2; i++){    // for the two players:
        for (int j = 0; j < 7; j++){    // give each 7 cards
            drawn_card = deck_of_cards.draw_card(); //draws card
            players[i].hand.add_card(drawn_card);   // adds card to their hand
        }
    }
}

/*******************************************************************
** Function: is_winner()
** Description: checks for winner
** Parameters: None
*******************************************************************/
bool Game::is_winner(){
    if (players[0].hand.get_num_cards() == 0){  //if someone gets rid of their hand, print that they have won and return true so that game ends
        cout << "Congratulations " << players[0].get_name() << " you have won!" << endl;
        return true;
    } else if (players[1].hand.get_num_cards() == 0){
        cout << "Congratulations " << players[1].get_name() << " you have won!" << endl;
        return true;
    } else {    // if false, continue playing game/check if deck is empty
        return false;
    }
}

/*******************************************************************
** Function: is_draw()
** Description: Checks for draw
** Parameters: None
*******************************************************************/
bool Game::is_draw(){
    if (deck_of_cards.get_num_cards() == 0){
        cout << "Out of cards, this game is a draw." << endl;
        return true;
    }

    return false;
}

/*******************************************************************
** Function: Game()
** Description: Game play
** Parameters: None
*******************************************************************/
void Game::play(){
    bool winner, draw;  // set variables to store the check on whether there is a winner or a draw
    discard_card = deck_of_cards.draw_card();   // draw card for discard pile

    cout << endl;

    while (winner == false && draw == false){   // while there is no winner or draw:
        print_discard(discard_card);
        players[0].game_turn(discard_card, deck_of_cards);  // player 1, the human, goes
        winner = is_winner();   // check for winner
        draw = is_draw();       // check for draw
        if (winner == false && draw == false){  // if no winner or draw:
            print_discard(discard_card);
            players[1].computer_turn(discard_card, deck_of_cards);  // computer's turn
            winner = is_winner();   // check winner and draw
            draw = is_draw();
        }
    }
}

/*******************************************************************
** Function: print_discard()
** Description: prints discard pile card
** Parameters: None
*******************************************************************/
void print_discard(Card discard_pile){
    cout << "Discard_pile: ";
    discard_pile.print_card();
    cout << endl;
}