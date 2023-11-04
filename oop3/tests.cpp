#include <gtest/gtest.h>
#include "src/pentagon.h"
#include "src/octagon.h"
#include "src/hexagon.h"



TEST(PentagonMethods, square1) {
    Pentagon p(2, 0, 2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5), 2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5), 2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5), 2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    double sq = p.figure_square_calc();
    ASSERT_TRUE(sq = 9.50942);
}

TEST(OctagonMethods, square2) {
    Octagon o(cos(2 * M_PI / 6), sin(2 * M_PI / 6), cos(4 * M_PI / 6), sin(4 * M_PI / 6), cos(6 * M_PI / 6), sin(6 * M_PI / 6), cos(8 * M_PI / 6), sin(8 * M_PI / 6), cos(10 * M_PI / 6), sin(10 * M_PI / 6), cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    double sq = o.figure_square_calc();
    ASSERT_TRUE(sq = 2.59808);
}

TEST(HexagonMethods, square3) {
    Hexagon h(3 * cos(0), 3 * sin(0), 3 * cos(M_PI / 4), 3 * sin(M_PI / 4), 3 * cos(M_PI / 2), 3 * sin(M_PI / 2), 3 * cos(3 * M_PI / 4), 3 * sin(3 * M_PI / 4), 3 * cos(M_PI), 3 * sin(M_PI), 3 * cos(5 * M_PI / 4), 3 * sin(5 * M_PI / 4), 3 * cos(3 * M_PI / 2), 3 * sin(3 * M_PI / 2), 3 * cos(7 * M_PI / 4), 3 * sin(7 * M_PI / 4));
    double sq = h.figure_square_calc();
    ASSERT_TRUE(sq = 25.4536);
}

TEST(PentagonMethods, geo_center1) {
    Pentagon p(2, 0, 2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5), 2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5), 2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5), 2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    p.geo_center_calc();
    double cent_x = p.get_geo_center_x();
    double cent_y = p.get_geo_center_y();
    ASSERT_TRUE((cent_x == 0) && (cent_y == 0));
}

TEST(OctagonMethods, geo_center2) {
    Octagon o(cos(2 * M_PI / 6), sin(2 * M_PI / 6), cos(4 * M_PI / 6), sin(4 * M_PI / 6), cos(6 * M_PI / 6), sin(6 * M_PI / 6), cos(8 * M_PI / 6), sin(8 * M_PI / 6), cos(10 * M_PI / 6), sin(10 * M_PI / 6), cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    o.geo_center_calc();
    double cent_x = o.get_geo_center_x();
    double cent_y = o.get_geo_center_y();
    ASSERT_TRUE((cent_x == 0) && (cent_y == 0));
}

TEST(HexagonMethods, geo_center3) {
    Hexagon h(3 * cos(0), 3 * sin(0), 3 * cos(M_PI / 4), 3 * sin(M_PI / 4), 3 * cos(M_PI / 2), 3 * sin(M_PI / 2), 3 * cos(3 * M_PI / 4), 3 * sin(3 * M_PI / 4), 3 * cos(M_PI), 3 * sin(M_PI), 3 * cos(5 * M_PI / 4), 3 * sin(5 * M_PI / 4), 3 * cos(3 * M_PI / 2), 3 * sin(3 * M_PI / 2), 3 * cos(7 * M_PI / 4), 3 * sin(7 * M_PI / 4));
    h.geo_center_calc();
    double cent_x = h.get_geo_center_x();
    double cent_y = h.get_geo_center_y();
    ASSERT_TRUE((cent_x == 0) && (cent_y == 0));
}

TEST(PentagonOperatorsOverloads, square_op_overload) {
    Pentagon p(2, 0, 2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5), 2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5), 2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5), 2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    double sq = p;
    ASSERT_TRUE(sq = 9.50942);
}

TEST(PentagonOperatorsOverloads, equal_oper_overload1) {
    Pentagon p1(2, 0, 2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5), 2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5), 2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5), 2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon p2(2, 0, 2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5), 2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5), 2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5), 2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    ASSERT_TRUE(p1 == p2);

}

TEST(PentagonOperatorsOverloads, equal_oper_overload2) {
    Pentagon p1(2, 0, 2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5), 2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5), 2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5), 2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon p2(1, 0, 1 * cos(2 * M_PI / 5), 1 * sin(2 * M_PI / 5), 1 * cos(4 * M_PI / 5), 1 * sin(4 * M_PI / 5), 1 * cos(6 * M_PI / 5), 1 * sin(6 * M_PI / 5), 1 * cos(8 * M_PI / 5), 1 * sin(8 * M_PI / 5));
    ASSERT_FALSE(p1 == p2);
}

TEST(PentagonOperatorsOverloads, assign_oper_overload1) {
    Pentagon p1(2, 0, 2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5), 2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5), 2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5), 2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon p2;
    p2 = p1;

    ASSERT_TRUE(p1 == p2);
}

TEST(PentagonOperatorsOverloads, assign_oper_overload3) {
    Pentagon p1;
    Pentagon p2;
    p1 = p2;

    ASSERT_TRUE(p1 == p2);
}

TEST(PentagonOperatorsOverloads, cout_oper_overload1) {
    testing::internal::CaptureStdout(); 
    Pentagon p1;
    cout << p1;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    cout << "Point1: 0,0" << endl;
    cout << "Point2: 0,0" << endl;
    cout << "Point3: 0,0" << endl;
    cout << "Point4: 0,0" << endl;
    cout << "Point5: 0,0" << endl;
    cout << "P1: 0" << endl;
    cout << "P2: 0" << endl;
    cout << "P3: 0" << endl;
    cout << "P4: 0" << endl;
    cout << "P5: 0" << endl;
    std::string ans = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, ans);
}

TEST(Pentagon1OperatorsOverloads, assign_oper_overload1) {
    Pentagon p1(2, 0, 2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5), 2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5), 2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5), 2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon p2;
    Pentagon p3;
    Pentagon p4;
    p4 = p1;
    p3 = std::move(p1);
    ASSERT_TRUE((p3 == p4) && (p1 == p2));
}





int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}