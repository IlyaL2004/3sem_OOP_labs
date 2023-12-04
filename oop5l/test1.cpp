#include <gtest/gtest.h>
#include <iostream>
#include "allocator.hpp"
#include "queue_container.hpp"

#define BLOCKS 1024

TEST(AllocTests, test1) {

    std::map<double, double, std::less<int>, My_Allocator::Allocator<std::pair<const double, double> > > test_map;
    test_map[1] = 1;
    test_map[2] = 3;
    test_map[3] = 5;
    test_map[4] = 6;
    test_map[5] = 8;

    testing::internal::CaptureStdout(); 
    for(const auto& [k,v]: test_map) {
            std::cout << k << " " << v << std::endl;
    } 
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    std::cout << 1 << " " << 1 << std::endl;
    std::cout << 2 << " " << 3 << std::endl;
    std::cout << 3 << " " << 5 << std::endl;
    std::cout << 4 << " " << 6 << std::endl;
    std::cout << 5 << " " << 8 << std::endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(QueueAllocator, test2) {

    Queue<int, My_Allocator::Allocator<int> > queue;
    queue.push(10);
    ASSERT_TRUE(queue.top() == 10);
}

TEST(QueueAllocator, test3) {

    Queue<int, My_Allocator::Allocator<int> > queue;
    queue.push(1);
    queue.push(5);
    queue.pop();

    ASSERT_TRUE(queue.top() == 5);   
}

TEST(QueueAllocator, test4) {

    Queue<int, My_Allocator::Allocator<int> > queue;
    queue.push(1);
    queue.push(5);
    queue.pop();
    queue.push(1);

    ASSERT_TRUE(queue.top() == 5);   
}



TEST(QueueAllocator, test5) {

    Queue<int, My_Allocator::Allocator<int> > queue;
    queue.push(1);
    queue.push(5);
    queue.pop();
    queue.pop();
    queue.push(1);

    ASSERT_TRUE(queue.top() == 1);   
}

TEST(QueueAllocator, test6) {

    Queue<int, My_Allocator::Allocator<int> > queue;
    queue.push(-1);
    queue.push(-5);
    queue.pop();
    queue.push(-1);

    ASSERT_TRUE(queue.top() == -5);   
}

TEST(QueueAllocator, test7) {

    Queue<int, My_Allocator::Allocator<int> > queue;
    queue.push(10);

    ASSERT_TRUE(queue.top() == 10);   
}

TEST(QueueAllocator, test8) {

    Queue<int, My_Allocator::Allocator<int> > queue;
    queue.push(1000);

    ASSERT_TRUE(queue.top() == 1000);   
}

TEST(QueueAllocator, test9) {

    Queue<int, My_Allocator::Allocator<int> > queue;
    ASSERT_TRUE(queue.begin() == queue.end());
}

TEST(QueueAllocator, test10) {

    Queue<double, My_Allocator::Allocator<double> > queue;
    EXPECT_ANY_THROW(queue.pop());
}

TEST(QueueIterator, test11) {
    Queue<int, My_Allocator::Allocator<int> > queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    Queue<int, My_Allocator::Allocator<int> >::Iterator it = queue.begin();

    testing::internal::CaptureStdout(); 
    std::cout << *it << std::endl;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout(); 
    std::cout << 1 << std::endl;
    std::string ans = testing::internal::GetCapturedStdout(); 
    
    ASSERT_TRUE(ans == output);
}



auto main(int argc, char** argv) -> int {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

