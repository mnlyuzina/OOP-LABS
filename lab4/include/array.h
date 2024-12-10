#pragma once

#include <vector>
#include <memory>
#include <algorithm>

template <typename T>
class Array {
public:
    Array() = default;

    void add(const std::shared_ptr<T>& item);
    void remove(size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;

private:
    std::vector<std::shared_ptr<T>> data;
};
