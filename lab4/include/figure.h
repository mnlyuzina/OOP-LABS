#pragma once

#include "point.h"
#include <iostream>
#include <utility>
#include <vector>
#include <memory>

template <Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual std::pair<T, T> geometricCenter() const = 0;

    virtual std::vector<std::unique_ptr<Point<T>>> getVertices() const = 0;

    virtual std::string getName() const = 0;

    virtual operator double() const = 0;
    
    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
};