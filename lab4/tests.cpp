#include <gtest/gtest.h>
#include "include/rectangle.h"
#include "include/rhombus.h"
#include "include/trapezoid.h"

TEST(RectangleTest, GeometricCenter) {
    Rectangle<int> rect(4, 6);
    auto center = rect.geometricCenter();
    EXPECT_EQ(center.first, 2);
    EXPECT_EQ(center.second, 3);
}

TEST(RectangleTest, Area) {
    Rectangle<int> rect(4, 6);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 24.0);
}

TEST(RectangleTest, Vertices) {
    Rectangle<int> rect(4, 6);
    auto vertices = rect.getVertices();
    ASSERT_EQ(vertices.size(), 4);
    EXPECT_EQ(*vertices[0], Point<int>(0, 0));
    EXPECT_EQ(*vertices[1], Point<int>(4, 0));
    EXPECT_EQ(*vertices[2], Point<int>(4, 6));
    EXPECT_EQ(*vertices[3], Point<int>(0, 6));
}

TEST(RectangleTest, Equality) {
    Rectangle<int> rect1(4, 6);
    Rectangle<int> rect2(4, 6);
    Rectangle<int> rect3(3, 5);
    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
}

TEST(TrapezoidTest, GeometricCenter) {
    Trapezoid<int> trap(4, 6, 5);
    auto center = trap.geometricCenter();
    EXPECT_EQ(center.first, 5);
    EXPECT_EQ(center.second, 2);
}

TEST(TrapezoidTest, Area) {
    Trapezoid<int> trap(4, 6, 5);
    EXPECT_DOUBLE_EQ(static_cast<double>(trap), 25.0);
}

TEST(TrapezoidTest, Vertices) {
    Trapezoid<int> trap(4, 6, 5);
    auto vertices = trap.getVertices();
    ASSERT_EQ(vertices.size(), 4);
    EXPECT_EQ(*vertices[0], Point<int>(0, 0));
    EXPECT_EQ(*vertices[1], Point<int>(4, 0));
    EXPECT_EQ(*vertices[2], Point<int>(6, 5));
    EXPECT_EQ(*vertices[3], Point<int>(0, 5));
}

TEST(TrapezoidTest, Equality) {
    Trapezoid<int> trap1(4, 6, 5);
    Trapezoid<int> trap2(4, 6, 5);
    Trapezoid<int> trap3(3, 5, 4);
    EXPECT_TRUE(trap1 == trap2);
    EXPECT_FALSE(trap1 == trap3);
}

TEST(RhombusTest, GeometricCenter) {
    Rhombus<int> rhomb(4, 5);
    auto center = rhomb.geometricCenter();
    EXPECT_EQ(center.first, 2);
    EXPECT_EQ(center.second, 2);
}

TEST(RhombusTest, Area) {
    Rhombus<int> rhomb(4, 5);
    EXPECT_DOUBLE_EQ(static_cast<double>(rhomb), 20.0);
}

TEST(RhombusTest, Vertices) {
    Rhombus<int> rhomb(4, 5);
    auto vertices = rhomb.getVertices();
    ASSERT_EQ(vertices.size(), 4);
    EXPECT_EQ(*vertices[0], Point<int>(2, 0));
    EXPECT_EQ(*vertices[1], Point<int>(4, 2));
    EXPECT_EQ(*vertices[2], Point<int>(2, 5));
    EXPECT_EQ(*vertices[3], Point<int>(0, 2));
}

TEST(RhombusTest, Equality) {
    Rhombus<int> rhomb1(4, 5);
    Rhombus<int> rhomb2(4, 5);
    Rhombus<int> rhomb3(3, 4);
    EXPECT_TRUE(rhomb1 == rhomb2);
    EXPECT_FALSE(rhomb1 == rhomb3);
}