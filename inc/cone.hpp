#pragma once

#include "point.hpp"
#include "vector.hpp"

class Cone {
  public:
    Point p;
    Vector v;
    double theta;

    Cone(Point p, Vector v, double theta);
};
