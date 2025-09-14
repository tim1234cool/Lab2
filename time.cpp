// John Sipahioglu
// Kent State University - Computer Science 2 - Lab 2
// time.cpp
// write the implementation of class Time here

#include "time.hpp"


bool TimePart::operator==(const TimePart &rhs) {
    return hour == rhs.hour && minute == rhs.minute && second == rhs.second;
}

std::ostream& operator<<(std::ostream &out, const TimePart &tp) {
    out << std::setfill('0') << std::setw(2) << tp.hour << ":";
    out << std::setfill('0') << std::setw(2) << tp.minute << ":";
    out << std::setfill('0') << std::setw(2) << tp.second;
    return out;
}

Time::Time() {
    _time.hour = 0;
    _time.minute = 0;
    _time.second = 0;
}

Time::Time(int hour) {    
    _time.minute = 0;
    _time.second = 0; 

 if (hour < 0){
        return;
    }    

    hour = hour % 24;
    _time.hour = hour;
}
   

Time::Time(int hour, int minute) {    
    _time.second = 0;
    

    if (minute < 0 || hour < 0) {
        return;
    }
    hour += minute/60;
    minute = minute % 60; 

    hour = hour % 24;

    _time.hour = hour;
    _time.minute = minute;
    
}
Time::Time(int hour, int minute, int second) {
    if (minute < 0 || hour < 0 || second < 0) {
        return;
    }
    minute += second/60;
    second = second % 60;

    hour += minute/60;
    minute = minute % 60;

    hour = hour % 24;

    _time.hour = hour;
    _time.minute = minute;
    _time.second = second;
}
void Time::increment(){
     
    _time.second++;   
    
    if (_time.second >= 60){        
        _time.second = 0;
        _time.minute++;
    }
    if (_time.minute >= 60){
        _time.minute = 0;
        _time.hour++;
    }
    if (_time.hour >= 24){
        _time.hour = 0;
    }

}
void Time::decrement(){
    _time.second--;   
    
    if (_time.second < 0){       
        _time.minute--;
        _time.second = 59;
    }
    if (_time.minute < 0){
        _time.hour--;
        _time.minute = 59;
    }
    if (_time.hour < 0){
        _time.hour = 23;
        _time.minute = 59;
        _time.second = 59;
    }
}

void Time::add(int seconds){

    if (seconds < 0){
        return;
    }
        _time.second += seconds;

    if (_time.second > 59){
        _time.minute += _time.second / 60;
        _time.second %= 60;
    }
    if (_time.minute > 59){
        _time.hour += _time.minute / 60;
        _time.minute %= 60; 
    }
    
    _time.hour %= 24;
}

// for this one canvas has the parameters as (const Time &sub)
// but that doesnt match the header file and gives an error
// we were also told not to touch the parameters so I wont?

int Time::diff(Time sub){
    int thisInSeconds = _time.hour * 3600 + _time.minute * 60 + _time.second;
    int subInSeconds  = sub._time.hour * 3600 + sub._time.minute * 60 + sub._time.second;
    return thisInSeconds - subInSeconds;
}