/******************************************************
** Program: node.h
** Author: Nicole Yarbrough
** Date: 06/07/2020
** Description: contains definition of Node class,
** Input: none
** Output: none
******************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node* next = nullptr;
};

#endif