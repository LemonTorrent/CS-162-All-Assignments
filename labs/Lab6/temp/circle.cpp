#include <iostream>
#include "shape.h"
#include "circle.h"

using namespace std;

Circle::Circle(){
    radius = 0;
}

Circle::Circle(float r){
    radius = r;
}

Circle::Circle(float r, string n){
    radius = r;
    name = n;
}

Circle::Circle(float r, string n, string c){
    radius = r;
    name = n;
    color = c;
}

Circle::Circle(string n){
    name = n;
}

Circle::Circle(string n, string c){
    name = n;
    color = c;
}

void Circle::set_radius(float r){
    radius = r;
}

float Circle::get_radius(){
    return radius;
}

float Circle::area(){
    float area;
    area = (radius * radius) * 3.14;

    return area;
}
