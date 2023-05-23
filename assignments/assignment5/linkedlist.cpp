/******************************************************
** Program: linked_list.cpp
** Author: Nicole Yarbrough
** Date: 06/07/2020
** Description: contains definitions for the functions in
** linkedlist.h
** Input: none
** Output: none
******************************************************/

#include <iostream>
#include "linkedlist.h"
#include "node.h"

using namespace std;

/*******************************************************************
** Function: Linked_List()
** Description: Linked List constructor
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
Linked_List::Linked_List(){
    length = 0;     // note: there is no set_length(unsigned int) (the reasoning should be intuitive)
    head = nullptr;
}

/*******************************************************************
** Function: get_length()
** Description: returns length
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int Linked_List::get_length(){
    return length;
}

/*******************************************************************
** Function: set_length()
** Description: sets length variable of Linked List
** Parameters: int l
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
void Linked_List::set_length(int l){
    length = l;
}

/*******************************************************************
** Function: print()
** Description: output a list of all integers contained within the list
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
void Linked_List::print(){
    cout << "Your Linked List's Contents: " << endl;
    Node* printing_node = head;
    //cout << "length = " << length << endl;
    for (int i = 0; i < length - 1; i++){
        cout << printing_node->value << " ";
        printing_node = printing_node->next;
    }

    cout << printing_node->value << endl << endl;
    //cout << "Yeet 5 = " << head->value;
    //cout << endl << endl;
} 


/*******************************************************************
** Function: clear()
** Description: delete the entire list, remove nodes and reset length to 0
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
void Linked_List::clear(){
    Node* temp_node = nullptr;
    for (int i = length - 1; i > 0; i--){
        temp_node = head;
        for (int j = 0; j < length - 1; j++){

            temp_node = temp_node->next;
        }

        delete temp_node->next;
        temp_node->next = nullptr;

        length -= 1;
    }
    delete head->next;
    delete head;
    head = nullptr;
    
    length = 0;    // In other words, length now equals 0
    head = nullptr;
}

/*******************************************************************
** Function: push_front()
** Description: insert a new value at the front of the list, returns 
** new length of the list
** Parameters: int n
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
unsigned int Linked_List::push_front(int n){
    Node* temp = head;
    head = new Node;
    head->value = n;
    head->next = temp;
    
    length += 1;
    return length;
}

/*******************************************************************
** Function: push_back()
** Description: insert a new value at the back of the list, returns 
** new length of the list
** Parameters: int n
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
unsigned int Linked_List::push_back(int n){
    Node* temp = head;

    if (length == 0){
        push_front(n);
        return length;
    }

    if (length > 0){
        for (int i = 0; i < length - 1; i++){
            temp = temp->next;
        }
    }

    temp->next = new Node;
    temp->next->value = n;
    
    length += 1;
    return length;
} 

/*******************************************************************
** Function: insert()
** Description: insert a new value in the list at the specified index, 
** returns the new length of the list
** Parameters: int val, unsigned int index
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
unsigned int Linked_List::insert(int val, unsigned int index){
    if (index < 0 || index >= length){
        cout << "Invalid index for insertion" << endl;
        return length;
    }
    Node *new_node = new Node, *temp = head;
    for (int i = 0; i < index - 1; i++){
        temp = temp->next;
    }
    
    new_node->next = temp->next;
    new_node->value = val;

    temp->next = new_node;

    length += 1;
    return length;
} 

/*******************************************************************
** Function: get_node()
** Description: returns the node at the specified index
** Parameters: int index
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
Node* Linked_List::get_node(int index){
    Node* node = head;

    if (index > 0){
        for (int i = 1; i < index; i++){
            node = node->next;
        }
    }

    return node;
}

/*******************************************************************
** Function: sort_descending()
** Description: sorts elements in descending order. I wasn't able to finish it,
** so I am printing to the screen as a placeholder.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
void Linked_List::sort_descending(){
    cout << "sort descending" << endl;
    /*Linked_List new_list;
    int index = 0;
    
    //int small_elements [length];
    int small_int;
    bool start = true;

    //new_list.head = find_min(small_int, start);
    //new_list.head
    Node* temp = head;
    Node* node2 = find_min(index);
    cout << "after find_min" << endl;
    for (int i = 0; i < length; i++){
        if (temp->value > temp->next->value){
            Node* temp2 = temp;
            temp = temp->next;
            temp->next = temp2;
        }
    }

    new_list.print();*/
} 

/*******************************************************************
** Function: sort_ascending()
** Description: sorts elements in ascending order. I wasn't able to finish it,
** so I am printing to the screen as a placeholder.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
void Linked_List::sort_ascending(){
    cout << "sort ascending" << endl;
}

/*******************************************************************
** Function: num_prime()
** Description: counts the number of prime elements in list
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int Linked_List::num_prime(){
    bool is_prime;
    int prime_elements = 0;

    Node* temp = head;
    for (int i = 0; i < length; i++){
        is_prime = true;
        for (int j = 2; j < temp->value; j++){
            if (temp->value % j == 0)
                is_prime = false;
        }
        if (is_prime == true)
            prime_elements += 1;    
        if (i < length - 1)
            temp = temp->next;
    }
    return prime_elements;
}

/*******************************************************************
** Function: ~Linked_List()
** Description: destructor for linked list, calls clear()
** Parameters: int val, unsigned int index
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
Linked_List::~Linked_List(){
    cout << "clearing... " << endl;
    clear();
}