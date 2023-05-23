#include <iostream>
#include "./pet.h"
#include "./dog.h"

using namespace std;

int main(){
	string temp;
	int temp_int, num_dogs;
	Pet pet1;
	Dog* dogs;

	cout << "Enter pet's name: ";
	cin >> temp;
	pet1.set_name(temp);

	cout << "Enter pet's weight: ";
	cin >> temp_int;
	pet1.set_weight(temp_int);

	cout << "Lifespan: " << pet1.get_lifespan() << endl;

	cout << "What size array of dogs would you like to make?";
	cin >> num_dogs;

	dogs = new Dog [num_dogs];

	for (int i = 0; i < num_dogs; i++){
		cout << "Enter dog " << i + 1 << " name: ";
		cin >> temp;
		dogs[i].set_name(temp);

		cout << "Enter dog's weight: ";
		cin >> temp_int;
		dogs[i].set_weight(temp_int);
	}

	for (int i = 0; i < num_dogs; i++){
		cout << "Dog " << i + 1 << "'s lifespan is " << dogs[i].get_lifespan() << endl;
	}

	delete [] dogs;

	
	return 0;
}
