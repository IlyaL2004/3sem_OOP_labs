#include "pentagon.h"
#include "Array.h"
#include "octagon.h"
#include "hexagon.h"
using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using dbl_point = pair<double, double>;
using int_point = pair<int, int>;

int main()
{   
    try{
    cout << "Pentagon" << endl;
    Pentagon<double> pen;
    pen << cout;
    pair<double, double> p1(2, 0);
    pair<double, double> p2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5));
    pair<double, double> p3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5));
    pair<double, double> p4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5));
    pair<double, double> p5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon<double> pen1(p1, p2, p3, p4, p5);
    pen1 << cout;
    pair<double, double> p(1, 0);
    p = pen1.geom_centr_calc();
    cout << p.first << ", "<< p.second << endl;
    double sq = pen1.figure_square_calc();
    cout << sq << endl;
    Pentagon<double> pen11;
    pen11 = pen1;
    pen11 << cout << endl;
    bool b = (pen1 == pen11);
    cout << b << endl;

    cout << "Octagon" << endl;

    Octagon<double> oct;
    oct << cout;
    pair<double, double> o1(cos(2 * M_PI / 6), sin(2 * M_PI / 6));
    pair<double, double> o2(cos(4 * M_PI / 6), sin(4 * M_PI / 6));
    pair<double, double> o3(cos(6 * M_PI / 6), sin(6 * M_PI / 6));
    pair<double, double> o4(cos(8 * M_PI / 6), sin(8 * M_PI / 6));
    pair<double, double> o5(cos(10 * M_PI / 6), sin(10 * M_PI / 6));
    pair<double, double> o6(cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    Octagon<double> oct1(o1, o2, o3, o4, o5, o6);
    oct1 << cout;
    pair<double, double> o(1, 0);
    o = oct1.geom_centr_calc();
    cout << o.first << ", "<< o.second << endl;
    double sq1 =oct1.figure_square_calc();
    cout << sq1 << endl;
    Octagon<double> oct11;
    oct11 = oct1;
    oct11 << cout << endl;
    bool b1 = (oct1 == oct11);
    cout << b1 << endl;

    cout << "Hexagon" << endl;

    Hexagon<double> hex;
    hex << cout;
    pair<double, double> h1(3 * cos(0), 3 * sin(0));
    pair<double, double> h2(3 * cos(M_PI / 4), 3 * sin(M_PI / 4));
    pair<double, double> h3(3 * cos(M_PI / 2), 3 * sin(M_PI / 2));
    pair<double, double> h4(3 * cos(3 * M_PI / 4), 3 * sin(3 * M_PI / 4));
    pair<double, double> h5(3 * cos(M_PI), 3 * sin(M_PI));
    pair<double, double> h6(3 * cos(5 * M_PI / 4), 3 * sin(5 * M_PI / 4));
    pair<double, double> h7(3 * cos(3 * M_PI / 2), 3 * sin(3 * M_PI / 2));
    pair<double, double> h8(3 * cos(7 * M_PI / 4), 3 * sin(7 * M_PI / 4));
    Hexagon<double> hex1(h1, h2, h3, h4, h5, h6, h7, h8);
    hex1 << cout;
    pair<double, double> h(1, 0);
    h = hex1.geom_centr_calc();
    cout << h.first << ", "<< h.second << endl;
    double sq11 =hex1.figure_square_calc();
    cout << sq11 << endl;
    Hexagon<double> hex11;
    hex11 = hex1;
    hex11 << cout << endl;
    bool b11 = (hex1 == hex11);
    cout << b11 << endl;

    cout << "-----------------------------------------";
    shared_ptr<Figure<double> > Pentagon_ptr(make_shared<Pentagon<double>>(p1, p2, p3, p4, p5));
    (*Pentagon_ptr) << cout;
    
    Array<shared_ptr<Figure<double> > > array{
    make_shared<Pentagon<double>>(p1, p2, p3, p4, p5), 
    make_shared<Pentagon<double>>(p1, p2, p3, p4, p5),
    make_shared<Pentagon<double>>(p1, p2, p3, p4, p5)
    };
        

    for(size_t i = 0;i < array.size(); ++i) {
        *(array[i]) << cout << endl;
    }

    double square = 0;
    for(size_t i = 0; i < array.size(); ++i) {
        square += array[i]->figure_square_calc();
    }
    cout << square << endl;

    Array<shared_ptr<Figure<double> > > array11;

    /////////////copy///////////

    array11 = array;
    
    for(size_t i = 0;i < array11.size(); ++i) {
        *(array11[i]) << cout << endl;
    }
    
    cout << "Input the index of element to remove: ";
    int num;
    cin >> num;
    array.del_ind(num);
    for(size_t i = 0;i < array.size(); ++i) {
        *(array[i]) << cout << endl;
    }
    }catch(exception &ex){
                cerr << "Exception in calculating: " << ex.what() << endl;
            }
}
