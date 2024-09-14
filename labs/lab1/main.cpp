#include <iostream>
#include "find_num.h"

int main() {
   int devider;
   int bound;
   int result;

   std::cout << "Enter the devider value:" << std::endl;
   if (!(std::cin >> devider)) {
    std::cerr << "Invalid input" << std::endl;
    return 1;
   }

   std::cout << "Enter the bound value:" << std::endl;
   if (!(std::cin >> bound)) {
    std::cerr << "Invalid input" << std::endl;
    return 1;
   }

   result = find_num(devider, bound);
   if (result != -1) {
    std::cout << "Find number = " << result << std::endl;
   }

   return 0;
}