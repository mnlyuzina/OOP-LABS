#include <gtest/gtest.h>
#include "include/rectangle.h"
#include "include/trapezoid.h"
#include "include/rhombus.h"

TEST(RectangleTest, GeometricCenter) {
    Rectangle rect(4.0, 6.0);
    auto center = rect.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 3.0);
}

TEST(RectangleTest, Area) {
    Rectangle rect(4.0, 6.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(rect), 24.0);
}

TEST(RectangleTest, Vertices) {
    Rectangle rect(4.0, 6.0);
    auto vertices = rect.getVertices();
    ASSERT_EQ(vertices.size(), 4);
    EXPECT_EQ(vertices[0], std::make_pair(0.0, 0.0));
    EXPECT_EQ(vertices[1], std::make_pair(4.0, 0.0));
    EXPECT_EQ(vertices[2], std::make_pair(4.0, 6.0));
    EXPECT_EQ(vertices[3], std::make_pair(0.0, 6.0));
}

TEST(RectangleTest, Equality) {
    Rectangle rect1(4.0, 6.0);
    Rectangle rect2(4.0, 6.0);
    Rectangle rect3(3.0, 5.0);
    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
}

TEST(TrapezoidTest, GeometricCenter) {
    Trapezoid trap(4.0, 6.0, 5.0);
    auto center = trap.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 5.0);
    EXPECT_DOUBLE_EQ(center.second, 2.5);
}

TEST(TrapezoidTest, Area) {
    Trapezoid trap(4.0, 6.0, 5.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(trap), 25.0);
}

TEST(TrapezoidTest, Vertices) {
    Trapezoid trap(4.0, 6.0, 5.0);
    auto vertices = trap.getVertices();
    ASSERT_EQ(vertices.size(), 4);
    EXPECT_EQ(vertices[0], std::make_pair(0.0, 0.0));
    EXPECT_EQ(vertices[1], std::make_pair(4.0, 0.0));
    EXPECT_EQ(vertices[2], std::make_pair(6.0, 5.0));
    EXPECT_EQ(vertices[3], std::make_pair(0.0, 5.0));
}

TEST(TrapezoidTest, Equality) {
    Trapezoid trap1(4.0, 6.0, 5.0);
    Trapezoid trap2(4.0, 6.0, 5.0);
    Trapezoid trap3(3.0, 5.0, 4.0);
    EXPECT_TRUE(trap1 == trap2);
    EXPECT_FALSE(trap1 == trap3);
}

TEST(RhombusTest, GeometricCenter) {
    Rhombus rhomb(4.0, 5.0);
    auto center = rhomb.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 2.5);
}

TEST(RhombusTest, Area) {
    Rhombus rhomb(4.0, 5.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(rhomb), 20.0);
}

TEST(RhombusTest, Vertices) {
    Rhombus rhomb(4.0, 5.0);
    auto vertices = rhomb.getVertices();
    ASSERT_EQ(vertices.size(), 4);
    EXPECT_EQ(vertices[0], std::make_pair(2.0, 0.0));
    EXPECT_EQ(vertices[1], std::make_pair(4.0, 2.5));
    EXPECT_EQ(vertices[2], std::make_pair(2.0, 5.0));
    EXPECT_EQ(vertices[3], std::make_pair(0.0, 2.5));
}

TEST(RhombusTest, Equality) {
    Rhombus rhomb1(4.0, 5.0);
    Rhombus rhomb2(4.0, 5.0);
    Rhombus rhomb3(3.0, 4.0);
    EXPECT_TRUE(rhomb1 == rhomb2);
    EXPECT_FALSE(rhomb1 == rhomb3);
}