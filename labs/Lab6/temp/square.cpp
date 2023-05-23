#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "square.h"

using namespace std;

Square::Square(){
    width = 1.0;
    height = width;
}
Square::Square(float w){
    width = w;
    height = w;
}

float Square::area(){
    return (width * width);
}

void Square::set_width(float w){
    width = w;
    height = w;
}

float Square::get_width(){
    return width;
}
