#include "../lib/Date.h"
#include <ctime>
#include <sstream>

Date::Date(): days(0),months(0),years(0)
{}

void Date::setDate(const std::string d)
{
    std::stringstream stream(d);
    
    char discard; // para descartar as '/' 

    stream >> days;
    stream >> discard;
    stream >> months;
    stream >> discard;
    stream >> years;

} 