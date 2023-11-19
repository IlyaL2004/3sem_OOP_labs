#include "figure.h"
#pragma once

template <typename T>

class Pentagon : public Figure<T>
{
    public:
        using point = pair<T, T>;

        Pentagon()
        {
            p1.first = 0; p2.first = 0; p3.first = 0; p4.first = 0; p5.first = 0;
            p1.second = 0; p2.second = 0; p3.second = 0; p4.second = 0; p5.second = 0;
            side1 = 0; side2 = 0; side3 = 0; side4 = 0; side5 = 0;
        }

        Pentagon(point _p1, point _p2, point _p3, point _p4, point _p5)
        {
            p1.first = _p1.first; p2.first = _p2.first;p3.first = _p3.first;p4.first = _p4.first;p5.first = _p5.first;
            p1.second = _p1.second; p2.second = _p2.second;p3.second = _p3.second;p4.second = _p4.second;p5.second = _p5.second;
            double side1 = round((sqrt((p2.first - p1.first)*(p2.first - p1.first) + (p2.second - p1.second)*(p2.second - p1.second))) * 1000) / 1000;
            double side2 = round((sqrt((p3.first - p2.first)*(p3.first - p2.first) + (p3.second - p2.second)*(p3.second- p2.second))) * 1000) / 1000;
            double side3 = round((sqrt((p4.first - p3.first)*(p4.first - p3.first) + (p4.second - p3.second)*(p4.second - p3.second))) * 1000) / 1000;
            double side4 = round((sqrt((p5.first - p4.first)*(p5.first - p4.first) + (p5.second - p4.second)*(p5.second - p4.second))) * 1000) / 1000;
            double side5 = round((sqrt((p1.first - p5.first)*(p1.first - p5.first) + (p1.second - p5.second)*(p1.second - p5.second))) * 1000) / 1000;
            this->side1 = side1;
            this->side2 = side2;
            this->side3 = side3;
            this->side4 = side4;
            this->side5 = side5;
        }

        virtual point geom_centr_calc() const override
        {
            point result;
            if (side1 != side2 || side1 != side3 || side1 != side4 || side1 != side5){
            throw std::logic_error{"That's not a correct figure!\n"};
            }
            result.first = round(((p1.first + p2.first + p3.first + p4.first + p5.first) / 5)*1000)/1000 + 0.0;
            result.second = round(((p1.second + p2.second + p3.second + p4.second + p5.second) / 5)*1000)/1000 + 0.0;
            return result;

        }
        
        virtual operator double() const override
        {   
            if (side1 != side2 || side1 != side3 || side1 != side4 || side1 != side5){
                throw std::logic_error{"That's not a correct figure!\n"};
            }
            return static_cast<double>(5 * (side1 * side1)/4) / tan((M_PI / 5));
        }

        virtual double figure_square_calc() const override{
            if (side1 != side2 || side1 != side3 || side1 != side4 || side1 != side5){
                throw std::logic_error{"That's not a correct figure!\n"};
            }
            double sq = (5 * (side1 * side1)/4) / tan((M_PI / 5));
            return sq;
        }


        virtual inline ostream& operator<<(ostream& os) const override
        {
            os << "Points of Pentagon:" << endl;
            os << "Point 1: " << p1.first << ", " << p1.second << endl;
            os << "Point 2: " << p2.first << ", " << p2.second << endl;
            os << "Point 3: " << p3.first << ", " << p3.second << endl;
            os << "Point 4: " << p4.first << ", " << p4.second << endl;
            os << "Point 5: " << p5.first << ", " << p5.second << endl;
            return os;
        }
        virtual inline istream& operator>>(istream& is) override
        {
            point p1, p2, p3, p4, p5;
            cout << "Input point pentagon: \n";
            cout << "Point 1: "; is >> p1.first >> p1.second;
            cout << "Point 2: "; is >> p2.first >> p2.second;
            cout << "Point 3: "; is >> p3.first >> p3.second;
            cout << "Point 4: "; is >> p4.first >> p4.second;
            cout << "Point 5: "; is >> p5.first >> p5.second;
            
            return is;
        }

        void operator=(const Pentagon<T>& fig)
        {
            p1.first = fig.p1.first;p2.first = fig.p2.first;p3.first = fig.p3.first;p4.first = fig.p4.first;p5.first = fig.p5.first;
            p1.second = fig.p1.second;p2.second = fig.p2.second;p3.second = fig.p3.second;p4.second = fig.p4.second;p5.second = fig.p5.second;
        }
        bool operator==(const Pentagon<T>& fig) const
        {
            if (p1.first == fig.p1.first && p2.first == fig.p2.first && p3.first == fig.p3.first && p4.first == fig.p4.first && p5.first == fig.p5.first &&
            p1.second == fig.p1.second && p2.second == fig.p2.second && p3.second == fig.p3.second && p4.second == fig.p4.second && p5.second == fig.p5.second)
                return true;
            else
                return false;
        }
    protected:
        point p1, p2, p3, p4, p5; 
        T side1, side2, side3, side4, side5;
};
