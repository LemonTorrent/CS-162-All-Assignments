/******************************************************
** Program: hogwarts.cpp
** Author: Nicole Yarbrough
** Date: 4/13/2020
** Description: Contains the definitions of functions
** listed in hogwarts.h
** Input: argc, argv
** Output: None
******************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "./hogwarts.h"

using namespace std;

/*******************************************************************
** Function: is_int()
** Description: This is the function where the string is checked to
** be an integer.
** Parameters: num
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool is_int(string num) {

	for (int i = 0; i < num.length(); i++) {
		if (num[i] < '0' or num[i] > '9')
			return false;
	}
	return true;

}

/*******************************************************************
** Function: check_input()
** Description: Checks number of inputs. If theres not enough inputs, 
** it'll ask for addresses to be inputted, then fill the array. 
** Otherwise, it'll check the existing inputs and fill the arrays.
** Parameters: f, argc, argv, wiz_db, spbk_db, num_wizard, num_spbk
** Pre-Conditions: initialization of parameters, file names through
** command prompt
** Post-Conditions: None
*******************************************************************/ 
bool check_input(ifstream& f, int argc, char** argv, wizard*& wiz_db, spellbook*& spbk_db, int& num_wizard, int& num_spbk){
    string wiz_bk_address, spell_bk_address, temp;

    if (argc != 3){
        cout << "Inadequate arguments" << endl;
        return false;
    } else {
        if (open_file(f, argv[1], "wizard database")== false) {
            return false;
        }
        get_wizards(f, wiz_db, num_wizard);
        if (open_file(f, argv[2], "spell book")== false){ //spell_bk_address, "the spellbook database");
            return false;
        }
        get_spellbooks(f, spbk_db, num_spbk);
        return true;
    }

}

/*******************************************************************
** Function: open_file()
** Description: Opens file (program already has address). Check whether 
** filename is valid. f is a pointer, so it changes f in check_input()
** Parameters: f, filename, type_db
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool open_file(ifstream& f, char* filename, string type_db) {
    f.open(filename, ios::in);
    if (f.is_open() == false){
        cout << "Error opening file." << endl;
        return false;
    }
    return true;
}

/*******************************************************************
** Function: get_wizards()
** Description: Uses open file to create and populate wizard array db,
** closes file when done.
** Parameters: f, wiz_db, num_wizard
** Pre-Conditions: opened file
** Post-Conditions: None
*******************************************************************/ 
void get_wizards(ifstream& f, wizard*& wiz_db, int& num_wizard){
    string temp;

    f >> temp;
    num_wizard = stoi(temp);

    wiz_db = new wizard [num_wizard];

    for (int i = 0; i < num_wizard; i++){
        f >> temp;
        wiz_db[i].name = temp;
        f >> temp;
        wiz_db[i].id = stoi(temp);
        f >> temp;
        wiz_db[i].password = temp;
        f >> temp;
        wiz_db[i].position_title = temp;
        f >> temp;
        wiz_db[i].beard_length = stof(temp);
    }
    f.close(); 
}

/*******************************************************************
** Function: create_spellbooks()
** Description: Creates and returns dynamic spellbook array
** Parameters: num_spbk
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
spellbook * create_spellbooks(int num_spbk){
    spellbook* spbk_db = new spellbook [num_spbk];
    return spbk_db;
}

/*******************************************************************
** Function: get_spellbook_data()
** Description: Fills spellbook array
** Parameters: spbk_db, num_spbk, f
** Pre-Conditions: spellbook array (spbk_db) must have been created
** Post-Conditions: None
*******************************************************************/ 
void get_spellbook_data(spellbook* spbk_db, int num_spbk, ifstream& f){
    string temp;
    for (int i = 0; i < num_spbk; i++){
        f >> temp;
        spbk_db[i].title = temp;
        f >> temp;
        spbk_db[i].author = temp;
        f >> temp;
        spbk_db[i].num_pages = stoi(temp);
        f >> temp;
        spbk_db[i].edition = stoi(temp);
        f >> temp;
        spbk_db[i].num_spells = stoi(temp);
        spbk_db[i].s = create_spells(spbk_db[i].num_spells);
        //get_spell_data(spbk_db, i, f);
        for (int j= 0; j < spbk_db[i].num_spells; j++){
            get_spell_data(spbk_db[i].s, j, f);
        }
        spbk_db[i].avg_success_rate = get_avg_success_rate(spbk_db[i].s, spbk_db[i].num_spells);
    }
}

/*******************************************************************
** Function: create_spells()
** Description: Creates and returns dynamic spell array
** Parameters: num_spells
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
spell* create_spells(int num_spells){
    spell* s = new spell [num_spells];
    return s;
}

/*******************************************************************
** Function: get_spell_data()
** Description: Fills spell array
** Parameters: spbk_db, i, f
** Pre-Conditions: file must be open, spellbook 
** Post-Conditions: None
*******************************************************************/ 
void get_spell_data(spell*& sp_db, int j, ifstream& f){
    // i is the index that is used in get_spellbook_data
    string temp;
    f >> temp;
    sp_db[j].name = temp;
    f >> temp;
    sp_db[j].success_rate = stof(temp);
    f >> temp;
    sp_db[j].effect = temp;
}

/*******************************************************************
** Function: get_avg_success_rate()
** Description: Calculates average success rate of spells
** Parameters: s, num_spells
** Pre-Conditions: spell array must be full
** Post-Conditions: None
*******************************************************************/ 
float get_avg_success_rate(spell* s, int num_spells){
    //spbk_db[i].avg_success_rate = sum_success / float(spbk_db[i].num_spells);
    int sum = 0, avg;

    for (int i = 0; i < num_spells; i ++){
        sum += s[i].success_rate;
    }

    avg = sum / float(num_spells);
    return avg;
}

/*******************************************************************
** Function: get_spellbooks()
** Description: Uses open file to populate spellbook array db, close
** file when done.
** Parameters: f, spbk_db, num_books
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int get_spellbooks(ifstream& f, spellbook*& spbk_db, int& num_books){
    string temp;

    f >> temp;
    num_books = stoi(temp);

    spbk_db = create_spellbooks(num_books);
    get_spellbook_data(spbk_db, num_books, f);

    f.close();
    return num_books;
}

/*******************************************************************
** Function: find_wizard()
** Description: Searches wizard database by id, checks if password is correct.
** If id is not found or password doesn't correspond, returns false. Else, 
** true. Also prints welcome when logging in, takes out whether position 
** is student.
** Parameters: wiz_db, num_wiz, id, password, is_student
** Pre-Conditions: wiz_db must be filled with wizard data from text file
** Post-Conditions: None
*******************************************************************/ 
bool find_wizard(wizard* wiz_db, int num_wiz, int id, string password, bool& is_student){ // wiz index = index of wizard if a wizard is found w/ id and password
    for (int i = 0; i < num_wiz; i++){
        if (wiz_db[i].id == id){
            if (wiz_db[i].password == password){
                cout << "Welcome " << wiz_db[i].name << "!" << endl;
                cout << "Position: " << wiz_db[i].position_title << endl;
                cout << "ID: " << wiz_db[i].id << endl;
                cout << "Beard length: " << wiz_db[i].beard_length << endl;
                if (wiz_db[i].position_title == "Student" 
                || wiz_db[i].position_title == "student"){
                    is_student = true;
                } else {
                    is_student = false;
                }
                return true;
            }
        }
    }
    cout << "Incorrect ID or password" << endl;
    return false;
}

/*******************************************************************
** Function: get_wizards()
** Description: Uses open file to populate wizard array db, closes
** file when done.
** Parameters: wiz_db, num_wiz, is_student
** Pre-Conditions: wiz_db must have been filled with data from
** wizard text file.
** Post-Conditions: None
*******************************************************************/ 
bool login(wizard* wiz_db, int num_wiz, bool& is_student){
    string password;
    int id, num_occurances = 0; // wiz index = index of wizard in database if a wizard is found w/ id and password
    bool is_found;

    do {
        get_id(id);
        cout << "Please enter your password: ";
        cin >> password;
        num_occurances += 1;
        is_found = find_wizard(wiz_db, num_wiz, id, password, is_student);
    } while (is_found == false && num_occurances < 3);
    if (num_occurances == 3 && is_found == false){
        cout << "Error: you have exceeded the amount of login attempts." << endl;
        return false;
    } else {
        return true;
    }
}

/*******************************************************************
** Function: get_id()
** Description: Gets id input from user, edits variable in previous
** function with pointer
** Parameters: id
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
void get_id(int& id){
    string str_id;
    bool id_is_int;

    cout << "Please enter your ID: ";
    cin >> str_id;
    id_is_int = is_int(str_id);
    while (is_int(str_id) == false){
        cout << "Error - ID contains characters that are not integers. ";
        cout << "Please enter your ID: ";
        cin >> str_id;
    }
    id = stoi(str_id);
}

/*******************************************************************
** Function: swap()
** Description: Swaps spellbooks with index x and y
** Parameters: sorted_spbk, xp, yp
** Pre-Conditions: sorted_spbk must have been created and filled
** with spellbook and spell data
** Post-Conditions: None
*******************************************************************/ 
void swap(spellbook*& sorted_spbk, int xp, int yp) {  
    spellbook temp = sorted_spbk[xp];  
    sorted_spbk[xp] = sorted_spbk[yp];
    sorted_spbk[yp] = temp;  
}  

/*******************************************************************
** Function: duplicate_spbk_db()
** Description: creates a duplicate of the original spellbook to sort
** Parameters: spbk_db, sorted_spbk, num_spellbooks
** Pre-Conditions: original spellbook must have all the spell data
** Post-Conditions: None
*******************************************************************/ 
void duplicate_spbk_db(spellbook* spbk_db, spellbook*& sorted_spbk, int num_spellbooks){
    sorted_spbk = new spellbook [num_spellbooks];

    for (int i = 0; i < num_spellbooks; i++){
        sorted_spbk[i] = spbk_db[i];
    }
}

/*******************************************************************
** Function: page_sort()
** Description: Sorts spellbook using bubble sort
** Parameters: sorted_spbk, spbk_db, num_spbk
** Pre-Conditions: spellbook arrays must have spellbook and spell data
** Post-Conditions: None
*******************************************************************/ 
void page_sort(spellbook*& sorted_spbk, spellbook* spbk_db, int num_spbk){
    int i, j, n = num_spbk;  

    for (i = 0; i < n-1; i++){      
        for (j = 0; j < n-i-1; j++){
            if (sorted_spbk[j].num_pages > sorted_spbk[j+1].num_pages)
                swap(sorted_spbk, j, j+1);
        }
    }
}

/*******************************************************************
** Function: find_empty_index()
** Description: find's empty location in array
** Parameters: sorted_sp, num_spelld
** Pre-Conditions: spell array must have spell data
** Post-Conditions: None
*******************************************************************/ 
int find_empty_index(spell* sorted_sp, int num_spells){
    int index = 0;

    while (index < num_spells && sorted_sp[index].effect != ""){
        index += 1;
    }

    return index;
}

/*******************************************************************
** Function: effect_spbk()
** Description: creates spell array for all of the spells, returns
** numer of spells total
** Parameters: sorted_sp, spbk_db, num_spbks
** Pre-Conditions: spellbook array must have spellbook data
** Post-Conditions: None
*******************************************************************/ 
int effect_spbk(spellbook* spbk_db, spell*& sorted_sp, int num_spbks){
    int num_spells = 0;
    
    for (int i = 0; i < num_spbks; i++){
        num_spells += spbk_db[i].num_spells;
    }

    sorted_sp = new spell [num_spells];
    return num_spells;
}

/*******************************************************************
** Function: effect_sort()
** Description: fills sorted_sp by looking through spbk_db's spells
** by effect, returns the number of spells in sorted_sp
** Parameters: spbk_db, sorted_sp, num_spbks
** Pre-Conditions: spbk_db must have spellbook data, sorted_sp must
** have been created
** Post-Conditions: None
*******************************************************************/ 
int effect_sort(spellbook* spbk_db, spell*& sorted_sp, int num_spbks){
    string effects[] = {"bubble", "memory_loss", "fire", "poison", "death"};
    int index, num_spells = effect_spbk(spbk_db, sorted_sp, num_spbks);
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < num_spbks; j++){
            for (int k = 0; k < spbk_db[j].num_spells; k++){
                if (spbk_db[j].s[k].effect == effects[i]){
                    index = find_empty_index(sorted_sp, num_spells);
                    sorted_sp[index] = spbk_db[j].s[k];
                }
            }
        }
    }
    return num_spells;
}

/*******************************************************************
** Function: asr_sort()
** Description: Sorts spellbooks byaverage success rate using bubble sort
** Parameters: sorted_spbk, spbk_db, num_spellbooks
** Pre-Conditions: sorted_spellbook must have been filled with spellbook
** data.
** Post-Conditions: None
*******************************************************************/ 
void asr_sort(spellbook* sorted_spbk, spellbook*& spbk_db, int num_spellbooks){
    int i, j, n = num_spellbooks;

    for (i = 0; i < n-1; i++){
      
        // Last i elements are already in place  
        for (j = 0; j < n-i-1; j++){
            if (sorted_spbk[j].avg_success_rate > sorted_spbk[j+1].avg_success_rate)  
                swap(sorted_spbk, j, j+1);
        }
    }
}

/*******************************************************************
** Function: catalog_sort()
** Description: gets the sorting method from user, or whether user wants
** to quit.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int catalog_sort(){
    string temp;
    int catalog_choice;
    cout << "Which sorting method would you like to use? 1- by number of pages, 2- by effect, 3- by average success rate, or 4- quit ";
    cin >> temp;
    while(temp != "1" && temp != "2" && temp != "3" && temp != "4"){
        cout << "Error - bad input. Please enter a number from 1-4 ";
        cin >> temp;
    }
    catalog_choice = stoi(temp);
    return catalog_choice;
}

/*******************************************************************
** Function: libary_catalog()
** Description: gets sort method from user, continues loop until user
** chooses to quit
** Parameters: spbk_db, num_spellbooks, is_student
** Pre-Conditions: spbk_db must have spellbook data
** Post-Conditions: None
*******************************************************************/ 
void library_catalog(spellbook* spbk_db, int num_spellbooks, bool is_student){
    int sort_method = catalog_sort(); // return info to get from spellbook

    while (sort_method != 4) {
        start_sort(spbk_db, sort_method, num_spellbooks, is_student);
        sort_method = catalog_sort();
    }
}

/*******************************************************************
** Function: start_sort()
** Description: sends user to the sorting method that they choose,
** deletes dynamc array when done
** Parameters: spbk_db, sort_method, num_spellbooks, is_student
** Pre-Conditions: spbk_db must have spellbook data, sort method
** should have user choice of sorting method
** Post-Conditions: None
*******************************************************************/ 
void start_sort(spellbook* spbk_db, int sort_method, int num_spellbooks, bool is_student){
    if (sort_method == 2){
        spell* sorted_sp;
        int num_sp = effect_sort(spbk_db, sorted_sp, num_spellbooks);
        spell_results(sorted_sp, num_sp, is_student);
        delete [] sorted_sp;
    }else{
        spellbook* sorted_spbk;
        duplicate_spbk_db(spbk_db, sorted_spbk, num_spellbooks);
        if (sort_method == 1){
            page_sort(sorted_spbk, spbk_db, num_spellbooks);
        } else {
            asr_sort(sorted_spbk, spbk_db, num_spellbooks);
        }
        spbk_results(sorted_spbk, sort_method, num_spellbooks, is_student);
        delete [] sorted_spbk;
    }
}

/*****************************************************************
** Function: spbk_results()
** Description: Asks user for type of output, calls functions based
** on user's choice
** Parameters: sorted_spbk, sort_method, num_spellbooks, is_student
** Pre-Conditions: must know if user is student, sorted_spbk must
** contain spellbook data
** Post-Conditions: None
*****************************************************************/
void spbk_results(spellbook* sorted_spbk, int sort_method, int num_spellbooks, bool is_student){
    string output_choice;

    do {
        cout << "Enter 1 to print results to the screen or 2 to save results in a text file: ";
        cin >> output_choice;
    } while (output_choice != "1" && output_choice != "2");

    if (output_choice == "1"){
        print_spellbook_results(sorted_spbk, sort_method, num_spellbooks, is_student);
    } else {
        save_to_file(sorted_spbk, sort_method, num_spellbooks, is_student);
    }
}

/*******************************************************************
** Function: spell_results()
** Description: gets user's choice to output spell results, sends to
** appropriate function
** Parameters: sorted_sp, num_spells, is_student
** Pre-Conditions: sorted_sp must have sorted spells, must know if 
** user is student
** Post-Conditions: None
*******************************************************************/ 
void spell_results(spell* sorted_sp, int num_spells, bool is_student){
    string output_choice;

    do {
        cout << "Enter 1 to print results to the screen or 2 to save results in a text file: ";
        cin >> output_choice;
    } while (output_choice != "1" && output_choice != "2");

    if (output_choice == "1"){
        print_spell_results(sorted_sp, num_spells, is_student);
    } else {
        save_sp_file(sorted_sp, num_spells, is_student);
    }
}

/*******************************************************************
** Function: can_print_spellbook()
** Description: checks whether the user can see spellbook based off 
** of whether user is student and the contents of the book
** Parameters: sorted_spbk, num_entries, is_student, current_i
** Pre-Conditions: sorted_spbk must have sorted spellbooks, must have
** index of spellbook being checked
** Post-Conditions: None
*******************************************************************/ 
bool can_print_spellbook(spellbook* sorted_spbk, int num_entries, bool is_student, int current_i){
    int num_spells = sorted_spbk[current_i].num_spells;

    if (is_student == false){
        return true;
    } else {
        for (int j = 0; j < num_spells; j++){
            if (sorted_spbk[current_i].s[j].effect == "poison" || sorted_spbk[current_i].s[j].effect == "death"){
                return false;
            }
        }
        return true;
    }
}

/*******************************************************************
** Function: can_print_spell()
** Description: checks whether user can see spellbook based off of
** whether user is student and effect of spell
** Parameters: sorted_sp, num_entries, is_student, current_i
** Pre-Conditions: sorted_sp must have sorted spells, must know
** if user is student
** Post-Conditions: None
*******************************************************************/ 
bool can_print_spell(spell* sorted_sp, int num_entries, bool is_student, int current_i){
    if (is_student == false){
        return true;
    } else {
        if (sorted_sp[current_i].effect == "poison" || sorted_sp[current_i].effect == "death"){
            return false;
        } else {
            return true;
        }
    }
}

/*******************************************************************
** Function: print_spellbook_results()
** Description: prints spellbook results to screen if user is allowed
** to see spellbook
** Parameters: sorted_sp, sort_method, entries, is_student
** Pre-Conditions: sorted_sp must have sorted spellsbooks, must know
** if user is student
** Post-Conditions: None
*******************************************************************/ 
void print_spellbook_results(spellbook* sorted_spbk, int sort_method, int entries, bool is_student){
    bool can_print = true;
    for (int i = 0; i < entries; i++){
        if (can_print_spellbook(sorted_spbk, entries, is_student, i) == true){
            cout << sorted_spbk[i].title << " ";
            if (sort_method == 1){
                cout << sorted_spbk[i].num_pages;
            } else {
                cout << sorted_spbk[i].avg_success_rate;
            }
            cout << endl;
        }
    }
    cout << endl;
}

/*******************************************************************
** Function: print_spell_results()
** Description: prints spell results to screen if user is allowed
** to see spell
** Parameters: sorted_sp, entries, is_student
** Pre-Conditions: sorted_sp must have sorted spells, must know
** if user is student
** Post-Conditions: None
*******************************************************************/ 
void print_spell_results(spell* sorted_sp, int entries, bool is_student){
    bool can_print = true;
    for (int i = 0; i < entries; i++){
        if (can_print_spell(sorted_sp, entries, is_student, i) == true){
            cout << sorted_sp[i].effect << " ";
            cout << sorted_sp[i].name << endl;
        }
    }
    cout << endl;
}

/*******************************************************************
** Function: get_output_file()
** Description: gets file location from user, tries to open file
** Parameters: sorted_sp, sort_method, entries, is_student
** Pre-Conditions: fstream
** if user is student
** Post-Conditions: None
*******************************************************************/ 
void get_output_file(fstream& f){
    string f_name;
    bool is_open;

    cout << "Enter the file location you would like to output to: ";
    cin >> f_name;

    do {
        f.open(f_name, ios::out | ios::app);
        if (f.is_open() == false){
            cout << "Error opening file." << endl;
            is_open = false;
            f.close();
            cout << "Please enter valid file address: ";
            cin >> f_name;
        }
    } while (is_open != false);

}

/*******************************************************************
** Function: save_sp_file()
** Description: saves spells to file if user is allowed to see spells
** Parameters: sorted_sp, num_spell, is_student
** Pre-Conditions: sorted_sp must have sorted spells, must know
** if user is student
** Post-Conditions: None
*******************************************************************/ 
void save_sp_file(spell* sorted_sp, int num_spell, bool is_student){
    fstream fout;

    get_output_file(fout);
    fout << "Search Results: " << endl;
    for (int i = 0; i < num_spell; i++){
        if (can_print_spell(sorted_sp, num_spell, is_student, i) == true){
            fout << sorted_sp[i].effect << " ";
            fout << sorted_sp[i].name << endl;
        }
    }
    fout << endl;

    fout.close();
}

/*******************************************************************
** Function: save_to_file()
** Description: saves spellbook results to file if user is allowed
** to see spellbook
** Parameters: sorted_sp, sort_method, num_spellbooks, is_student
** Pre-Conditions: sorted_sp must have sorted spellsbooks, must know
** if user is student
** Post-Conditions: None
*******************************************************************/ 
void save_to_file(spellbook* sorted_spbk, int sort_method, int num_spellbooks, bool is_student){
    fstream fout;

    get_output_file(fout);

    fout << "Search Results:" << endl;
    for (int i = 0; i < num_spellbooks; i++){
        if (can_print_spellbook(sorted_spbk, num_spellbooks, is_student, i)){ //(sorted_spbk[i].s[j].effect != "death" || sorted_spbk[i].s[j]effect != "poison") || is_student == false){
            fout << sorted_spbk[i].title << " ";
            if (sort_method == 1){
                fout << sorted_spbk[i].num_pages;
            } else {
                fout << sorted_spbk[i].avg_success_rate;
            }
            fout << endl;
        }
    }

    fout << endl;
    fout.close();
}

/*******************************************************************
** Function: delete_spellbook_db()
** Description: deletes spell array in spellbook
** Parameters: spbk_db, num_spbk
** Pre-Conditions: spbk_db must have spellbooks, spbk_db must store
** spells in dynamic arrays
** Post-Conditions: None
*******************************************************************/ 
void delete_spellbook_db(spellbook*& spbk_db, int num_spbk){
    for (int i = 0; i < num_spbk; i++){
        delete [] spbk_db[i].s;
    }
}

/*******************************************************************
** Function: delete_components()
** Description: deletes memory allocated for wizard array and original
** spellbook array.
** Parameters: wiz_db, spbk_db, num_wiz, num_spbk
** Pre-Conditions: wiz_db and spbk_db must be dynamic arrays
** Post-Conditions: None
*******************************************************************/ 
void delete_components(wizard*& wiz_db, spellbook*& spbk_db, int num_wiz, int num_spbk){
    if (num_spbk > 0){
        delete_spellbook_db(spbk_db, num_spbk);
        delete [] spbk_db;
    }

    if (num_wiz > 0)
        delete [] wiz_db;
}