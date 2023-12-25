#include <iostream>
#include <map>
#include "allocator.hpp"
#include "queue_container.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::less;
using std::map;

using namespace My_Allocator;


int main() {

    try {
        std::map<int, int, std::less<int>, Allocator<std::pair<const int,int>>> my_map;
        int res = 1;
        for (size_t i = 0; i < 5; ++i) {
            res = 1;
            for (int j = 1; j <= i; ++j) {
            res *= j;
            }
            my_map[i] = res;
        }

        for(const auto& [k,v]: my_map) {
            cout << k << " -> " << v << endl;
        } 
        
        cout << endl;

        cout << "--------------Queue--------------------" << endl; 

        Queue<int, Allocator<int> > queue;      
        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.push(4);
        queue.push(5);

        int s = queue.size();
        cout << s <<endl;
        for (int i = 0; i < s; ++i) {
            queue.pop(); 
        }
        if(s == 0){
            cout << "True" << endl;
        }
        else{
            cout << "False" << endl;
        }
        queue.push(11);
        queue.push(21);
        queue.push(31);
        queue.push(41);
        queue.push(51);
        queue.push(61); 
        queue.push(71); 
        queue.push(81); 
        queue.push(91);
        queue.push(101);    
        for (Queue<int, Allocator<int> >::Iterator i = queue.begin(); i != queue.end(); ++i) {
            cout << *i << endl; 
        } 
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << endl;
    }

    return 0;
}
