#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct mult_div_values {
	int mult;
	float div;
};

bool is_valid_input(char* v){
	for (int j = 0; j < strlen(v); j++){
		if (v[j] < '0' || v[j] > '9')
			return false;
	}

	return true;
}

void get_w(int& w) {
	cout << "Please enter the width of the table: ";
	cin >> w;
}

void check_w(char** v, int& w) {
	if(is_valid_input(v[1]) == false) {
		cout << "Bad width input." << endl;
		get_w(w);
	} else {
		w = atoi(v[1]);
	}
}

void get_h(int& h) {
	cout << "Please enter the height of the table: ";
	cin >> h;
}

void check_h(char** v, int& h) {
	if (is_valid_input(v[2]) == false) {
		cout << "Bad height input. " << endl;
		get_h(h);
	} else {
		h = atoi(v[2]);
	}
}

void get_input(int c, char** v, int& w, int& h) {
	if (c < 3){
		cout << "Error - not enough arguments" << endl;
		get_w(w);
		get_h(h);
	} else {
		check_w(v, w);
		check_h(v, h);
	}
}



void array_mult(mult_div_values** array, int w, int h){
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++){
			array[i][j].mult = (i+1) * (j+1);
		}
	}
}

void array_div(mult_div_values** array, int w, int h){
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			array[i][j].div = (float(i+1)) / (float(j+1));
			cout << "value: " << array[i][j].div << endl;

		}
	}
}

mult_div_values** create_2d(int w, int h){
	mult_div_values** array = new mult_div_values* [w];
	for (int i = 0; i < w; i++){
		array[i] = new mult_div_values[h];
	}
	array_mult(array, w, h);
	array_div(array, w, h);

	return array;
}

void print_mult(mult_div_values** array, int w, int h){
	for (int i = 0; i < w; i++){
		for (int j = 0; j < h; j++){
			cout << array[i][j].mult << "  ";
		}
		cout << endl;
	}
}

void print_div(mult_div_values** array, int w, int h){
	for (int i = 0; i < w; i++){
		for (int j = 0; j < h; j++){
			cout << array[i][j].div << "  ";
		}
		cout << endl;
	}
}

void delete_array(mult_div_values** array, int w, int h){
	for (int i = 0; i < w; i++){
		delete [] array[i];
	}
	delete [] array;
}

int cont_program(){
	string input;
	do{
		cout << "Would you like to run this program again? 1-yes, 0-no ";
		cin >> input;
	} while (input != "1" && input != "0");

	if (input == "1"){
		return 1;
	} else {
		return 0;
	}
}

int start(int w, int h){
	mult_div_values** array = create_2d(w, h);
	print_mult(array, w, h);
	cout << endl;
	print_div(array, w, h);
	delete_array(array, w, h);
	return cont_program();
}

void new_input(int &w, int &h){
		get_w(w);
		get_h(h);
}

int main(int argc, char** argv) {
	int w, h, cont_program = 0;

	get_input(argc, argv, w, h);

	do {
		if (cont_program == 1)
			new_input(w, h);
		cont_program = start(w, h);
	} while (cont_program == 1);
	
	return 0;

}

