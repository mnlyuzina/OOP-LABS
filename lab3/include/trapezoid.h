#pragma once

#include "figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid(double base1, double base2, double height);

    std::pair<double, double> geometricCenter() const override;
    std::vector<std::pair<double, double>> getVertices() const override;
    std::string getName() const override;
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& trap);
    friend std::istream& operator>>(std::istream& is, Trapezoid& trap);
    operator double() const override;
    Trapezoid* clone() const override;
    bool operator==(const Figure& other) const override;

private:
    double base1, base2, height;
};