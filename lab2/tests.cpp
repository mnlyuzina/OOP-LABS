#include <gtest/gtest.h>
#include "decimal.h"

TEST(DecimalTest, DefaultConstructor) {
    Decimal a;
    std::stringstream ss;
    a.print(ss);
    EXPECT_EQ(ss.str(), "0");  // expecting the empty object to be "0"
}

TEST(DecimalTest, StringConstructor) {
    Decimal a("12345");
    std::stringstream ss;
    a.print(ss);
    EXPECT_EQ(ss.str(), "12345");  // expecting a string representation of a number
}

TEST(DecimalTest, AdditionOperator) {
    Decimal a("12345");
    Decimal b("6789");
    Decimal result = a + b;
    std::stringstream ss;
    result.print(ss);
    EXPECT_EQ(ss.str(), "19134");  // 12345 + 6789 = 19134
}

TEST(DecimalTest, SubtractionOperator) {
    Decimal a("12345");
    Decimal b("10000");
    Decimal result = a - b;

    std::stringstream ss;
    result.print(ss);
    EXPECT_EQ(ss.str(), "2345");  // 12345 - 10000 = 2345
}

TEST(DecimalTest, GreaterThanOperator) {
    Decimal a("12345");
    Decimal b("6789");
    EXPECT_TRUE(a > b);
}

TEST(DecimalTest, LessThanOperator) {
    Decimal a("6789");
    Decimal b("12345");
    EXPECT_TRUE(a < b);
}

TEST(DecimalTest, EqualityOperator) {
    Decimal a("12345");
    Decimal b("12345");
    EXPECT_TRUE(a == b);
}

TEST(DecimalTest, SubtractionThrowsException) {
    Decimal a("12345");
    Decimal b("20000");
    EXPECT_THROW(a - b, std::logic_error);
}
