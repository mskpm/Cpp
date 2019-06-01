#include "vector.hpp"
#include "point.hpp"
#include <memory>

unsigned int vector::counter_v = 0;

///////////////////////////////////////////////////////////////////////////
// Constructors
///////////////////////////////////////////////////////////////////////////

vector::vector()
{
    ++counter_v;
}

///////////////////////////////////////////////////////////////////////////

vector::vector(double x, double y) :x{x},y{y}
{}

///////////////////////////////////////////////////////////////////////////

vector::vector(const vector &obj) : point{obj}          //konstruktor kopiujący
{
    x=obj.x;
    y=obj.y;
}

///////////////////////////////////////////////////////////////////////////

vector::vector(point a, point b)
{
    ++counter_v;
    this->x=b.getX()-a.getX();
    this->y=b.getY()-a.getY();
}
///////////////////////////////////////////////////////////////////////////

//vector::vector(double x1, double y1, double x2, double y2) : vector(x2-x1, y2-y1){};
vector::vector(double x1, double y1, double x2, double y2) : vector(point{x1,y1}, point{x2,y2})
{}

///////////////////////////////////////////////////////////////////////////

vector::vector(segment obj)
{
    x=obj.getX();
    y=obj.getY();
}

///////////////////////////////////////////////////////////////////////////

vector::vector(vector *obj)
{
    x=obj->x;
    y=obj->y;
}

///////////////////////////////////////////////////////////////////////////
// Destructor
///////////////////////////////////////////////////////////////////////////

vector::~vector() 
{
    --counter_v;
}

///////////////////////////////////////////////////////////////////////////
// Overload operators
///////////////////////////////////////////////////////////////////////////

std::ostream & operator<<(std::ostream & ekran, vector & obj)
{
    ekran   << "<" << obj.id << ">" 
            << "[" << obj.getX() 
            << "," << obj.getY() << "]";
    return ekran;
}

///////////////////////////////////////////////////////////////////////////

vector* vector::operator+(vector el)
{
    --counter_v;
    
    vector *el_new = new vector();
    //std::unique_ptr<vector> el_new(new vector());
    el_new->setX(this->x + el.getX());
    el_new->setY(this->y + el.getY());
    // cout << "Operator+"
    //      << "(" << this->id << ")";
    return el_new;
}

///////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////

double vector::getAngleDeg()
{
    double degrees = std::atan2(getY(), getX()) * 180 / M_PI;
    if (degrees > 90)
    {
        degrees = 450 - degrees;
    }
    else
    {
        degrees = 90 - degrees;
    }

    return degrees;
}
///////////////////////////////////////////////////////////////////////////

double vector::getAngle2vectors(vector z)
{
    double degrees = acosl(((z.x * x) + (z.y * y)) / (getMagnitude() * z.getMagnitude())) * 180 / M_PI;
    return degrees;
}

///////////////////////////////////////////////////////////////////////////

void vector::show()
{
    std::cout << "vector[" << this->getX() << "," << this->getY() << "]" << std::endl;
}

///////////////////////////////////////////////////////////////////////////

void vector::show(vector *u)
{
    std::cout << "vector[" << u->getX() << "," << u->getY() << "]" << std::endl;
}

///////////////////////////////////////////////////////////////////////////

