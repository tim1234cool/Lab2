#include <iostream>
#include "time.hpp"
#include <cassert>

int main(){
    std::cout << "Begin unit test for Time::Time(int hour, int minute)\n";


    {
        Time t1(1, 1);
        TimePart ref = {1, 1, 0};
        assert(t1.time() == ref);

    }    
    {
        Time t2(0, 60);
        TimePart ref = {1, 0, 0};
        assert(t2.time() == ref);
    }
    {
        Time t3(23, 60);
        TimePart ref = {0, 0, 0};
        assert(t3.time() == ref);
    }






    std::cout << "Done testing Time::Time(int hour, int minute)\n";
return 0;
}