#include <iostream>
#include <fstream>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H
struct student {
    int id;
    string f_name;
    string l_name;
    string major;
};

#endif

student* create_student_db(int);
int get_int(string);
void get_student_db_info(student*&, fstream&, int&);
void delete_student_db_info(student*&);
void get_file(int, char**, fstream&);
void sort_db(student*&, int);
void swap(student*&, int, int);
void id_sort(student*&, int);
void l_name_sort(student*&, int);
void save_to_file(student*, fstream&, int);