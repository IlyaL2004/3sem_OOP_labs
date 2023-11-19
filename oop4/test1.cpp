#include <gtest/gtest.h>
#include "pentagon.h"
#include "octagon.h"
#include "hexagon.h"

TEST(PentagonMethods, square1) {
    pair<double, double> p1(2, 0);
    pair<double, double> p2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5));
    pair<double, double> p3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5));
    pair<double, double> p4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5));
    pair<double, double> p5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon<double> pen1(p1, p2, p3, p4, p5);
    double sq = pen1.figure_square_calc();
    ASSERT_TRUE(sq = 9.50942);
}

TEST(OctagonMethods, square2) {
    pair<double, double> o1(cos(2 * M_PI / 6), sin(2 * M_PI / 6));
    pair<double, double> o2(cos(4 * M_PI / 6), sin(4 * M_PI / 6));
    pair<double, double> o3(cos(6 * M_PI / 6), sin(6 * M_PI / 6));
    pair<double, double> o4(cos(8 * M_PI / 6), sin(8 * M_PI / 6));
    pair<double, double> o5(cos(10 * M_PI / 6), sin(10 * M_PI / 6));
    pair<double, double> o6(cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    Octagon<double> oct1(o1, o2, o3, o4, o5, o6);
    double sq = oct1.figure_square_calc();
    ASSERT_TRUE(sq = 2.59808);
}

TEST(HexagonMethods, square3) {
    pair<double, double> h1(3 * cos(0), 3 * sin(0));
    pair<double, double> h2(3 * cos(M_PI / 4), 3 * sin(M_PI / 4));
    pair<double, double> h3(3 * cos(M_PI / 2), 3 * sin(M_PI / 2));
    pair<double, double> h4(3 * cos(3 * M_PI / 4), 3 * sin(3 * M_PI / 4));
    pair<double, double> h5(3 * cos(M_PI), 3 * sin(M_PI));
    pair<double, double> h6(3 * cos(5 * M_PI / 4), 3 * sin(5 * M_PI / 4));
    pair<double, double> h7(3 * cos(3 * M_PI / 2), 3 * sin(3 * M_PI / 2));
    pair<double, double> h8(3 * cos(7 * M_PI / 4), 3 * sin(7 * M_PI / 4));
    Hexagon<double> hex1(h1, h2, h3, h4, h5, h6, h7, h8);
    double sq = hex1.figure_square_calc();
    ASSERT_TRUE(sq = 25.4536);
}

TEST(PentagonMethods, geo_center1) {
    pair<double, double> p1(2, 0);
    pair<double, double> p2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5));
    pair<double, double> p3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5));
    pair<double, double> p4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5));
    pair<double, double> p5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon<double> pen1(p1, p2, p3, p4, p5);
    pair<double, double> p(1, 0);
    p = pen1.geom_centr_calc();
    ASSERT_TRUE((p.first == 0) && (p.second == 0));
}

TEST(OctagonMethods, geo_center2) {
    pair<double, double> o1(cos(2 * M_PI / 6), sin(2 * M_PI / 6));
    pair<double, double> o2(cos(4 * M_PI / 6), sin(4 * M_PI / 6));
    pair<double, double> o3(cos(6 * M_PI / 6), sin(6 * M_PI / 6));
    pair<double, double> o4(cos(8 * M_PI / 6), sin(8 * M_PI / 6));
    pair<double, double> o5(cos(10 * M_PI / 6), sin(10 * M_PI / 6));
    pair<double, double> o6(cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    Octagon<double> oct1(o1, o2, o3, o4, o5, o6);
    pair<double, double> o(1, 0);
    o = oct1.geom_centr_calc();
    ASSERT_TRUE((o.first == 0) && (o.second == 0));
}

TEST(HexagonMethods, geo_center3) {
    pair<double, double> h1(3 * cos(0), 3 * sin(0));
    pair<double, double> h2(3 * cos(M_PI / 4), 3 * sin(M_PI / 4));
    pair<double, double> h3(3 * cos(M_PI / 2), 3 * sin(M_PI / 2));
    pair<double, double> h4(3 * cos(3 * M_PI / 4), 3 * sin(3 * M_PI / 4));
    pair<double, double> h5(3 * cos(M_PI), 3 * sin(M_PI));
    pair<double, double> h6(3 * cos(5 * M_PI / 4), 3 * sin(5 * M_PI / 4));
    pair<double, double> h7(3 * cos(3 * M_PI / 2), 3 * sin(3 * M_PI / 2));
    pair<double, double> h8(3 * cos(7 * M_PI / 4), 3 * sin(7 * M_PI / 4));
    Hexagon<double> hex1(h1, h2, h3, h4, h5, h6, h7, h8);
    pair<double, double> h(1, 0);
    h = hex1.geom_centr_calc();
    ASSERT_TRUE((h.first == 0) && (h.second == 0));
}

TEST(PentagonOperatorsOverloads, square_op_overload) {
    pair<double, double> p1(2, 0);
    pair<double, double> p2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5));
    pair<double, double> p3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5));
    pair<double, double> p4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5));
    pair<double, double> p5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon<double> pen1(p1, p2, p3, p4, p5);
    double sq = pen1;
    ASSERT_TRUE(sq = 9.50942);
}

TEST(PentagonOperatorsOverloads, equal_oper_overload1) {
    pair<double, double> p1(2, 0);
    pair<double, double> p2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5));
    pair<double, double> p3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5));
    pair<double, double> p4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5));
    pair<double, double> p5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon<double> pen1(p1, p2, p3, p4, p5);
    Pentagon<double> pen2(p1, p2, p3, p4, p5);
    ASSERT_TRUE(pen1 == pen2);

}

TEST(PentagonOperatorsOverloads, equal_oper_overload2) {
    pair<double, double> p1(2, 0);
    pair<double, double> p2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5));
    pair<double, double> p3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5));
    pair<double, double> p4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5));
    pair<double, double> p5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    pair<double, double> p11(1, 0);
    pair<double, double> p22(1 * cos(2 * M_PI / 5), 1 * sin(2 * M_PI / 5));
    pair<double, double> p33(1 * cos(4 * M_PI / 5), 1 * sin(4 * M_PI / 5));
    pair<double, double> p44(1 * cos(6 * M_PI / 5), 1 * sin(6 * M_PI / 5));
    pair<double, double> p55(1 * cos(8 * M_PI / 5), 1 * sin(8 * M_PI / 5));
    Pentagon<double> pen1(p1, p2, p3, p4, p5);
    Pentagon<double> pen2(p11, p22, p33, p44, p55);
    ASSERT_FALSE(pen1 == pen2);
}

TEST(PentagonOperatorsOverloads, assign_oper_overload1) {
    pair<double, double> p1(2, 0);
    pair<double, double> p2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5));
    pair<double, double> p3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5));
    pair<double, double> p4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5));
    pair<double, double> p5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon<double> pen1(p1, p2, p3, p4, p5);
    Pentagon<double> pen2;
    pen2 = pen1;

    ASSERT_TRUE(pen1 == pen2);
}

TEST(PentagonOperatorsOverloads, assign_oper_overload3) {
    Pentagon<double> p1;
    Pentagon<double> p2;
    p1 = p2;

    ASSERT_TRUE(p1 == p2);
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}