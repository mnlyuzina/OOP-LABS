#include "../include/trapezoid.h"
#include <vector>

Trapezoid::Trapezoid(double base1, double base2, double height) : base1(base1), base2(base2), height(height) {}

std::pair<double, double> Trapezoid::geometricCenter() const {
    return {(base1 + base2) / 2, height / 2};
}

std::vector<std::pair<double, double>> Trapezoid::getVertices() const {
    return {{0, 0}, {base1, 0}, {base2, height}, {0, height}};
}

std::string Trapezoid::getName() const {
    return "Trapezoid";
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& trap) {
    os << "Trapezoid: " << trap.base1 << " " << trap.base2 << " " << trap.height;
    return os;
}

std::istream& operator>>(std::istream& is, Trapezoid& trap) {
    is >> trap.base1 >> trap.base2 >> trap.height;
    return is;
}

Trapezoid::operator double() const {
    return (base1 + base2) * height / 2;
}

Trapezoid* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* trap = dynamic_cast<const Trapezoid*>(&other);
    return trap && trap->base1 == base1 && trap->base2 == base2 && trap->height == height;
}