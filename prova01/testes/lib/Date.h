#ifndef MACRO_DATE
#define MACRO_DATE
 #include <string>

struct Date
{
    Date();
    unsigned days;
    unsigned months;
    unsigned years;
    
    void setDate(const std::string d);
};



#endif // !1