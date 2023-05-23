#include <iostream>
#include "shape.h"

using namespace std;

Shape::Shape(){

}

Shape::Shape(string n){
    name = n;
}

Shape::Shape(string n, string c){
    name = n;
    color = c;
}

/*float Shape::area(){
    return 0.0;
}
*/

string Shape::get_name() const{
    return name;
}

string Shape::get_color() const{
    return color;
}

void Shape::set_name(string n){
    name = n;
}

void Shape::set_color(string c){
    color = c;
}