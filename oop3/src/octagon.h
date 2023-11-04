#pragma once

#include <iostream>
#include "figure.h"
#include <math.h>

class Octagon: public Figure {

    friend std::istream& operator>>(std::istream& is, Octagon& t);
    friend std::ostream& operator<<(std::ostream& os, Octagon& t);

public:

    Octagon();
    Octagon(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4, double _x5, double _y5, double _x6, double _y6);
    operator double() const; 
    void operator=(const Octagon& t);
    void operator=(Octagon&& t);
    bool operator==(Octagon& t);
    virtual double figure_square_calc() const override;
    virtual void geo_center_calc() override;
    ~Octagon() = default;

private:
    double x1;double y1;
    double x2;double y2;
    double x3;double y3;
    double x4;double y4;
    double x5;double y5;
    double x6;double y6;
    double side1;double side2;double side3;double side4;double side5;double side6;

};

inline std::istream& operator>>(std::istream& is, Octagon& t) {

    std::cout << "the coordinates of the first point" << std::endl;
    is >> t.x1 >> t.y1;
    std::cout << "the coordinates of the second point" << std::endl;
    is >> t.x2 >> t.y2;
    std::cout << "the coordinates of the third point" << std::endl;
    is >> t.x3 >> t.y3;
    std::cout << "the coordinates of the third point" << std::endl;
    is >> t.x4 >> t.y4;
    std::cout << "the coordinates of the third point" << std::endl;
    is >> t.x5 >> t.y5;
    std::cout << "the coordinates of the third point" << std::endl;
    is >> t.x6 >> t.y6;
    return is;

}

inline std::ostream& operator<<(std::ostream& os, Octagon& t) {

    os << "Point1: " << t.x1 << "," << t.y1  << std::endl;
    os << "Point2: " << t.x2 << "," << t.y2  << std::endl;
    os << "Point3: " << t.x3 << "," << t.y3  << std::endl;
    os << "Point4: " << t.x4 << "," << t.y4  << std::endl;
    os << "Point5: " << t.x5 << "," << t.y5  << std::endl;
    os << "Point6: " << t.x6 << "," << t.y6  << std::endl;
    os << "P1: " << t.side1 << std::endl;
    os << "P2: " << t.side2 << std::endl;
    os << "P3: " << t.side3 << std::endl;
    os << "P4: " << t.side4 << std::endl;
    os << "P5: " << t.side5 << std::endl;
    os << "P6: " << t.side6 << std::endl;

    
    return os;
}
