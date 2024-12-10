#pragma once

#include "figure.h"
#include <vector>

class Rectangle : public Figure {
public:
    Rectangle(double width, double height);

    std::pair<double, double> geometricCenter() const override;
    std::vector<std::pair<double, double>> getVertices() const override;
    std::string getName() const override;
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);
    friend std::istream& operator>>(std::istream& is, Rectangle& rect);
    operator double() const override;
    Rectangle* clone() const override;
    bool operator==(const Figure& other) const override;

private:
    double width, height;
};