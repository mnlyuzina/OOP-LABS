#include "../include/rectangle.h"

template <Scalar T>
Rectangle<T>::Rectangle(T width, T height) : width(width), height(height) {}

template <Scalar T>
std::pair<T, T> Rectangle<T>::geometricCenter() const {
    return {width / 2, height / 2};
}

template <Scalar T>
std::vector<std::unique_ptr<Point<T>>> Rectangle<T>::getVertices() const {
    std::vector<std::unique_ptr<Point<T>>> vertices;
    vertices.push_back(std::make_unique<Point<T>>(0, 0));
    vertices.push_back(std::make_unique<Point<T>>(width, 0));
    vertices.push_back(std::make_unique<Point<T>>(width, height));
    vertices.push_back(std::make_unique<Point<T>>(0, height));
    return vertices;
}

template <Scalar T>
std::string Rectangle<T>::getName() const {
    return "Rectangle";
}

template <Scalar T>
Rectangle<T>::operator double() const {
    return static_cast<double>(width) * static_cast<double>(height);
}

template <Scalar T>
Rectangle<T>* Rectangle<T>::clone() const {
    return new Rectangle(*this);
}

template <Scalar T>
bool Rectangle<T>::operator==(const Figure<T>& other) const {
    const Rectangle<T>* rect = dynamic_cast<const Rectangle<T>*>(&other);
    return rect && rect->width == width && rect->height == height;
}

template class Rectangle<int>;
template class Rectangle<double>;