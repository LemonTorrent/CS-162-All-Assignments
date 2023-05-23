#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "./mult_div.h"
//include "./lab1part2.cpp"

using namespace std;

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