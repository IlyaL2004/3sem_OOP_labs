#include "figure.h"
#pragma once

template <typename T>

class Octagon : public Figure<T>
{
    public:
        using point = pair<T, T>;

        Octagon()
        {
            p1.first = 0; p2.first = 0; p3.first = 0; p4.first = 0; p5.first = 0, p6.first = 0;
            p1.second = 0; p2.second = 0; p3.second = 0; p4.second = 0; p5.second = 0, p6.second = 0;
            side1 = 0; side2 = 0; side3 = 0; side4 = 0; side5 = 0, side6 = 0;
        }

        Octagon(point _p1, point _p2, point _p3, point _p4, point _p5, point _p6)
        {
            p1.first = _p1.first; p2.first = _p2.first;p3.first = _p3.first;p4.first = _p4.first;p5.first = _p5.first;p6.first = _p6.first;
            p1.second = _p1.second; p2.second = _p2.second;p3.second = _p3.second;p4.second = _p4.second;p5.second = _p5.second;p6.second = _p6.second;
            double side1 = round((sqrt((p2.first - p1.first)*(p2.first - p1.first) + (p2.second - p1.second)*(p2.second - p1.second))) * 1000) / 1000;
            double side2 = round((sqrt((p3.first - p2.first)*(p3.first - p2.first) + (p3.second - p2.second)*(p3.second- p2.second))) * 1000) / 1000;
            double side3 = round((sqrt((p4.first - p3.first)*(p4.first - p3.first) + (p4.second - p3.second)*(p4.second - p3.second))) * 1000) / 1000;
            double side4 = round((sqrt((p5.first - p4.first)*(p5.first - p4.first) + (p5.second - p4.second)*(p5.second - p4.second))) * 1000) / 1000;
            double side5 = round((sqrt((p6.first - p5.first)*(p6.first - p5.first) + (p6.second - p5.second)*(p6.second - p5.second))) * 1000) / 1000;
            double side6 = round((sqrt((p1.first - p6.first)*(p1.first - p6.first) + (p1.second - p6.second)*(p1.second - p6.second))) * 1000) / 1000;
            this->side1 = side1;
            this->side2 = side2;
            this->side3 = side3;
            this->side4 = side4;
            this->side5 = side5;
            this->side6 = side6;
        }

        virtual point geom_centr_calc() const override
        {
            point result;
            if (side1 != side2 || side1 != side3 || side1 != side4 || side1 != side5 || side1 != side6){
            throw std::logic_error{"That's not a correct figure!\n"};
            }
            result.first = round(((p1.first + p2.first + p3.first + p4.first + p5.first + p6.first) / 6)*1000)/1000 + 0.0;
            result.second = round(((p1.second + p2.second + p3.second + p4.second + p5.second + p6.second) / 6)*1000)/1000 + 0.0;
            return result;

        }
        
        virtual operator double() const override
        {   
            if (side1 != side2 || side1 != side3 || side1 != side4 || side1 != side5 || side1 != side6){
                throw std::logic_error{"That's not a correct figure!\n"};
            }
            return static_cast<double>(6 * (side1 * side1)/4) / tan((M_PI / 6));
        }

        virtual double figure_square_calc() const override{
            if (side1 != side2 || side1 != side3 || side1 != side4 || side1 != side5 || side1 != side6){
                throw std::logic_error{"That's not a correct figure!\n"};
            }
            double sq = (6 * (side1 * side1)/4) / tan((M_PI / 6));
            return sq;
        }


        virtual inline ostream& operator<<(ostream& os) const override
        {
            os << "Points of Octagon:" << endl;
            os << "Point 1: " << p1.first << ", " << p1.second << endl;
            os << "Point 2: " << p2.first << ", " << p2.second << endl;
            os << "Point 3: " << p3.first << ", " << p3.second << endl;
            os << "Point 4: " << p4.first << ", " << p4.second << endl;
            os << "Point 5: " << p5.first << ", " << p5.second << endl;
            os << "Point 6: " << p6.first << ", " << p6.second << endl;
            return os;
        }
        virtual inline istream& operator>>(istream& is) override
        {
            point p1, p2, p3, p4, p5, p6;
            cout << "Input point Octagon: \n";
            cout << "Point 1: "; is >> p1.first >> p1.second;
            cout << "Point 2: "; is >> p2.first >> p2.second;
            cout << "Point 3: "; is >> p3.first >> p3.second;
            cout << "Point 4: "; is >> p4.first >> p4.second;
            cout << "Point 5: "; is >> p5.first >> p5.second;
            cout << "Point 6: "; is >> p6.first >> p6.second;
            
            return is;
        }

        void operator=(const Octagon<T>& fig)
        {
            p1.first = fig.p1.first;p2.first = fig.p2.first;p3.first = fig.p3.first;p4.first = fig.p4.first;p5.first = fig.p5.first;p6.first = fig.p6.first;
            p1.second = fig.p1.second;p2.second = fig.p2.second;p3.second = fig.p3.second;p4.second = fig.p4.second;p5.second = fig.p5.second;p6.second = fig.p6.second;
        }
        bool operator==(const Octagon<T>& fig) const
        {
            if (p1.first == fig.p1.first && p2.first == fig.p2.first && p3.first == fig.p3.first && p4.first == fig.p4.first && p5.first == fig.p5.first && p6.first == fig.p6.first &&
            p1.second == fig.p1.second && p2.second == fig.p2.second && p3.second == fig.p3.second && p4.second == fig.p4.second && p5.second == fig.p5.second && p6.second == fig.p6.second)
                return true;
            else
                return false;
        }
    protected:
        point p1, p2, p3, p4, p5, p6; 
        T side1, side2, side3, side4, side5, side6;
};