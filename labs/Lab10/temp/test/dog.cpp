#include "dog.h"
#include "pet.h"
#include <iostream>

using namespace std;

Dog::Dog(){
	
}

string Dog::get_lifespan(){
	if (get_weight() < 100)
		return "Approximately 13 years";
	return "Approximately 7 years";
}
