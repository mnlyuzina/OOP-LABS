#include "../include/rhombus.h"
#include <vector>

Rhombus::Rhombus(double side, double height) : side(side), height(height) {}

std::pair<double, double> Rhombus::geometricCenter() const {
    return {side / 2, height / 2};
}

std::vector<std::pair<double, double>> Rhombus::getVertices() const {
    return {{side / 2, 0}, {side, height / 2}, {side / 2, height}, {0, height / 2}};
}

std::string Rhombus::getName() const {
    return "Rhombus";
}

std::ostream& operator<<(std::ostream& os, const Rhombus& rhomb) {
    os << "Rhombus: " << rhomb.side << " " << rhomb.height;
    return os;
}

std::istream& operator>>(std::istream& is, Rhombus& rhomb) {
    is >> rhomb.side >> rhomb.height;
    return is;
}

Rhombus::operator double() const {
    return side * height;
}

Rhombus* Rhombus::clone() const {
    return new Rhombus(*this);
}

bool Rhombus::operator==(const Figure& other) const {
    const Rhombus* rhomb = dynamic_cast<const Rhombus*>(&other);
    return rhomb && rhomb->side == side && rhomb->height == height;
}