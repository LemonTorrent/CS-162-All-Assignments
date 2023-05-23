#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "shape.h"
#include "rectangle.h"

class Square : public Rectangle {
   private:

   public:
      float area();
      void set_width(float);
      float get_width();

      Square();
      Square(float);
};

#endif