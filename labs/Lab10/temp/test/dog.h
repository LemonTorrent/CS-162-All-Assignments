#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "./pet.h"

using namespace std;

class Dog:public Pet{
public:
	Dog();
	string get_lifespan();
};

#endif
