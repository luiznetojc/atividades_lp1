#include "../lib/time.h"
#include <ctime>
#include <sstream>

Time::Time(): hours(0),minutes(0),seconds(0)
{}

void Time::setTime(const std::string t)
{
    std::stringstream stream(t);
    
    char discard; // para descartar as ':' 

    stream >> hours;
    stream >> discard;
    stream >> minutes;
    stream >> discard;
    stream >> seconds;

} 