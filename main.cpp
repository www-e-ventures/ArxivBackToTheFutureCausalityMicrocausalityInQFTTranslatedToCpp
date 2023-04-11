#include <iostream>
#include <cmath>
#include <functional>
#include "include/point.h"
#include "include/scalar_field.h"
#include "include/greens_function.h"

int main() {
    FreeScalarField scalarField;
    RetardedGreensFunction greensFunction;

    // An example of a higher-order function that applies a transformation on the Green's function.
    auto applyTransformation = [](const GreensFunction& greensFunction, const std::function<Point(const Point&)>& transformation, const Point& x1, const Point& x2) {
        Point transformedX1 = transformation(x1);
        Point transformedX2 = transformation(x2);
        return greensFunction(transformedX1, transformedX2);
    };

    // An example of a higher-order function that calculates the commutator using the Green's function.
    auto commutator = [](const GreensFunction& greensFunction, const ScalarField& scalarField, const Point& x1, const Point& x2) {
        return greensFunction(x1, x2) * (scalarField(x1) - scalarField(x2));
    };

    Point p1(0.0, 1.0, 2.0);
    Point p2(3.0, 4.0, 5.0);

    // Example transformation: A simple shift in the x direction.
    auto shiftX = [](double deltaX) {
        return [deltaX](const Point& p) -> Point {
            return Point(p.t, p.x + deltaX, p.z);
        };
    };

    // Apply a shift of 1.0 in the x direction.
    auto shiftedGreensFunction = applyTransformation(greensFunction, shiftX(1.0), p1, p2);
    auto comm = commutator(greensFunction, scalarField, p1, p2);

    std::cout << "Shifted Green's function value: " << shiftedGreensFunction << std::endl;
    std::cout << "Commutator value: " << comm << std::endl;

    // Example transformation: Scaling in the x direction.
    auto scaleX = [](double scaleFactor) {
        return [scaleFactor](const Point& p) -> Point {
            return Point(p.t, p.x * scaleFactor, p.z);
        };
    };

    // Apply a scaling of 2.0 in the x direction.
    auto scaledGreensFunction = applyTransformation(greensFunction, scaleX(2.0), p1, p2);
    auto scaledComm = commutator(greensFunction, scalarField, p1, p2);

    std::cout << "Scaled Green's function value: " << scaledGreensFunction << std::endl;
    std::cout << "Scaled commutator value: " << scaledComm << std::endl;

    // Example transformation: Shift in the z direction.
    auto shiftZ = [](double deltaZ) {
        return [deltaZ](const Point& p) -> Point {
            return Point(p.t, p.x, p.z + deltaZ);
        };
    };

    // Apply a shift of 1.0 in the z direction.
    auto shiftedZGreensFunction = applyTransformation(greensFunction, shiftZ(1.0), p1, p2);
    auto shiftedZComm = commutator(greensFunction, scalarField, p1, p2);

    std::cout << "Shifted (in z) Green's function value: " << shiftedZGreensFunction << std::endl;
    std::cout << "Shifted (in z) commutator value: " << shiftedZComm << std::endl;


}
