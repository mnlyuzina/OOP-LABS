#include "../include/trapezoid.h"

template <Scalar T>
Trapezoid<T>::Trapezoid(T base1, T base2, T height) : base1(base1), base2(base2), height(height) {}

template <Scalar T>
std::pair<T, T> Trapezoid<T>::geometricCenter() const {
    return {(base1 + base2) / 2, height / 2};
}

template <Scalar T>
std::vector<std::unique_ptr<Point<T>>> Trapezoid<T>::getVertices() const {
    std::vector<std::unique_ptr<Point<T>>> vertices;
    vertices.push_back(std::make_unique<Point<T>>(0, 0));
    vertices.push_back(std::make_unique<Point<T>>(base1, 0));
    vertices.push_back(std::make_unique<Point<T>>(base2, height));
    vertices.push_back(std::make_unique<Point<T>>(0, height));
    return vertices;
}

template <Scalar T>
std::string Trapezoid<T>::getName() const {
    return "Trapezoid";
}

template <Scalar T>
Trapezoid<T>::operator double() const {
    return (static_cast<double>(base1) + static_cast<double>(base2)) * static_cast<double>(height) / 2;
}

template <Scalar T>
Trapezoid<T>* Trapezoid<T>::clone() const {
    return new Trapezoid(*this);
}

template <Scalar T>
bool Trapezoid<T>::operator==(const Figure<T>& other) const {
    const Trapezoid<T>* trap = dynamic_cast<const Trapezoid<T>*>(&other);
    return trap && trap->base1 == base1 && trap->base2 == base2 && trap->height == height;
}

template class Trapezoid<int>;
template class Trapezoid<double>;