#include "../include/rhombus.h"

template <Scalar T>
Rhombus<T>::Rhombus(T side, T height) : side(side), height(height) {}

template <Scalar T>
std::pair<T, T> Rhombus<T>::geometricCenter() const {
    return {side / 2, height / 2};
}

template <Scalar T>
std::vector<std::unique_ptr<Point<T>>> Rhombus<T>::getVertices() const {
    std::vector<std::unique_ptr<Point<T>>> vertices;
    vertices.push_back(std::make_unique<Point<T>>(side / 2, 0));
    vertices.push_back(std::make_unique<Point<T>>(side, height / 2));
    vertices.push_back(std::make_unique<Point<T>>(side / 2, height));
    vertices.push_back(std::make_unique<Point<T>>(0, height / 2));
    return vertices;
}

template <Scalar T>
std::string Rhombus<T>::getName() const {
    return "Rhombus";
}

template <Scalar T>
Rhombus<T>::operator double() const {
    return static_cast<double>(side) * static_cast<double>(height);
}

template <Scalar T>
Rhombus<T>* Rhombus<T>::clone() const {
    return new Rhombus(*this);
}

template <Scalar T>
bool Rhombus<T>::operator==(const Figure<T>& other) const {
    const Rhombus<T>* rhomb = dynamic_cast<const Rhombus<T>*>(&other);
    return rhomb && rhomb->side == side && rhomb->height == height;
}

template class Rhombus<int>;
template class Rhombus<double>;
