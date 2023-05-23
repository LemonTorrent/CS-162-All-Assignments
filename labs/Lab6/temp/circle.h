#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "shape.h"

class Circle : public Shape {
   private:
      float radius;
   public:
      float area();
      void set_radius(float);
      float get_radius();

      Circle();
      Circle(float);
      Circle(float, string);
      Circle(float, string, string);
      Circle(string);
      Circle(string, string);
};

#endif