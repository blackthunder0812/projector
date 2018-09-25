#include "line.hpp"
#include <cmath>

Line::Line(double a, double b, double c, double x0, double y0, double z0) :
    a(a), b(b), c(c), x0(x0), y0(y0), z0(z0) {

}

Line::Line(Point p, double a, double b, double c):
    a(a), b(b), c(c), x0(p.x), y0(p.y), z0(p.z) {

}

Line::Line(Point p, Vector t):
    a(t.a), b(t.b), c(t.c), x0(p.x), y0(p.y), z0(p.z) {

}

bool Line::normalize() {
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

Vector Line::unit_vector() {
    double length = sqrt(a * a + b * b + c * c);
    return Vector(a / length, b / length, c / length);
}
