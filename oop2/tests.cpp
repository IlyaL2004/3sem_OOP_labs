#include <gtest/gtest.h>
#include "src/Decimal.h" 

TEST(test_01, basic_test_set){  
    Decimal first {"10"}; 
    Decimal second {"15"};
    first.add(second);
    ASSERT_TRUE(first.equal(Decimal{"25"}));
}

TEST(test_02, basic_test_set){  
    Decimal first {"0"}; 
    Decimal second {"15"};
    first.add(second);
    ASSERT_TRUE(first.equal(Decimal{"15"}));
}

TEST(test_03, basic_test_set){  
    Decimal first {"0"}; 
    Decimal second {"0"};
    first.add(second);
    ASSERT_TRUE(first.equal(Decimal{"0"}));
}

TEST(test_04, basic_test_set){  
    Decimal first {"98"}; 
    Decimal second {"36"};
    first.add(second);
    ASSERT_TRUE(first.equal(Decimal{"134"}));
}

TEST(test_05, basic_test_set){
    Decimal first {"100"};
    Decimal second {"0"};
    
    ASSERT_TRUE(first.big(second));
}

TEST(test_06, basic_test_set){
    Decimal first {"5"};
    Decimal second {"1"};
    
    ASSERT_TRUE(first.big(second));
}

TEST(test_07, basic_test_set){
    bool flag = false;
    try{
        Decimal not_11dec {"a1b2c"};
    }
    catch(exception &ex){
        flag = true;
    }

    ASSERT_TRUE(flag);
}

TEST(test_08, basic_test_set){
    bool flag = false;
    try{
        Decimal first {""};
    }catch(exception &ex){
        flag = true;
    }
    ASSERT_TRUE(flag);
}

TEST(test_09, basic_test_set){
    Decimal first {"1"};
    Decimal second {"1"};
    
    ASSERT_TRUE(first.equal(second));
}

TEST(test_10, basic_test_set){
    Decimal first {"0"};
    Decimal second {"0"};
    
    ASSERT_TRUE(first.equal(second));
}

TEST(test_11, basic_test_set){
    Decimal first {"1"};
    Decimal second {"5"};
    
    ASSERT_TRUE(first.small(second));
}

TEST(test_12, basic_test_set){
    Decimal first {"0"};
    Decimal second {"5"};
    
    ASSERT_TRUE(first.small(second));
}

TEST(test_13, basic_test_set){  
    Decimal first {"18"}; 
    Decimal second {"15"};
    first.add(second);
    ASSERT_TRUE(first.equal(Decimal{"3"}));
}

TEST(test_14, basic_test_set){  
    Decimal first {"18"}; 
    Decimal second {"0"};
    first.add(second);
    ASSERT_TRUE(first.equal(Decimal{"18"}));
}

TEST(test_15, basic_test_set){
    bool flag = true; 
    try{
        Decimal f{"100035"};
        Decimal s{"55"};
        s.remove(f);
    }catch(exception &ex){
        flag = false;
    }
    ASSERT_TRUE(flag);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
