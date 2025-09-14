#include <iostream>
#include "time.hpp"
#include <cassert>

int main(){
        std::cout << "Begin unit test for void Time::add\n";
    {
        Time t1(0);
        t1.add(1);     
        TimePart ref = {0, 0, 1};
        assert(t1.time() == ref);
    }  
    {
        Time t2(0);
        t2.add(60);
        TimePart ref = {0, 1, 0};
        assert(t2.time() == ref);
    } 
    {
        Time t3(0);
        t3.add(3601);
        TimePart ref = {1, 0, 1};        
        assert(t3.time() == ref);
    }
    {
        Time t4(0);
        t4.add(3661);
        TimePart ref = {1, 1, 1};
        assert(t4.time() == ref);
    }
    std::cout << "Done testing void Time::add\n";
    
}