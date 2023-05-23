#include <iostream>
#include "./date.h"

using namespace std;

int main(){
    Date date1;
    Date date2(3, 15, 2013);

    date1.print_date_short();
    date1.print_date_long();

    date2.print_date_short();
    date2.print_date_long();
}