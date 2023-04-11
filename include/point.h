#ifndef POINT_H
#define POINT_H
//https://e.ventures
//the@e.ventures
//Translated to C++ by e.ventures
//Original paper: https://arxiv.org/pdf/2208.09014.pdf
struct Point {
    double t;
    double x;
    double z;

    Point(double t, double x, double z) : t(t), x(x), z(z) {}
};

#endif // POINT_H
