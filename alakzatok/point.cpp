#include "point.h"
#include <iostream>


std::istream& operator>>(std::istream& in, Point& p)
{
    in >> p.x;
    in>> p.y;
    return in;
}
std::ostream& operator<<(std::ostream& out, Point& p)
{
    return out<<"x:"<<p.x<<" y:"<<p.y<<std::endl;
}
void Point::pointwrite()
{
    std::cout<< x << y <<std::endl;
}
