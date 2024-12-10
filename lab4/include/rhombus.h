#pragma once

#include "figure.h"

template <Scalar T>
class Rhombus : public Figure<T> {
public:
    Rhombus(T side, T height);

    std::pair<T, T> geometricCenter() const override;
    std::vector<std::unique_ptr<Point<T>>> getVertices() const override;
    std::string getName() const override;
    operator double() const override;
    Rhombus* clone() const override;
    bool operator==(const Figure<T>& other) const override;

private:
    T side, height;
};
