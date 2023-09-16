#include <iostream>
#include "max_val.h"

using namespace std;

int main(){
    int N, devider, bound;
    cin >> devider >> bound;
       
    N = max_val(devider, bound);

    cout << N << '\n';
    
    return 0;
}
