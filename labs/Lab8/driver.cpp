#include <iostream>
#include <string>
#include "tuple.hpp"
#include "template_functions.hpp"
#include "rectangle.h"

using namespace std;

int main () {

    //
    // A basic template example using a tuple.
    //

    //
    // Creating a tuple of ints.
    //
    Tuple<int> new_coords(1, 2);

    //
    // Using '=' operator overload.
    //
    Tuple<int> my_coords;
    my_coords = new_coords;

    //
    // Outputting the contents.
    //
    cout << "My first value is: " << my_coords.get_d0() << endl
         << "My second value is: " << my_coords.get_d1() << endl
         << "--------------------------------------------------" << endl;

    //
    // Creating a tuple with a username and password.
    //
    Tuple<string> temp("taylozac@oregonstate.edu", "hunter2");

    //
    // Using copy constructor.
    //
    Tuple<string> user_pass(temp);

    //
    // Outputting the contents.
    //
    cout << "My username is: " << user_pass.get_d0() << endl
         << "My password is: " << user_pass.get_d1() << endl
         << "--------------------------------------------------" << endl;

    //
    // Changing some tuple values.
    //
    user_pass.set_d1("********");

    //
    // Outputting new contents.
    //
    cout << "My username is: " << user_pass.get_d0() << endl
         << "My password is: " << user_pass.get_d1() << endl
         << "--------------------------------------------------" << endl;

    //
    // Dynamic memory inside of the template class.
    //
    int *arr_1 = new int[10];
    int *arr_2 = new int[15];

    //
    // Why does this leak memory? Isn't this in a static array? How do we stop
    // these memory leaks from occurring?
    //
    Tuple<int *> arrs(arr_1, arr_2);

    //
    // Ouputting the contents.
    //
    cout << "First array address: " << arrs.get_d0() << endl
         << "Second array address: " << arrs.get_d1() << endl
         << "--------------------------------------------------" << endl;

    /*
    delete [] arr_1;
    delete [] arr_2;
    */


    //
    // What happens if we try to set a Tuple<int> equal to a Tuple<string>?
    //
    // my_coords = user_pass;


    //==========================================================================

    //
    // A basic template function example.
    //

    //
    // The sum of two ints.
    //
    cout << "Sum of 1 and 2: ";
    print_sum(1, 2);
    cout << endl;

    //
    // The sum of two string literals. Why doesn't this work?
    //
    /*
    cout << "Sum of \"my\" and \"string\": ";
    print_sum("my", "string");
    cout << endl;
    */

    //
    // The sum of two strings.
    //
    string a("my");
    string b("string");
    cout << "Sum of string a and string b: ";
    print_sum(a, b);
    cout << endl;

    //
    // What classes can we make these templates work with?
    //
    // If we can do it with other classes, how do we make sure they work with
    // these templated functions and classes?
    //

    //
    // The sum of two rectangles.
    //
    Rectangle r1(5,5);
    Rectangle r2(10,10);
    cout << "Rectangle r1: " << r1 << endl;
    cout << "Rectangle r2: " << r2 << endl;
    cout << "Sum of rectangle r1 and rectangle r2: ";
    print_sum(r1, r2);
    cout << endl;

    return 0;
}
