#pragma once

#include "point.hpp"
#include "vector.hpp"

///
/// \brief The Line class
/// line representation:
/// x = x0 + at
/// y = y0 + bt
/// z = z0 + ct
///
class Line {
  public:
    double a, b, c, x0, y0, z0;

    Line(double a, double b, double c, double x0, double y0, double z0);
    Line(Point p, double a, double b, double c);
    Line(Point p, Vector t);
    bool normalize();
    Vector unit_vector();
};
