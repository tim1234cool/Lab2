#include <iostream>
#include "time.hpp"
#include <cassert>

int main(){
        std::cout << "Begin unit test for void Time::increment\n";
    {
        Time t1(0, 0, 0);
        t1.increment();     
        TimePart ref = {0, 0, 1};
        assert(t1.time() == ref);
    }  
    {
        Time t2(1, 1, 59);
        t2.increment();
        TimePart ref = {1, 2, 0};
        assert(t2.time() == ref);
    }  
    {
        Time t3(23, 59, 59);
        t3.increment();
        TimePart ref = {0, 0, 0};
        assert(t3.time() == ref);
    }
    std::cout << "Done testing void Time::increment\n";
    
}