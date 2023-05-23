#include <iostream>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"

using namespace std;

void print_shape_info(Shape &s){
    cout << "Name = " << s.get_name() << endl;
    cout << "Color = " << s.get_color() << endl;
    cout << "Area = " << s.area() << endl << endl;
}

int main(){
    /*cout << "Shapes:" << endl;
    Shape shape1;
    shape1.set_color("red");
    shape1.set_name("crazy shape");
    cout << "color = " << shape1.get_color() << endl;
    cout << "name = " << shape1.get_name() << endl;

    cout << endl;

    Shape shape2("happy shape");
    cout << "name = " << shape2.get_name() << endl;
    shape2.set_color("blue");
    cout << "color = " << shape2.get_color() << endl;

    cout << endl;

    Shape shape3("sad shape", "pink");
    shape3.set_name("angry shape");
    shape3.set_color("green");
    cout << "color = " << shape3.get_color() << endl;
    cout << "name = " << shape3.get_name() << endl;

    cout << endl;

    cout << "Circles:" << endl;
    Circle circle1;
    circle1.set_color("white");
    circle1.set_radius(2.0);
    cout << "color = " << circle1.get_color() << endl;
    cout << "radius = " << circle1.get_radius() << endl;
    cout << "area = " << circle1.area() << endl;
    
    cout << endl;

    Circle circle2(4.0, "crazy circle");
    cout << "name = " << circle2.get_name() << endl;
    //shape2.set_color("blue");
    cout << "radius = " << circle2.get_radius() << endl;
    cout << "area = " << circle2.area() << endl;

    cout << endl;

    Circle circle3(9.12, "hungry circle", "navy blue");
    circle3.set_name("angry circle");
    circle3.set_color("orange");
    cout << "color = " << circle3.get_color() << endl;
    cout << "name = " << circle3.get_name() << endl;
    cout << "radius = " << circle3.get_radius() << endl;
    cout << "area = " << circle3.area() << endl;

    cout << endl;

    cout << "Rectangles: " << endl;
    Rectangle rectangle1;
    rectangle1.set_color("white");
    rectangle1.set_width(2.0);
    cout << "color = " << rectangle1.get_color() << endl;
    cout << "width = " << rectangle1.get_width() << endl;
    cout << "height = " << rectangle1.get_height() << endl;
    cout << "area = " << rectangle1.area() << endl;

    cout << endl;

    Rectangle rectangle2(4.0, 3.0);
    //cout << "name = " << rectangle2.get_name() << endl;
    //shape2.set_color("blue");
    cout << "width = " << rectangle2.get_width() << endl;
    cout << "height = " << rectangle2.get_height() << endl;
    cout << "area = " << rectangle2.area() << endl;

    cout << endl;

    Rectangle rectangle3(1.2, 2.3);
    rectangle3.set_name("angry rectangle");
    rectangle3.set_color("orange");
    cout << "color = " << rectangle3.get_color() << endl;
    cout << "name = " << rectangle3.get_name() << endl;
    cout << "width = " << rectangle3.get_width() << endl;
    cout << "height = " << rectangle3.get_height() << endl;
    cout << "area = " << rectangle3.area() << endl;

    cout << endl;

    cout << "< and >" << endl;
    if (rectangle2 > rectangle3){
        cout << "R2 > R3" << endl;
    } else {
        cout <<  "R2 is not > R3" << endl;
    }

    if (rectangle3 < rectangle2){
        cout << "R3 < R2" << endl;
    } else {
        cout << "R3 is not < R2" << endl;
    }

    cout << endl;

    cout << "Squares:" << endl;
    Square square1;
    //square1.set_color("white");
    //square1.set_width(2.1234);
    //cout << "color = " << square1.get_color() << endl;
    cout << "width = " << square1.get_width() << endl;
    cout << "height = " << square1.get_height() << endl;
    cout << "area = " << square1.area() << endl;
    
    cout << endl;

    Square square2(float (4.02));
    cout << "width = " << square2.get_width() << endl;
    cout << "height = " << square2.get_height() << endl;
    cout << "area = " << square2.area() << endl;

    cout << endl;

    Square square3;
    //sqaure3.set_name("sleepy square");
    //sqaure3.set_color("neon green");
    //cout << "color = " << sqaure3.get_color() << endl;
    //cout << "name = " << sqaure3.get_name() << endl;
    cout << "width = " << square3.get_width() << endl;
    square3.set_width(5.2);
    cout << "width = " << square3.get_width() << endl;
    cout << "height = " << square3.get_height() << endl;
    cout << "area = " << square3.area() << endl;
    */

    //Rectangle* pt1;
    cout << "Rectangles: " << endl;
    Rectangle rectangle1;
    /*rectangle1.set_name("Hoku");
    rectangle1.set_color("white");
    rectangle1.set_width(2.0);*/
    //pt1 = &rectangle1;
    /*cout << "color = " << rectangle1.get_color() << endl;
    cout << "width = " << rectangle1.get_width() << endl;
    cout << "height = " << rectangle1.get_height() << endl;
    cout << "area = " << rectangle1.area() << endl;
    */
    //print_shape_info(rectangle1);
    //print_shape_info(*pt1);
    //delete pt1;

    cout << "yo" << endl;

    //Rectangle* pt1;
    //Rectangle rectangle2(1, 1);
    //rectangle1.set_color("pink");
    //rectangle1.set_width(2.0);
    //pt1 = &rectangle1;
    //print_shape_info(rectangle2);
    return 0;
}