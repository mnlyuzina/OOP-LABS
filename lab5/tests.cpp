#include <gtest/gtest.h>
#include "solution.h"

// Тест для FixedMemoryResource
TEST(FixedMemoryResourceTest, AllocateDeallocate) {
    const std::size_t memory_size = 1024;
    FixedMemoryResource memory_resource(memory_size);
    std::pmr::polymorphic_allocator<int> allocator(&memory_resource);

    int* ptr1 = allocator.allocate(1);
    int* ptr2 = allocator.allocate(1);

    allocator.deallocate(ptr1, 1);
    allocator.deallocate(ptr2, 1);

    EXPECT_EQ(memory_resource.get_used_memory(), 0);
}

// Тест для Queue с простыми типами
TEST(QueueTest, IntQueue) {
    const std::size_t memory_size = 1024;
    FixedMemoryResource memory_resource(memory_size);
    std::pmr::polymorphic_allocator<int> allocator(&memory_resource);

    Queue<int> int_queue(allocator);
    int_queue.push(1);
    int_queue.push(2);
    int_queue.push(3);

    EXPECT_EQ(int_queue.front(), 1);
    int_queue.pop();
    EXPECT_EQ(int_queue.front(), 2);
    int_queue.pop();
    EXPECT_EQ(int_queue.front(), 3);
    int_queue.pop();
    EXPECT_TRUE(int_queue.empty());
}

// Тест для Queue с сложными типами
TEST(QueueTest, ComplexTypeQueue) {
    const std::size_t memory_size = 1024;
    FixedMemoryResource memory_resource(memory_size);
    std::pmr::polymorphic_allocator<ComplexType> allocator(&memory_resource);

    Queue<ComplexType> complex_queue(allocator);
    complex_queue.push({1, 2.0, "one"});
    complex_queue.push({2, 3.0, "two"});
    complex_queue.push({3, 4.0, "three"});

    EXPECT_EQ(complex_queue.front().a, 1);
    EXPECT_EQ(complex_queue.front().b, 2.0);
    EXPECT_EQ(complex_queue.front().c, "one");
    complex_queue.pop();
    EXPECT_EQ(complex_queue.front().a, 2);
    EXPECT_EQ(complex_queue.front().b, 3.0);
    EXPECT_EQ(complex_queue.front().c, "two");
    complex_queue.pop();
    EXPECT_EQ(complex_queue.front().a, 3);
    EXPECT_EQ(complex_queue.front().b, 4.0);
    EXPECT_EQ(complex_queue.front().c, "three");
    complex_queue.pop();
    EXPECT_TRUE(complex_queue.empty());
}