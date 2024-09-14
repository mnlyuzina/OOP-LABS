#include <gtest/gtest.h>
#include "find_num.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(find_num(10,50) == 50);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(find_num(2,7) == 6);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(find_num(0,1) == -1);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(find_num(100,100) == 100);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

