//
// A basic rectangle class (no inheritance from a shape like in Lab 6/7).
//
#include <iostream>

using std::ostream;

class Rectangle {

    private:
        int _width;
        int _height;

    public:
        Rectangle();
        Rectangle(int, int);

        int area() const;

        int width() const;
        int height() const;
};

//
// Declaring some overloaded operators.
//
Rectangle operator+ (const Rectangle &, const Rectangle &);
ostream& operator<< (ostream &, const Rectangle &);
