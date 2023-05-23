struct mult_div_values {
	int mult;
	float div;
};

bool is_valid_input(char*);
void get_w(int&);
void check_w(char**, int&);
void get_h(int&);
void check_h(char**, int&);
void get_input(int, char**, int&, int&);
void array_mult(mult_div_values**, int, int);
void array_div(mult_div_values**, int, int);
mult_div_values** create_2d(int, int);
void print_mult(mult_div_values**, int, int);
void print_div(mult_div_values**, int, int);
void delete_array(mult_div_values**, int, int);
int cont_program();
int start(int, int);
void new_input(int&, int&);