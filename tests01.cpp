#include <gtest/gtest.h>
#include "src/max_val.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(max_val(2,7)==6); 
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(max_val(2,8)==8);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(max_val(2,6)==6);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(max_val(7,2)==0);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(max_val(7,7)==7);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(max_val(1,7)==7);
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(max_val(3,7)==6);
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(max_val(4,7)==4);
}

TEST(test_09, basic_test_set)
{
    ASSERT_TRUE(max_val(8,7)==0);
}

TEST(test_10, basic_test_set)
{
    ASSERT_TRUE(max_val(8,15)==8);
}

TEST(test_11, basic_test_set)
{
    ASSERT_TRUE(max_val(8,25)==24);
}

TEST(test_12, basic_test_set)
{
    ASSERT_TRUE(max_val(0,0)==-1);
}

TEST(test_13, basic_test_set)
{
    ASSERT_TRUE(max_val(-1,0)==-1);
}

TEST(test_14, basic_test_set)
{
    ASSERT_TRUE(max_val(-1,-10)==-1);
}

TEST(test_15, basic_test_set)
{
    ASSERT_TRUE(max_val(0,-10)==-1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}