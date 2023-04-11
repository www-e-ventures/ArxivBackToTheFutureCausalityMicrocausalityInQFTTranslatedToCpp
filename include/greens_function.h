#ifndef GREENS_FUNCTION_H
#define GREENS_FUNCTION_H
//https://e.ventures
//the@e.ventures
//Translated to C++ by e.ventures
//Original paper: https://arxiv.org/pdf/2208.09014.pdf
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
