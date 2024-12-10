#include <iostream>
#include <memory>
#include "include/rectangle.h"
#include "include/trapezoid.h"
#include "include/rhombus.h"
#include "include/array.h"
#include "include/figure.h"

int main() {
    Array<Figure<int>> figures;

    int n;
    std::cout << "Enter the number of figures: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        char type;
        std::cout << "Enter figure type (R for Rectangle, T for Trapezoid, D for Rhombus): ";
        std::cin >> type;
        if (type == 'R') {
            int width, height;
            std::cout << "Enter width and height: ";
            std::cin >> width >> height;
            figures.add(std::make_shared<Rectangle<int>>(width, height));
        } else if (type == 'T') {
            int base1, base2, height;
            std::cout << "Enter base1, base2, and height: ";
            std::cin >> base1 >> base2 >> height;
            figures.add(std::make_shared<Trapezoid<int>>(base1, base2, height));
        } else if (type == 'D') {
            int side, height;
            std::cout << "Enter side and height: ";
            std::cin >> side >> height;
            figures.add(std::make_shared<Rhombus<int>>(side, height));
        } else {
            std::cout << "Invalid figure type. Skipping...\n";
            --i;
        }
    }

    for (size_t i = 0; i < figures.size(); ++i) {
        const auto& figure = figures[i];
        std::cout << "Figure: " << figure.getName() << "\n";
        std::cout << "Geometric Center: " << figure.geometricCenter().first << " " << figure.geometricCenter().second << "\n";
        std::cout << "Area: " << static_cast<double>(figure) << "\n";
        std::cout << "Vertices: ";
        for (const auto& vertex : figure.getVertices()) {
            std::cout << *vertex << " ";
        }
        std::cout << "\n";
    }

    double totalArea = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        totalArea += static_cast<double>(figures[i]);
    }
    std::cout << "Total Area: " << totalArea << "\n";

    int index;
    std::cout << "Enter the index of the figure to remove: ";
    std::cin >> index;
    if (index >= 0 && index < figures.size()) {
        figures.remove(index);
    } else {
        std::cout << "Invalid index. No figure removed.\n";
    }

    std::cout << "Updated list of figures:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        const auto& figure = figures[i];
        std::cout << "Figure: " << figure.getName() << "\n";
        std::cout << "Geometric Center: " << figure.geometricCenter().first << " " << figure.geometricCenter().second << "\n";
        std::cout << "Area: " << static_cast<double>(figure) << "\n";
        std::cout << "Vertices: ";
        for (const auto& vertex : figure.getVertices()) {
            std::cout << *vertex << " ";
        }
        std::cout << "\n";
    }

    return 0;
}