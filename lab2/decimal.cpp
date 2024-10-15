#include "decimal.h"
#include <stdexcept>
#include <algorithm>

Decimal::Decimal() : _size(1), _array(new unsigned char[1]) {
    std::cout << "Default constructor" << std::endl;
    _array[0] = 0;
}

Decimal::Decimal(const size_t& n, unsigned char t) : _size(n), _array(new unsigned char[n]) {
    std::cout << "Fill constructor" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        _array[i] = t;
    }
}

Decimal::Decimal(const std::initializer_list<unsigned char>& t) : _size(t.size()), _array(new unsigned char[_size]) {
    std::cout << "Initializer list constructor" << std::endl;
    size_t i = 0;
    for (auto& c : t) {
        _array[i++] = c;
    }
}

Decimal::Decimal(const std::string& t) : _size(t.size()), _array(new unsigned char[_size]) {
    std::cout << "Copy string constructor" << std::endl;
    for (size_t i = 0; i < _size; ++i) {
        if (!isdigit(t[i])) {
            throw std::invalid_argument("Invalid character in string");
        }
        _array[i] = t[_size - i - 1] - '0';
    }
}

Decimal::Decimal(const Decimal& other) : _size(other._size), _array(new unsigned char[_size]) {
    std::cout << "Copy constructor" << std::endl;
    for (size_t i = 0; i < _size; ++i) {
        _array[i] = other._array[i];
    }
}

Decimal::Decimal(Decimal&& other) noexcept: _size(other._size), _array(other._array) {
    std::cout << "Move constructor" << std::endl;
    other._size = 0;
    other._array = nullptr;
}

Decimal& Decimal::operator+=(const Decimal& other) {
    size_t max_size = std::max(_size, other._size);
    unsigned char* result = new unsigned char[max_size + 1];
    unsigned char carry = 0;
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char a = (i < _size) ? _array[i] : 0;
        unsigned char b = (i < other._size) ? other._array[i] : 0;
        unsigned char sum = a + b + carry;
        result [i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) {
        result[max_size] = carry;
        ++max_size;
    }

    delete[] _array;
    _array = result;
    _size = max_size;

    return *this;
}

Decimal& Decimal::operator-=(const Decimal& other) {
    if (_size < other._size) {
        throw std::logic_error("Negative result in unsigned operation");
    }
    for (size_t i = 0; i < _size; ++i) {
        unsigned char a = (i < _size) ? _array[i] : 0;
        unsigned char b = (i < other._size) ? other._array[i] : 0;
        if (a < b) {
            _array[i] = (10 + a) - b;
            if (i + 1 < _size) {
                --_array[i + 1];
            } else {
                throw std::logic_error("Negative result in unsigned operation");
            }
        } else {
            _array[i] = a - b;
        }
    }
    while (_size > 0 && _array[_size - 1] == 0) {
        --_size;
    }
    return *this;
}

Decimal Decimal::operator+(const Decimal& other) const {
    Decimal result(*this);
    result += other;
    return result;
}

Decimal Decimal::operator-(const Decimal& other) const {
    Decimal result(*this);
    result -= other;
    return result;
}

bool Decimal::operator>(const Decimal& other) const {
    if (_size != other._size) {
        return _size > other._size;
    }
    for (size_t i = _size; i > 0; --i) {
        if (_array[i - 1] != other._array[i - 1]) {
            return _array[i - 1] > other._array[i - 1];
        }
    }
    return false;
}

bool Decimal::operator<(const Decimal& other) const {
    return other > *this;
}

bool Decimal::operator==(const Decimal& other) const {
    if (_size != other._size) {
        return false;
    }
    for (size_t i = 0; i < _size; ++i) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }
    return true;
}

std::ostream& Decimal::print(std::ostream& os) {
    for (size_t i = _size; i > 0; --i) {
        os << static_cast<char>(_array[i - 1] + '0');
    }
    return os;
}

Decimal::~Decimal() noexcept {
    std::cout << "Destructor" << std::endl;
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

