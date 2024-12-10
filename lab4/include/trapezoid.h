#pragma once

#include "figure.h"

template <Scalar T>
class Trapezoid : public Figure<T> {
public:
    Trapezoid(T base1, T base2, T height);

    std::pair<T, T> geometricCenter() const override;
    std::vector<std::unique_ptr<Point<T>>> getVertices() const override;
    std::string getName() const override;
    operator double() const override;
    Trapezoid* clone() const override;
    bool operator==(const Figure<T>& other) const override;

private:
    T base1, base2, height;
};