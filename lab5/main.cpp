// var 15
#include <iostream>
#include "solution.h"

int main() {
    const std::size_t memory_size = 1024;
    FixedMemoryResource memory_resource(memory_size);
    std::pmr::polymorphic_allocator<int> allocator(&memory_resource);

    Queue<int> int_queue(allocator);
    int_queue.push(1);
    int_queue.push(2);
    int_queue.push(3);

    std::cout << "Int Queue: ";
    for (auto it = int_queue.begin(); it != int_queue.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::pmr::polymorphic_allocator<ComplexType> complex_allocator(&memory_resource);
    Queue<ComplexType> complex_queue(complex_allocator);
    complex_queue.push({1, 2.0, "one"});
    complex_queue.push({2, 3.0, "two"});
    complex_queue.push({3, 4.0, "three"});

    std::cout << "ComplexType Queue: ";
    for (auto it = complex_queue.begin(); it != complex_queue.end(); ++it) {
        std::cout << it->a << " " << it->b << " " << it->c << " | ";
    }
    std::cout << std::endl;

    return 0;
}