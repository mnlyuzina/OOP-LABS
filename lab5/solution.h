#pragma once

#include <memory_resource>
#include <map>
#include <stdexcept>

#include <memory>
#include <deque>
#include <iterator>

#include <string>

struct ComplexType {
    int a;
    double b;
    std::string c;
};

class FixedMemoryResource : public std::pmr::memory_resource {
public:
    explicit FixedMemoryResource(std::size_t size);
    ~FixedMemoryResource() override;

    std::size_t get_used_memory() const;

private:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

    std::byte* buffer_;
    std::size_t size_;
    std::size_t used_;
    std::map<void*, std::size_t> allocated_blocks_;
};

template <typename T>
class Queue {
public:
    using value_type = T;
    using allocator_type = std::pmr::polymorphic_allocator<T>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<allocator_type>::pointer;
    using const_pointer = typename std::allocator_traits<allocator_type>::const_pointer;
    using iterator = typename std::deque<T, allocator_type>::iterator;
    using const_iterator = typename std::deque<T, allocator_type>::const_iterator;

    explicit Queue(const allocator_type& alloc = allocator_type())
        : deque_(alloc) {}

    void push(const T& value) {
        deque_.push_back(value);
    }

    void pop() {
        deque_.pop_front();
    }

    reference front() {
        return deque_.front();
    }

    const_reference front() const {
        return deque_.front();
    }

    bool empty() const {
        return deque_.empty();
    }

    iterator begin() {
        return deque_.begin();
    }

    const_iterator begin() const {
        return deque_.begin();
    }

    iterator end() {
        return deque_.end();
    }

    const_iterator end() const {
        return deque_.end();
    }

private:
    std::deque<T, allocator_type> deque_;
};
