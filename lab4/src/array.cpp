#include "../include/array.h"
#include "../include/figure.h"

template <typename T>
void Array<T>::add(const std::shared_ptr<T>& item) {
    data.push_back(item);
}

template <typename T>
void Array<T>::remove(size_t index) {
    if (index < data.size()) {
        data.erase(data.begin() + index);
    }
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    return *data[index];
}

template <typename T>
size_t Array<T>::size() const {
    return data.size();
}

template class Array<Figure<int>>;
template class Array<Figure<double>>;