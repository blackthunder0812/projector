#include "utils.hpp"
#include <cmath>

Point solve_intersection(Point p, Vector d, Cone cone) {
    Vector d_unit_vector = d.unit_vector();
    Vector v_unit_vector = cone.v.unit_vector();
    Vector co(cone.p.x - p.x, cone.p.y - p.y, cone.p.z - p.z);
    double cos_theta = cos(cone.theta);
    double cos_theta_square = cos_theta * cos_theta;
    double a = d_unit_vector.dot_product_square(v_unit_vector) - cos_theta_square;
    double b = 2.0 * (d_unit_vector.dot_product(v_unit_vector) * co.dot_product(v_unit_vector) - d_unit_vector.dot_product(co) * cos_theta_square);
    double c = co.dot_product_square(v_unit_vector) - co.dot_product(co) * cos_theta_square;
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        return cone.p;
    } else {
        if (delta == 0) {
            double t = -b / 2.0 / a;
            return Point(p.x + t * d.a, p.y + t * d.b, p.z + t * d.c);
        } else {
            double sqrt_delta = sqrt(delta);
            double t1 = (-b - sqrt_delta) / 2.0 / a;
            double t2 = (-b + sqrt_delta) / 2.0 / a;
            Point p1(p.x + t1 * d.a, p.y + t1 * d.b, p.z + t1 * d.c);
            Point p2(p.x + t2 * d.a, p.y + t2 * d.b, p.z + t2 * d.c);

            // check if (P - C) . V  > 0
            if (Vector(p1.x - cone.p.x, p1.y - cone.p.y, p1.z - cone.p.z).dot_product(v_unit_vector) > 0) {
                return p1;
            } else {
                return p2;
            }
        }
    }
}
