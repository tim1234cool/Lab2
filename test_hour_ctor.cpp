#include "time.hpp"
#include <cassert>
#include <iostream>

int main(){
    std::cout << "Begin unit test for Time::Time(int hour)\n";

         
    {
        Time t1(1);
        TimePart ref = {1, 0, 0};
        assert(t1.time() == ref);

    }    
    {
        Time t2(24);
        TimePart ref = {0, 0, 0};
        assert(t2.time() == ref);
    }
    {
        Time t3(26);
        TimePart ref = {2, 0, 0};
        assert(t3.time() == ref);
    }
    

std::cout << "Done testing Time::Time(int hour)\n";
return 0;
} 