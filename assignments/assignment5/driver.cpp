/******************************************************
** Program: driver.cpp
** Author: Nicole Yarbrough
** Date: 06/07/2020
** Description: contains main function as well as functions
** that get input and check integers
** Input: none
** Output: none
******************************************************/

#include <iostream>
#include "./linkedlist.h"
#include "./node.h"

using namespace std;

/*******************************************************************
** Function: is_int()
** Description: This is the function where the string is checked to
** be an integer.
** Parameters: num
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool is_int(string num) {

	for (int i = 0; i < num.length(); i++) {
		if (num[i] < '0' or num[i] > '9')
			return false;
	}
	return true;

}


/*******************************************************************
** Function: get_elements()
** Description: Gets integer inputs from user
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int get_elements(){
    bool int_input;
    string temp, temp_choice;
    do{
        int_input = true;
        cout << "Please enter number: ";
        cin >> temp;
        if (is_int(temp) == false){
            cout << "Please enter integer." << endl;
            int_input = false;
        }
    } while (int_input == false);

    return stoi(temp);
}

/*******************************************************************
** Function: get_input()
** Description: gets integers as input from user
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
/*void get_input(){
    bool good_input;
    string temp, choice;
    do {
        get_elements(list);
        cout << "get_input" << endl;
        do {
            good_input = true;
            cout << "Would you like to add another number? (y or n) ";
            cin >> choice;
            if (choice != "y" && choice != "Y" && choice != "n" && choice != "N"){
                cout << "Please enter valid input" << endl;
                good_input = false;
            }
        } while (good_input == false);
    } while(choice == "y" || choice == "Y");
    list.print();
}
*/

/*******************************************************************
** Function: again()
** Description: checks if user would like to add another integer
** to the linked list.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool again(){
    string choice;
    do{
        cout << "Would you like to add another number? (y or n) ";
        cin >> choice;
        if (choice != "y" &&  choice != "Y" && choice != "n" && choice != "N"){
            cout << "Please enter valid input." << endl;
        }
    } while (choice != "y" &&  choice != "Y" && choice != "n" && choice != "N");

    if (choice == "y" || choice == "Y")
        return true;
    return false;
}

/*******************************************************************
** Function: gets_sort_method()
** Description: gets sort method from user
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int get_sort_method(){
    string temp;
    bool good_input;

    do{
        good_input = true;
        cout << "Would you like to sort linked list in ascending or descending order? (a/d) ";
        cin >> temp;
        if (temp != "a" && temp != "A" && temp != "d" && temp != "D"){
            cout << "Please enter valid input" << endl;
            good_input = false;
        }
    } while (good_input == false);

    if (temp == "A" || temp == "a")
        return 1;
    return 2;
}

/*******************************************************************
** Function: sort_list()
** Description: calls sort method that user chose
** Parameters: list
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
void sort_list(Linked_List& list){
    int method = get_sort_method();
    if (method == 1){
        list.sort_ascending();
    } else {
        list.sort_descending();
    }
}

/*******************************************************************
** Function: function()
** Description: this is where the functionality of the program is called.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
void function(){
    Linked_List list;
    bool more_input;
    int length;

    do{
        list.push_back(get_elements());
        more_input = again();
    } while (more_input == true);

    cout << "List created" << endl;
    
    list.print();
    cout << "number of primes: " << list.num_prime() << endl;
    //list.sort_descending();
    sort_list(list);
}

/*******************************************************************
** Function: main()
** Description: calls function(), and has loop that keeps running program
** while user wants to.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int main(){
    string choice;
    bool good_choice;
    do{
        function();
        do{
            good_choice = true;
            cout << "Would you like to do this again? (y/n) ";
            cin >> choice;
            if (choice != "y" &&  choice != "Y" && choice != "n" && choice != "N"){
                cout << "Please enter a valid input." << endl;
                good_choice = false;
            }
        } while (good_choice == false);
    } while (choice == "y" || choice == "Y");


    return 0;
}