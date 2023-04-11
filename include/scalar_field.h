#ifndef SCALAR_FIELD_H
#define SCALAR_FIELD_H

#include "point.h"

class ScalarField {
public:
    virtual double operator()(const Point& p) const = 0;
};

class FreeScalarField : public ScalarField {
public:
    double operator()(const Point& p) const override;
};

#endif // SCALAR_FIELD_H
