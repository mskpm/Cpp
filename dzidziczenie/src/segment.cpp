#include "segment.hpp"

unsigned int segment::counter_s = 0;   //segments counter

///////////////////////////////////////////////////////////////////////////
// Constructors
///////////////////////////////////////////////////////////////////////////

segment::segment(double x_1, double y_1, double x_2, double y_2)
                                                    :x1{x_1},y1{y_1},x2{x_2},y2{y_2}
{
    ++counter_s;
}

///////////////////////////////////////////////////////////////////////////

segment::segment(point a, point b) : start{a}, end{b} 
{ 
    x1 = start.getX();
    y1 = start.getY(); 
    x2 = end.getX();
    y2 = end.getY();   
}

///////////////////////////////////////////////////////////////////////////

//segment::segment(const segment &wzorzec) : start{point(wzorzec.start)}, end{point(wzorzec.end)}{}
//segment::segment(const segment &wzorzec) : segment(point(wzorzec.start), point(wzorzec.end)){}

///////////////////////////////////////////////////////////////////////////

segment::segment(const segment &wzorzec) : segment(wzorzec.start, wzorzec.end)
{
    ++counter_s;
}

///////////////////////////////////////////////////////////////////////////

segment::segment(double a, double b) : x1{},y1{},x2{a},y2{b} 
{++counter_s;}

segment::~segment()
{
    --counter_s;
}

///////////////////////////////////////////////////////////////////////////
// Overload operators
///////////////////////////////////////////////////////////////////////////

std::ostream & operator<<(std::ostream & ekran, segment & obj)
{
    ekran   << "<" << obj.id << ">" 
            << "|" << obj.x2 - obj.x1 << ","
            << obj.y2 - obj.y1 << "|";
    return ekran;
}

///////////////////////////////////////////////////////////////////////////
segment &segment::operator=(segment &wzorzec)
{
    if (this != &wzorzec)
    {
        x1=wzorzec.x1;
        y1=wzorzec.y1;
        x2=wzorzec.x2;
        y2=wzorzec.y2;
        start = wzorzec.start;
        end = wzorzec.end;
    }
    // cout << "kopiujący operator przypisania+";
    // cout << "(" << this->id << ")";
    return *this;
}

///////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////

double segment::dim()
{
    return sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}

///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////

void segment::show()
{
    std::cout <<"<" << get_id() << ">" << "|" << x2 - x1 << ","
                     << y2 - y1 << "|";
}
