#include "vector.hpp"
#include <cmath>

Vector::Vector(double a, double b, double c):
    a(a), b(b), c(c) {

}

bool Vector::normalize() {
    if (a == 0 && b == 0 && c == 0) {
        return false;
    } else {
        double length = sqrt(a * a + b * b + c * c);
        a = a / length;
        b = b / length;
        c = c / length;
        return true;
    }
}

Vector Vector::unit_vector()
{
    double length = sqrt(a * a + b * b + c * c);
    return Vector(a / length, b / length, c / length);
}

double Vector::length() {
    return sqrt(a * a + b * b + c * c);
}

double Vector::length_square() {
    return a * a + b * b + c * c;
}

bool Vector::is_orthogonal(Vector v) {
    return a * v.a + b * v.b + c * v.c == 0;
}

Vector Vector::cross_product(Vector v) {
    return Vector(b * v.c - c * v.b,
                  c * v.a - a * v.c,
                  a * v.b - b * v.a);
}

double Vector::dot_product(Vector v) {
    return a * v.a + b * v.b + c * v.c;
}

double Vector::dot_product_square(Vector v)
{
    return (a * v.a + b * v.b + c * v.c) * (a * v.a + b * v.b + c * v.c);
}

double Vector::cos_theta(Vector v) {
    return (a * v.a + b * v.b + c * v.c) / sqrt((a * a + b * b + c * c) * (v.a * v.a + v.b * v.b + v.c * v.c));
}

double Vector::cos_theta_square(Vector v) {
    return (a * v.a + b * v.b + c * v.c) * (a * v.a + b * v.b + c * v.c) / ((a * a + b * b + c * c) * (v.a * v.a + v.b * v.b + v.c * v.c));
}
