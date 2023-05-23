#include "rectangle.h"

//
// Default Constructor
//
Rectangle::Rectangle() {
    _width = -1;
    _height = -1;
    return;
}


//
// Non-default Constructor
//
Rectangle::Rectangle(int w, int h) {
    _width = w;
    _height = h;
    return;
}


//
// Area function.
//
int Rectangle::area() const {
    return _width * _height;
}

//
// Getters
//
int Rectangle::width() const {
    return _width;
}

int Rectangle::height() const {
    return _height;
}


//
// Setters
//

// Did not implement for this class.


//
// Overloaded operator '+' for the rectangle class. This adds the widths and
// height of the given rectangles to produce a new rectangle.
//
Rectangle operator+ (const Rectangle &r1, const Rectangle &r2) {
    Rectangle new_r(r1.width() + r2.width(), r1.height() + r2.height());
    return new_r;
}

//
// Overloaded operator '<<' for the rectangle class. This outputs the value
// given by the area when someone tries to 'cout' a rectangle.
//
ostream& operator<< (ostream &os, const Rectangle &r) {
    os << r.area();
    return os;
}
