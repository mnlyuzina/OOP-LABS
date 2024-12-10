#pragma once

#include <iostream>
#include <utility>
#include <vector>

class Figure {
public:
    virtual ~Figure() = default;

    // Вычисление геометрического центра фигуры вращения
    virtual std::pair<double, double> geometricCenter() const = 0;

    // Вывод координат вершин фигуры
    virtual std::vector<std::pair<double, double>> getVertices() const = 0;

    virtual std::string getName() const = 0;

    // Вывод координат вершин фигуры
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);

    // Чтение данных фигуры
    friend std::istream& operator>>(std::istream& is, Figure& figure);

    // Вычисление площади фигуры
    virtual operator double() const = 0;

    // Переопределение операций копирования, перемещения и сравнения
    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);