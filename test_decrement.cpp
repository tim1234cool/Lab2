#include <iostream>
#include "time.hpp"
#include <cassert>

int main(){
        std::cout << "Begin unit test for void Time::decrement\n";
    {
        Time t1(0, 0, 1);
        t1.decrement();     
        TimePart ref = {0, 0, 0};
        assert(t1.time() == ref);
    }  
    {
        Time t2(23, 59, 59);
        t2.decrement();
        TimePart ref = {23, 59, 58};
        assert(t2.time() == ref);
    }  
    {
        Time t3(1, 0, 0);
        t3.decrement();
        TimePart ref = {0, 59, 59};
        assert(t3.time() == ref);
    }
    {
        Time t4(0, 0, 0);
        t4.decrement();
        TimePart ref = {23, 59, 59};
        assert(t4.time() == ref);
    }

    std::cout << "Done testing void Time::decrement\n";
    
}