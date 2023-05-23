#include <iostream>
#include "./pet.h"

using namespace std;

Pet::Pet(){
	name = "";
	weight = 0;
}

void Pet::set_name(string n){
	name = n;
}

void Pet::set_weight(int w){
	weight = w;
}

string Pet::get_lifespan(){
	return "unknown lifespan";
}

string Pet::get_name(){
	return name;
}

int Pet::get_weight() {
	return weight;
}
