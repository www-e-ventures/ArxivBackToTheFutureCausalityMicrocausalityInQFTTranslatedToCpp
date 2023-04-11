#ifndef GREENS_FUNCTION_H
#define GREENS_FUNCTION_H

#include <complex>
#include "scalar_field.h"

class GreensFunction {
public:
    virtual std::complex<double> operator()(const Point& x1, const Point& x2) const = 0;
};

class RetardedGreensFunction : public GreensFunction {
public:
    std::complex<double> operator()(const Point& x1, const Point& x2) const override;
};

#endif // GREENS_FUNCTION_H
