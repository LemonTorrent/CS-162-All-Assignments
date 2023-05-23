#ifndef PET_H
#define PET_H

#include <iostream>

using namespace std;

class Pet {
protected:
	string name;
	int weight;
public:
	Pet();
	void set_name(string);
	void set_weight(int);

	string get_lifespan();
	string get_name();
	int get_weight();
};

#endif
