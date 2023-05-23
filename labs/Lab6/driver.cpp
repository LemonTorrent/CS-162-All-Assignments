#include "fruit.h"
#include "apple.h"
#include "orange.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

    Apple a;
    Orange o;

    a.set_name("the biggest apple");
    a.set_weight(100);

    cout << "I am " << a.get_name() << " and I weigh " << a.get_weight()
         << " ounces!" << endl;

    cout << "I am just a regular " << o.get_name() << " and I weigh "
         << o.get_weight() << " ounces." << endl;


    if (o > a) {
        cout << "uh oh" << endl;
    }

    if (a > o) {
        cout << "a is bigger than o!" << endl;
    }

    a.set_weight(1);

    if (a < o) {
        cout << "now a is smaller than o!" << endl;
    }


    return 0;
}
