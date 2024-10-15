#include "decimal.h"

int main() {
    Decimal a("4567");
    Decimal b("123");

    Decimal sum = a + b;
    a -= b;

    sum.print(std::cout) << std::endl;
    a.print(std::cout) << std::endl;
}