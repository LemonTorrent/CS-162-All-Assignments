#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "shape.h"

class Rectangle : public Shape {
   protected:
      float width;
      float height;
   public:
      float area() const;

      Rectangle();
      ~Rectangle();
      Rectangle(float, float);

      void set_width(float);
      void set_height(float);
      float get_width();
      float get_height();

      //bool operator> (const Rectangle &, const Rectangle &);
      //bool operator< (const Rectangle &, const Rectangle &);

};

bool operator> (const Rectangle &, const Rectangle &);
bool operator< (const Rectangle &, const Rectangle &);

#endif