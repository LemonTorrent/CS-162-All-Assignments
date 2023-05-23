#include <iostream>

using namespace std;

template <class T>

//
// This function prints the sum of two imputs of the same type.
//
// Note that if the these are not primitive types (e.g. int, float, char) and
// are a user defined class, operator overloads for both '<<' and '+' must be
// provided.
//
void print_sum(T x, T y) {
    cout << x + y << endl;
    return;
}
