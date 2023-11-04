#include <iostream>
#include "pentagon.h"
#include "octagon.h"
#include "hexagon.h"
using std::cin;
using std::cout;
using std::endl;
using std::move;

#define FIG 3


int main() {


        
        try{
        cout << "Pentagon: " << endl;
        Pentagon pen;
        cout << pen << endl;

        Pentagon p(2, 0, 2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5), 2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5), 2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5), 2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
        p.geo_center_calc();
        cout << p;
        
        cout << "test1 == " << endl;  

        Pentagon p1(1, 0, 1 * cos(2 * M_PI / 5), 1 * sin(2 * M_PI / 5), 1 * cos(4 * M_PI / 5), 1 * sin(4 * M_PI / 5), 1 * cos(6 * M_PI / 5), 1 * sin(6 * M_PI / 5), 1 * cos(8 * M_PI / 5), 1 * sin(8 * M_PI / 5));
        bool equal = (p == p1);
        cout << "egual:" << equal << endl;
        
        cout << "test2 == with = " << endl;

        Pentagon p2;
        p2 = p;
        bool equal1 = (p == p2);
        cout << "equal:" << equal1 << endl;

        cout << "test3 == with =(move) " << endl;

        Pentagon p3;
        p3 = move(p1);
        cout << p1 << endl;
        bool equal2 = (p1 == p3);
        cout << "equal:" << equal2 << endl;

        double sq1 = p.figure_square_calc();
        cout << "Pentagon square: " << sq1 << endl;



        cout << "Octagon: " << endl;
        Octagon o(cos(2 * M_PI / 6), sin(2 * M_PI / 6), cos(4 * M_PI / 6), sin(4 * M_PI / 6), cos(6 * M_PI / 6), sin(6 * M_PI / 6), cos(8 * M_PI / 6), sin(8 * M_PI / 6), cos(10 * M_PI / 6), sin(10 * M_PI / 6), cos(12 * M_PI / 6), sin(12 * M_PI / 6));
        o.geo_center_calc();
        cout << o;
        double sq2 = o.figure_square_calc();
        cout << "Octagon square: " << sq2 << endl;



        cout << "Hexagon: " << endl;
        Hexagon h(3 * cos(0), 3 * sin(0), 3 * cos(M_PI / 4), 3 * sin(M_PI / 4), 3 * cos(M_PI / 2), 3 * sin(M_PI / 2), 3 * cos(3 * M_PI / 4), 3 * sin(3 * M_PI / 4), 3 * cos(M_PI), 3 * sin(M_PI), 3 * cos(5 * M_PI / 4), 3 * sin(5 * M_PI / 4), 3 * cos(3 * M_PI / 2), 3 * sin(3 * M_PI / 2), 3 * cos(7 * M_PI / 4), 3 * sin(7 * M_PI / 4));
        h.geo_center_calc();
        cout << h;
        double sq3 = h.figure_square_calc();
        cout << "Hexagon square: " << sq3 << endl;



        cout << "________________________Part_number_two___________________________" << endl << endl;


        Figure** figs = new Figure* [FIG];
        
        double total_sq = 0;

        figs[0] = &p;
        figs[1] = &o;
        figs[2] = &h;
        int size = FIG;

        for(int i = 0; i < size; ++i) {
            figs[i]->geo_center_calc();
            double sq = figs[i]->figure_square_calc();
            total_sq += sq;
        }

        cout << "total square: " << total_sq << endl << endl;

        cout << "Input the index of element to remove: ";
        int num;
        cin >> num;
        --num;
        if(num >= 0 && num < size) {
        Figure** figs_new = new Figure*[size - 1];
            int d = 0;
            for(int j = 0; j < size; ++j) {
                if(j ==  num) {
                    d = 1;
                    continue;
                }
                figs_new[j - d] = figs[j];
            }
            --size;
            total_sq = 0;
            for(int i = 0; i < size; ++i) {
                figs_new[i]->geo_center_calc();
                double sq = figs_new[i]->figure_square_calc();
                total_sq += sq;
            }
            cout << "total square: " << total_sq << endl;
            delete[] figs_new;
        }
        else {
            cout << "Invalid index!" << endl;

        }
        delete[] figs;

        }
        catch(...){
            cout << "Invalid input data!" << endl;
        }

    return 0;
}