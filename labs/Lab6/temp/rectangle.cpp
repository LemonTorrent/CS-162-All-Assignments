#include <iostream>
#include <stdexcept>
#include "shape.h"
#include "rectangle.h"

using namespace std;

float Rectangle::area() const{
    float area;
    area = width * height;

    return area;
}

Rectangle::Rectangle(){
    //throw "Invalid constructor argument";
    //throw invalid_argument("Invalid constructor argument");
    width = 1.0;
    height = 1.0;

    /*
    try{
        throw invalid_argument("Invalid constructor argument");

    } catch (string){
        cerr << "Caught string" << endl;
    } catch (...){
        cerr << "Caught unknown" << endl;
    }
    */
}

Rectangle::Rectangle(float w, float h){

    /*try{
        if (w == 0.0 || h == 0.0)
     
           throw invalid_argument("Invalid constructor argument");

    } catch (invalid_argument){
        cerr << "Caught argument" << endl;
    } catch (...){
        cerr << "Caught unknown" << endl;
    }
    */

    width = w;
    height = h;
}

void Rectangle::set_width(float w){
    width = w;
}

void Rectangle::set_height(float h){
    height = h;
}

float Rectangle::get_width(){
    return width;
}

float Rectangle::get_height(){
    return height;
}

Rectangle::~Rectangle(){
    cout <<"Destruct" << endl;
}


bool operator> (const Rectangle &r1, const Rectangle &r2){
    if (r1.area() > r2.area())
        return true;
    return false;
}

bool operator< (const Rectangle &r1, const Rectangle &r2){
    if (r1.area() < r2.area())
        return true;
    return false;
}
