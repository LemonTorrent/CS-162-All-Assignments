#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

class Shape{
	protected:
	string name;
	string color;

	public:
	Shape();
	Shape(string);
	Shape(string, string);

	//virtual float area() const = 0;
	float area();
	~Shape();
	string get_name() const;
	string get_color() const;

	void set_name(string);
	void set_color(string);
};

#endif
