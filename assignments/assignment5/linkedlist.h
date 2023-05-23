/******************************************************
** Program: linked_list.h
** Author: Nicole Yarbrough
** Date: 06/07/2020
** Description: contains definition of Linked List class,
** including member variables and functions
** Input: none
** Output: none
******************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h"

using namespace std;

class Linked_List{
private:
   unsigned int length; // the number of nodes contained in the list

public:
   Node* head; // a pointer to the first node in the list

   Linked_List();
   ~Linked_List();
   int get_length();
   void set_length(int);
   // note: there is no set_length(unsigned int) (the reasoning should be intuitive)
   void print(); // output a list of all integers contained within the list
   void clear(); // delete the entire list (remove all nodes and reset length to 0)
   unsigned int push_front(int); // insert a new value at the front of the list (returns the new length of the list)
   unsigned int push_back(int); // insert a new value at the back of the list (returns the new length of the list)
   unsigned int insert(int val, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)
   void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
   int min_index(int, int);
   void recursive_ascending(int, int);
   void swap(int, int);
   Node* get_node(int);
   Linked_List recursive_merge(Linked_List, int, int, int);
   // Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
   void sort_descending(); // sort the nodes in descending order
   // you can add extra member variables or functions as desired
   int num_prime();
   Node* find_min(int&);    //int&, bool&);

};

#endif