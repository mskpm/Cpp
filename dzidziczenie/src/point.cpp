#include "point.hpp"
#include <memory>

using namespace std;

unsigned int point::counter_p = 0;

///////////////////////////////////////////////////////////////////////////
// Constructors
///////////////////////////////////////////////////////////////////////////

point::point() 
{
    ++counter_p;
    // cout << "point()+"
    //      << "(" << this->id << ")";
};

///////////////////////////////////////////////////////////////////////////

point::point(double x, double y):x{x},y{y}
{
    // cout << "point(double x, double y)+"
    //      << "(" << this->id << ")";
}

///////////////////////////////////////////////////////////////////////////

point::point(const point &wzorzec) : x{wzorzec.x}, y{wzorzec.y} //konstruktor kopiujący
{
    // cout << "konstruktor kopiujący+"
    //      << "(" << this->id << ")";
}

///////////////////////////////////////////////////////////////////////////
// Destructor
///////////////////////////////////////////////////////////////////////////

point::~point()
{
    // cout << "~point()-"
    //      << "(" << this->id << ")";
    --counter_p;
}

///////////////////////////////////////////////////////////////////////////
// Overload operators
///////////////////////////////////////////////////////////////////////////

point &point::operator=(const point &wzorzec) //kopiujący operator przypisania
{
    if (this != &wzorzec)
    {
        x = wzorzec.x;
        y = wzorzec.y;
    }
    // cout << "kopiujący operator przypisania+";
    // cout << "(" << this->id << ")";
    return *this;
}

///////////////////////////////////////////////////////////////////////////

point *point::operator+(point el)
{
    --counter_p;
    point *el_new = new point();
    el_new->setX(x + el.getX());
    el_new->setY(y + el.getY());
    // cout << "Operator+"
    //      << "(" << this->id << ")";
    return el_new;
}

///////////////////////////////////////////////////////////////////////////

ostream &operator<<(ostream &ekran, point &obj)
{
    ekran << "<" << obj.id << ">"
          << "(" << obj.getX() << "," 
          << obj.getY() << ")";

    return ekran;
}

///////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////

void point::show()
{
    std::cout << "<" << get_id() << ">" << "(" << this->getX() << "," << this->getY() << ")" << std::endl;
}
