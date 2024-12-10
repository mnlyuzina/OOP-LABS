#include <iostream>
#include <vector>
#include <memory>
#include "include/rectangle.h"
#include "include/trapezoid.h"
#include "include/rhombus.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;

    // Ввод количества фигур
    int n;
    std::cout << "Enter the number of figures: ";
    std::cin >> n;

    // Ввод фигур
    for (int i = 0; i < n; ++i) {
        char type;
        std::cout << "Enter figure type (R for Rectangle, T for Trapezoid, D for Rhombus): ";
        std::cin >> type;
        if (type == 'R') {
            double width, height;
            std::cout << "Enter width and height: ";
            std::cin >> width >> height;
            figures.push_back(std::make_unique<Rectangle>(width, height));
        } else if (type == 'T') {
            double base1, base2, height;
            std::cout << "Enter base1, base2, and height: ";
            std::cin >> base1 >> base2 >> height;
            figures.push_back(std::make_unique<Trapezoid>(base1, base2, height));
        } else if (type == 'D') {
            double side, height;
            std::cout << "Enter side and height: ";
            std::cin >> side >> height;
            figures.push_back(std::make_unique<Rhombus>(side, height));
        } else {
            std::cout << "Invalid figure type. Skipping...\n";
            --i; // Repeat the loop for the same index
        }
    }

    // Вывод геометрического центра, площади, названия и координат вершин для каждой фигуры
    for (const auto& figure : figures) {
        std::cout << "Figure: " << figure->getName() << "\n";
        std::cout << "Geometric Center: " << figure->geometricCenter().first << " " << figure->geometricCenter().second << "\n";
        std::cout << "Area: " << static_cast<double>(*figure) << "\n";
        std::cout << "Vertices: ";
        for (const auto& vertex : figure->getVertices()) {
            std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
        }
        std::cout << "\n";
    }

    // Общая площадь фигур
    double totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }
    std::cout << "Total Area: " << totalArea << "\n";

    // Удаление фигуры по индексу
    int index;
    std::cout << "Enter the index of the figure to remove: ";
    std::cin >> index;
    if (index >= 0 && index < figures.size()) {
        figures.erase(figures.begin() + index);
    } else {
        std::cout << "Invalid index. No figure removed.\n";
    }

    // Вывод обновленного списка фигур
    std::cout << "Updated list of figures:\n";
    for (const auto& figure : figures) {
        std::cout << "Figure: " << figure->getName() << "\n";
        std::cout << "Geometric Center: " << figure->geometricCenter().first << " " << figure->geometricCenter().second << "\n";
        std::cout << "Area: " << static_cast<double>(*figure) << "\n";
        std::cout << "Vertices: ";
        for (const auto& vertex : figure->getVertices()) {
            std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
        }
        std::cout << "\n";
    }

    return 0;
}