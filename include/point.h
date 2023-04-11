#ifndef POINT_H
#define POINT_H

struct Point {
    double t;
    double x;
    double z;

    Point(double t, double x, double z) : t(t), x(x), z(z) {}
};

#endif // POINT_H
