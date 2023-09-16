#include "max_val.h"

int max_val(int devider, int bound){
    int element_search = 1;
    int iterator = 2;

    if (devider > 0 && bound > 0){
    
        if (bound < devider)
            return 0;

        else if ((element_search == devider) || (devider == bound))
            return bound;
    
        else if ((devider < bound) && (iterator*devider > bound))
            return devider; 

        while((iterator * devider) <= bound){
            element_search = iterator * devider;
            iterator ++; 
        }

        return element_search;
    }
    
    else{    
        
        return -1; // если некорректный ввод
    }

}