#include <iostream>
#include "find_num.h"

int find_num(int devider, int bound) {
    if (devider == 0) {
        std::cerr << "Devider cannot be zero" << std::endl;
        return -1;
    }
    int remainder = bound % devider;
    if (remainder == 0) {
        return bound;
    } else {
        int num = bound - remainder;
        return num;
    }
}