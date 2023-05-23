//#ifndef DATE_H
//#define DATE_H
#include <iostream>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int, int, int);
    void print_date_short();
    void print_date_long();
    string year_to_string();

};

