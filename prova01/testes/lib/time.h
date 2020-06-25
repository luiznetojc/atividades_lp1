#ifndef MACRO_time
#define MACRO_time
#include <string>

struct Time
{
    Time();
    unsigned hours;
    unsigned minutes;
    unsigned seconds;
    
    void setTime(const std::string t);
};



#endif // MACRO



