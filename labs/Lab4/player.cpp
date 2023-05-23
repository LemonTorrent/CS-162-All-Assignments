/******************************************************************************
 ** Program: player.cpp
 ** Author: Nicole Yarbrough
 ** Date: 04/24/2020
 ** Description: This file contains the definitions for the functions from player.h
 *****************************************************************************/ 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "./card.h"
#include "./deck.h"
#include "./hand.h"
#include "player.h"

using namespace std;

Player::Player(){
    //name = "Player 1";
    
    return;
}


/*******************************************************************
** Function: Player()
** Description: Initializes Player with name
** Parameters: Player_name
*******************************************************************/ 
Player::Player(string player_name){
    name = player_name;
    
    return;
}

/*******************************************************************
** Function: computer_turn()
** Description: Performs the computer's actions during its turn.
** Parameters: discard_pile, deck
*******************************************************************/ 
void Player::computer_turn(Card& discard_pile, Deck& deck){
    int index = hand.find_card(discard_pile);
    Card drawn_card;

    while (index == -1 && deck.get_num_cards() != 0){
        cout << "The computer is drawing a card..." << endl;
        drawn_card = deck.draw_card();
        hand.add_card(drawn_card);
        index = hand.find_card(discard_pile);
    }

    if (index >= 0){
        hand.play_card(index, discard_pile);
        cout << "The computer has played ";
        discard_pile.print_card();
        cout << endl << endl;
        if (discard_pile.get_rank() == 8)
            wild_8(discard_pile);
    }
}

/*******************************************************************
** Function: print_computer_hand()
** Description: prints hand
** Parameters: hand
*******************************************************************/ 
void print_computer_hand(Hand& hand){
    cout << "Computer's hand: " << endl;
    hand.print_hand();
    cout << endl;
}

/*******************************************************************
** Function: wild_8()
** Description: changes discard pile card's suit when computer plays an 8
** Parameters: discard_pile
*******************************************************************/ 
void Player::wild_8(Card& discard_pile){
    char suits [4] = {'d','c','h','s'};
    int index;
    srand(time(NULL));

    index = rand() % 4;

    discard_pile.set_suit(suits[index]);

    cout << "The computer has chosen to play a wild card. The suit is now " << suits[index] << endl;
}


/*******************************************************************
** Function: is_int()
** Description: This is the function where the string is checked to
** be an integer.
** Parameters: num
*******************************************************************/
bool is_int(string num) {

	for (int i = 0; i < num.length(); i++) {
		if (num[i] < '0' or num[i] > '9')
			return false;
	}
	return true;

}

/*******************************************************************
** Function: get_int()
** Description: This is the function where strings of number
** characters are turned into an integer.
** Parameters: prompt
*******************************************************************/ 
int get_int(string prompt) {
  int output_int = 0;

  if (prompt[0] == '-') {
    for (int i = 1; i < prompt.length(); i++){
      output_int += ((prompt[prompt.length()-i] - 48) * pow(10, i-1));
    }

    output_int *= -1;
  } else {    
    for (int i = 0; i < prompt.length(); i++){
    output_int += ((prompt[prompt.length()-1-i] - 48) * pow(10, i));
    }
  }
		
	return output_int;
}

/*******************************************************************
** Function: player_input()
** Description: Prints hand, gets player's choice of card to play
** Parameters: discard_pile, deck
*******************************************************************/ 
int Player::player_input(Card discard_pile, Deck& deck){
    string temp;
    int choice = -1;
    bool is_num;

    cout << "This is your hand: " << endl;
    hand.print_hand();
    cout << endl << "Enter the index of the card you would like to play: ";
    get_player_input(temp, choice, is_num);

    player_input_error(temp, choice, is_num, discard_pile, deck, hand);
    
    cout << "You are playing ";
    hand.current_hand[choice].print_card();
    cout << endl;

    return choice;
}

/*******************************************************************
** Function: player_input()
** Description: Gets player's input
** Parameters: temp, choice, is_num
*******************************************************************/ 
void get_player_input(string& temp, int& choice, bool& is_num){
        cin >> temp;
        is_num = is_int(temp);
        if (is_num == true)
            choice = get_int(temp);
}

/*******************************************************************
** Function: player_input_error()
** Description: error handles player input
** Parameters: temp, choice, is_num, discard_pile, deck, hand
*******************************************************************/ 
void player_input_error(string& temp, int& choice, bool& is_num, Card discard_pile, Deck& deck, Hand& hand){
    while ((is_num == false) || (choice < 0 || choice >= hand.get_num_cards()) || 
        (hand.current_hand[choice].get_suit() != discard_pile.get_suit() && 
        hand.current_hand[choice].get_rank() != discard_pile.get_rank() && hand.current_hand[choice].get_rank() != 8) ){

        cout << "Enter a valid choice. Enter the index of the card you would like to play: ";
        get_player_input(temp, choice, is_num);
    }
}

/*******************************************************************
** Function: game_turn()
** Description: Checks if there is a playable card in hand, if not, 
** draws card. player_input() called, card is played.
** Parameters: discard_pile, deck
*******************************************************************/ 
void Player::game_turn(Card& discard_pile, Deck& deck){
    int index = hand.find_card(discard_pile);
    Card drawn_card;

    while (index == -1 && deck.get_num_cards() != 0){
        hand.print_hand();
        cout << "You cannot play anything in your hand. Drawing card..." << endl;
        drawn_card = deck.draw_card();
        hand.add_card(drawn_card);
        index = hand.find_card(discard_pile);
    }

    index = player_input(discard_pile, deck);

    if (index >= 0){
        hand.play_card(index, discard_pile);
        if (discard_pile.get_rank() == 8)
            change_suit(discard_pile);
    }
}

/*******************************************************************
** Function: change_suit()
** Description: gets user input to change suit when user plays an 8
** Parameters: discard_pile
*******************************************************************/ 
void Player::change_suit(Card& discard_pile){
    bool is_num;
    int choice;
    string temp;

    cout << "You have played a random card. Enter: 1-diamond, 2-club, 3-heart, 4-spade ";
    cin >> temp;
    
    is_num = is_int(temp);
    if (is_num == true){
        choice = get_int(temp);
    }

    while (is_num == false || choice < 1 || choice > 4){
        cout << "Please enter a valid choice. Enter: 1-diamond, 2-club, 3-heart, 4-spade";
        cin >> temp;
        is_num = is_int(temp);
        if (is_num == true)
            choice = get_int(temp);
    }
    wild_suit(discard_pile, choice);
}

/*******************************************************************
** Function: Hand()
** Description: changes suit of discard pile based on user choice
** Parameters: discard_pile, choice
*******************************************************************/ 
void Player::wild_suit(Card& discard_pile, int choice){
    if (choice == 1){
        discard_pile.set_suit('d');
    } else if (choice == 2){
        discard_pile.set_suit('c');
    } else if (choice == 3){
        discard_pile.set_suit('h');
    } else {
        discard_pile.set_suit('s');
    }
}

/*******************************************************************
** Function: set_name()
** Description: sets player name
** Parameters: str
*******************************************************************/ 
void Player::set_name(const string str){
    name = str;
}

/*******************************************************************
** Function: get_name()
** Description: returns player name
** Parameters: none
*******************************************************************/ 
string Player::get_name(){
    return name;
}