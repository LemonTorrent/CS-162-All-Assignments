#include <iostream>
#include <fstream>
#include <cmath>
#include <curses.h>
#include "./student_db.h"
//#include "./student_db.cpp"

using namespace std;

int main(int argc, char** argv){
    fstream my_file;
    //myfile.open(argv[1], ios::in);
    //if ()
    int num_students;
    student *db;

    get_file(argc, argv, my_file);
    //cout << "yo" << endl;
    get_student_db_info(db, my_file, num_students);
    //cout << "yeet" << endl;
    sort_db(db, num_students);
    //id_sort(db, num_students);
    //l_name_sort(db, num_students);
    save_to_file(db, my_file, num_students);
    delete_student_db_info(db);

    return 0;
}