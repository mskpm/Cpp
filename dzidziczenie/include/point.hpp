#pragma once
#include <iostream>
#include <memory>


class point {
        double x{};
        double y{};
        static unsigned int counter_p;
        const unsigned int id{++counter_p};

    public:

        point();
        point(double, double);

        point(const point &);               //konstruktor kopiujący
        point & operator=(const point &);   //kopiujący operator przypisania

        point(const point &&);              //konstruktor przenoszący

        ~point(); //destruktor
                            
        point & operator=(const point &&);  //przenoszący konstruktor przypisania

        friend std::ostream & operator<<(std::ostream &, point &);

        virtual unsigned int get_id()
        {
            return id; 
        }

        double getY()
        {
            return this->y;
        }

        double getX()
        {
            return this->x;
        }

        virtual void show();

        point* operator+(point);
    
    protected: 
    
        double setY(double _y)
        {
            return y = _y;
        }

        double setX(double _x)
        {
            return x = _x;
        }
        
};
