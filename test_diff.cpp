#include <iostream>
#include "time.hpp"
#include <cassert>

int main(){
        std::cout << "Begin unit test for void Time::diff\n";
    {
        Time t1(1, 0, 0);
        Time t2(0, 0, 0);
        int result = t1.diff(t2);
        assert(result == 3600);
    }  
    {
        Time t1(0, 30, 0);
        Time t2(0, 45, 0);
        int result = t1.diff(t2);
        assert(result == -900);
    } 
    {
        Time t1(2, 15, 30);
        Time t2(1, 45, 15);
        int result = t1.diff(t2);
        assert(result == 1815);
    }
    {
        Time t1(0, 0, 0);
        Time t2(0, 0, 0);
        int result = t1.diff(t2);
        assert(result == 0);
    }
    std::cout << "Done testing void Time::diff\n";
    
}