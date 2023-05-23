#include <iostream>
#include <cmath>
#include "./date.h"

using namespace std;

Date::Date(){
    month = 1;
    day = 1;
    year = 2001;
}

Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Date::print_date_short(){
    string temp_year = year_to_string();
    cout << month << "/" << day << "/" << temp_year[2] << temp_year[3] << endl;
    year_to_string();
}
void Date::print_date_long(){
    string month_names [12] = {"January", "Febuary", "March", "April","May", "June", "July", "August", "September", "October", "November", "December"};
    cout << month_names[month-1] << " " << day << ", " << year << endl;
}

string Date::year_to_string(){
    string output;
    int remainder, temp_year = year;

    for (int i = 3; i >= 0; i--){
        remainder = temp_year / pow(10, i);
        temp_year -= remainder * pow(10,i);
        //cout << remainder << endl;
        output += remainder + 48;
    }
    
    //cout << output << endl;
    return output;
}

/*
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
*/