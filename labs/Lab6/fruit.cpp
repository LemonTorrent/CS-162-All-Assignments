#include "fruit.h"

using namespace std;

Fruit::Fruit() {
    this->name = "";
    this->weight = 0;
    return;
}


bool Fruit::operator> (const Fruit &f) {
    if (this->weight > f.weight) {
        return true;
    }
    return false;
}


bool Fruit::operator< (const Fruit &f) {
    if (this->weight < f.weight) {
        return true;
    }
    return false;
}


string Fruit::get_name() {
    return this->name;
}


void Fruit::set_name(string s) {
    this->name = s;
    return;
}


unsigned short Fruit::get_weight() {
    return this->weight;
}


void Fruit::set_weight(unsigned short w) {
    this->weight = w;
    return;
}
