#pragma once

#include "figure.h"

class Rhombus : public Figure {
public:
    Rhombus(double side, double height);

    std::pair<double, double> geometricCenter() const override;
    std::vector<std::pair<double, double>> getVertices() const override;
    std::string getName() const override;
    friend std::ostream& operator<<(std::ostream& os, const Rhombus& rhomb);
    friend std::istream& operator>>(std::istream& is, Rhombus& rhomb);
    operator double() const override;
    Rhombus* clone() const override;
    bool operator==(const Figure& other) const override;

private:
    double side, height;
};
