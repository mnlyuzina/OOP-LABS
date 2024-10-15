#include <iostream>
#include <string>
#include <vector>

#pragma once

class Decimal {
public:
    Decimal();
    Decimal(const size_t& n, unsigned char t=0);
    Decimal(const std::initializer_list<unsigned char>& t);
    Decimal(const std::string& t);
    Decimal(const Decimal& other);
    Decimal(Decimal&& other) noexcept;

    Decimal& operator+=(const Decimal& other);
    Decimal& operator-=(const Decimal& other);

    Decimal operator+(const Decimal& other) const;
    Decimal operator-(const Decimal& other) const;

    bool operator>(const Decimal& other) const;
    bool operator<(const Decimal& other) const;
    bool operator==(const Decimal& other) const;

    std::ostream& print(std::ostream& os);

    virtual ~Decimal() noexcept;

private:
    size_t _size;
    unsigned char* _array;
};