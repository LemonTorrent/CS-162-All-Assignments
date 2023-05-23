#include <iostream>
#include <fstream>
#include <cmath>
#include <curses.h>
#include "./student_db.h"

using namespace std;

student* create_student_db(int num_students){
    student* db = new student [num_students];

    return db;
}

int get_int(string prompt) {
  int output_int = 0;

  if (prompt[0] == '-') {
    for (int i = 1; i < prompt.length(); i++){
      output_int += ((prompt[prompt.length()-i] - 48) * pow(10, i-1));
    }

    output_int *= -1;
  } else {    
    for (int i = 0; i < prompt.length(); i++){
    output_int += ((prompt[prompt.length()-1-i] - 48) * pow(10, i));
    }
  }
		
	return output_int;
}

void get_student_db_info(student*& db, fstream& file, int& num_students){
    string temp;
    //getline(file, temp);
    file >> temp;
    //cout << temp;
    num_students = get_int(temp);
    db = create_student_db(num_students);

    for (int i = 0; i < num_students; i++){
        //getline(file, temp, " ");
        file >> temp;
        //cout << temp << endl;
        db[i].id = get_int(temp);
        //cout << db[i].id << endl;
        //getline(file, temp);
        file >> temp;
        //cout << temp << endl;
        db[i].f_name = temp;
        //getline(file, temp);
        file >> temp;
        //cout << temp << endl;
        db[i].l_name = temp;
        //getline(file, temp);
        file >> temp;
        //cout << temp << endl;
        db[i].major = temp;
    }
    file.close();
}

void delete_student_db_info(student*& db){
    delete [] db;
}

void get_file(int argc, char** argv, fstream& my_file){
    string file_name;
    if (argc = 2){
        file_name.assign(argv[1]);
    } else {
        cout << "Enter a file name: ";
        cin >> file_name;
    }

    //cout << file_name << endl;
    my_file.open(file_name);
    //string temp;
    //my_file >> temp;
    //cout << temp;

    while (my_file.is_open() == false){
        cout << "Error opening file!" << endl;
        cout << "Enter another file name: ";
        cin >> file_name;
        my_file.close();
        my_file.open(file_name);
    }
}

void sort_db(student*& db, int num_students){
  string hmm;
  
  cout << "Enter 1 if you would like to sort by id, 2 to sort by last name: " << endl;
  cin >> hmm;
  //cout << "check" << endl;
  //cout << choice;
  if (hmm == "1"){
    //cout << "yeah";
    id_sort(db, num_students);
  } else {
    //cout << "ayy";
    l_name_sort(db, num_students);
  }
  //cout << "huh" << endl;
}

void swap(student*& db, int i, int j){  
    student temp = db[i];
    db[i] = db[j];
    db[j] = temp;
    //cout << "ok" << endl;
}

void id_sort(student*& db, int num_students){
  //cout << endl << endl;
  //cout << "id" << endl;
  //cout << "students = " << num_students << endl;
  for (int i = 0; i < num_students-1; i++){
    for (int j = 0; j < num_students-i-1; j++){
      //cout << db[j].id << endl;
      //cout << db[j+1].id << endl;
      if (db[j].id > db[j+1].id){
        //  cout << ":) ";
          swap(db, j, j+1);
          //cout << ":P" << endl;
          //cout << db[j].id << endl;
          //cout << db[i].id << endl;
          //cout << endl;
      }
    }
  }
}

void l_name_sort(student*& db, int num_students){
  for (int i = 0; i < num_students-1; i++){
    for (int j = 0; j < num_students-i-1; j++){
      if (db[j].l_name[0] > db[j+1].l_name[0])  
          swap(db, j, j+1);
    }
  }
}

void save_to_file(student *db, fstream& file, int num_students){
  string filename;

  cout << "Enter file name: ";
  cin >> filename;
  file.open(filename, ios::out | ios::app);

  file << "Results:" << endl;

  for (int i = 0; i < num_students; i++){
    file << db[i].id << " "
      << db[i].f_name << " "
      << db[i].l_name << " "
      << db[i].major << endl;
  }

  cout << endl;

  file.close();
}
