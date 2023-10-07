cmake_minimum_required(VERSION 3.10)
project(gtest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task01 ../src/main.cpp ../src/Decimal.cpp)


enable_testing()
add_executable(tests01 ../tests01.cpp ../src/Decimal.cpp)
target_link_libraries(tests01 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests01)








# cmake_minimum_required(VERSION 3.10)
# project(lab1)

# add_executable(a.out main.cpp max_val.cpp)
# find_package(GTest REQUIRED)

# add_executable(tests.out tests01.cpp max_val.cpp)

# target_link_libraries(a.out ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

# enable_testing()

# add_test(add a.out)

# # include_directories(${GTEST_INCLUDE_DIRS})

# # add_executable(main main.cpp max_val.cpp)


# # enable_testing()

# # target_link_libraries(tests01 ${GTEST_LIBRARIES})

# # add_test(NAME BASIC COMMAND tests01)
