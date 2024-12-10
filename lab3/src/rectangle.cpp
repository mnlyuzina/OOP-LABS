#include "../include/rectangle.h"
#include <vector>

Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

std::pair<double, double> Rectangle::geometricCenter() const {
    return {width / 2, height / 2};
}

std::vector<std::pair<double, double>> Rectangle::getVertices() const {
    return {{0, 0}, {width, 0}, {width, height}, {0, height}};
}

std::string Rectangle::getName() const {
    return "Rectangle";
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << "Rectangle: " << rect.width << " " << rect.height;
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rect) {
    is >> rect.width >> rect.height;
    return is;
}

Rectangle::operator double() const {
    return width * height;
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* rect = dynamic_cast<const Rectangle*>(&other);
    return rect && rect->width == width && rect->height == height;
}