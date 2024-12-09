#include "solution.h"

FixedMemoryResource::FixedMemoryResource(std::size_t size)
    : buffer_(static_cast<std::byte*>(::operator new(size))), size_(size), used_(0) {
    if (!buffer_) {
        throw std::bad_alloc();
    }
}

FixedMemoryResource::~FixedMemoryResource() {
    ::operator delete(buffer_);
}

std::size_t FixedMemoryResource::get_used_memory() const {
    return used_;
}

void* FixedMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    if (used_ + bytes > size_) {
        throw std::bad_alloc();
    }

    void* ptr = buffer_ + used_;
    used_ += bytes;
    allocated_blocks_[ptr] = bytes;
    return ptr;
}

void FixedMemoryResource::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    auto it = allocated_blocks_.find(p);
    if (it != allocated_blocks_.end()) {
        used_ -= it->second;
        allocated_blocks_.erase(it);
    }
}

bool FixedMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}
