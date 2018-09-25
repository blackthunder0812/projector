#pragma once

///
/// \brief The Vector class
/// represent as point
class Vector {
  public:
    double a, b, c;

    Vector(double a, double b, double c);

    bool normalize();
    Vector unit_vector();
    double length();
    double length_square();

    bool is_orthogonal(Vector v);
    Vector cross_product(Vector v);
    double dot_product(Vector v);
    double dot_product_square(Vector v);
    double cos_theta(Vector v);
    double cos_theta_square(Vector v);
};
