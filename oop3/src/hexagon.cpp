#include <iostream>
#include "hexagon.h"

Hexagon::Hexagon(): x1(0), x2(0), x3(0), x4(0), x5(0), x6(0), x7(0), x8(0), y1(0), y2(0), y3(0), y4(0), y5(0), y6(0), y7(0), y8(0), side1(0), side2(0), side3(0), side4(0), side5(0), side6(0), side7(0), side8(0){}

Hexagon::Hexagon(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4, double _x5, double _y5, double _x6, double _y6, double _x7, double _y7, double _x8, double _y8) {
   
    this->x1 = _x1; this->y1 = _y1; 
    this->x2 = _x2; this->y2 = _y2;
    this->x3 = _x3; this->y3 = _y3;
    this->x4 = _x4; this->y4 = _y4;
    this->x5 = _x5; this->y5 = _y5;
    this->x6 = _x6; this->y6 = _y6;
    this->x7 = _x7; this->y7 = _y7;
    this->x8 = _x8; this->y8 = _y8;

    double side1 = round((sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))) * 1000) / 1000;
    double side2 = round((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2))) * 1000) / 1000;
    double side3 = round((sqrt((x4 - x3)*(x4 - x3) + (y4 - y3)*(y4 - y3))) * 1000) / 1000;
    double side4 = round((sqrt((x5 - x4)*(x5 - x4) + (y5 - y4)*(y5 - y4))) * 1000) / 1000;
    double side5 = round((sqrt((x6 - x5)*(x6 - x5) + (y6 - y5)*(y6 - y5))) * 1000) / 1000;
    double side6 = round((sqrt((x7 - x6)*(x7 - x6) + (y7 - y6)*(y7 - y6))) * 1000) / 1000;
    double side7 = round((sqrt((x8 - x7)*(x8 - x7) + (y8 - y7)*(y8 - y7))) * 1000) / 1000;
    double side8 = round((sqrt((x1 - x8)*(x1 - x8) + (y1 - y8)*(y1 - y8))) * 1000) / 1000;
    

    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
    this->side4 = side4;
    this->side5 = side5;
    this->side6 = side6;
    this->side7 = side7;
    this->side8 = side8;


}


Hexagon::operator double() const {
    return figure_square_calc();
}

bool Hexagon::operator==(Hexagon& t) {
    if((x1 == t.x1) && (x2 == t.x2) && (x3 == t.x3) && (x4 == t.x4) && (x5 == t.x5) && (x6 == t.x6) && (x7 == t.x7) && (x8 == t.x8)
    && (y1 == t.y1) && (y2 == t.y2) && (y3 == t.y3) && (y4 == t.y4) && (y5 == t.y5) && (y6 == t.y6) && (y7 == t.y7) && (y8 == t.y8)) {
        return true;
    }
    return false;
}

void Hexagon::operator=(const Hexagon& t) {

        x1 = t.x1; x2 = t.x2; x3 = t.x3; x4 = t.x4; x5 = t.x5; x6 = t.x6; x7 = t.x7; x8 = t.x8;
        y1 = t.y1; y2 = t.y2; y3 = t.y3; y4 = t.y4; y5 = t.y5; y6 = t.y6; y7 = t.y7; y8 = t.y8;
        side1 = t.side1;side2 = t.side2;side3 = t.side3;side4 = t.side4;side5 = t.side5;side6 = t.side6;side7 = t.side7;side8 = t.side8; 
    }

void Hexagon::operator=(Hexagon&& t) {

        x1 = t.x1; x2 = t.x2; x3 = t.x3; x4 = t.x4; x5 = t.x5; x6 = t.x6;x7 = t.x7; x8 = t.x8;
        y1 = t.y1; y2 = t.y2; y3 = t.y3; y4 = t.y4; y5 = t.y5; y6 = t.y6;y7 = t.y7; y8 = t.y8;
        side1 = t.side1;side2 = t.side2;side3 = t.side3;side4 = t.side4;side5 = t.side5;side6 = t.side6;side7 = t.side7;side8 = t.side8; 
        t.x1 = 0; t.x2 = 0; t.x3 = 0; t.x4 = 0; t.x5 = 0; t.x6 = 0; t.x7 = 0; t.x8 = 0;
        t.y1 = 0; t.y2 = 0; t.y3 = 0; t.y4 = 0; t.y5 = 0; t.y6 = 0; t.y7 = 0; t.y8 = 0;
        t.side1 = 0;t.side2 = 0;t.side3 = 0;t.side4 = 0;t.side5 = 0; t.side6 = 0;t.side7 = 0;t.side8 = 0;t.geo_center_x = 0;t.geo_center_y = 0;
    }

double Hexagon::figure_square_calc() const{

    if (side1 != side2 || side1 != side3 || side1 != side4 || side1 != side5 || side1 != side6 || side1 != side7 || side1 != side8){
             throw std::logic_error{"That's not a correct figure!\n"};
         }
        double sq = (8 * (side1 * side1)/4) / tan((M_PI / 8));
        return sq;
    }

void Hexagon::geo_center_calc(){

    if (side1 != side2 || side1 != side3 || side1 != side4 || side1 != side5 || side1 != side6 || side1 != side7 || side1 != side8){
            throw std::logic_error{"That's not a correct figure!\n"};
        }

        double mid_x = round(((x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8) / 8)*1000)/1000 + 0.0;
        double mid_y = round(((y1 + y2 + y3 + y4 + y5 + y6 + y7 + y8) / 8)*1000)/1000 + 0.0;
        this->geo_center_x = mid_x;
        this->geo_center_y = mid_y;
    }
