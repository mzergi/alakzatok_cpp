#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include "shapes.h"

class Triangle: public Shapes
{
    Point p1;
    Point p2;
    Point p3;
public:
    Triangle():Shapes(),p1(0,0),p2(0,0),p3(0,0){}
    Triangle(Point& c, Point& p);
    friend std::ostream& operator<<(std::ostream& out, Triangle& tri);
    friend std::istream& operator>>(std::istream& in, Triangle& tri);
    Triangle& operator=(const Triangle& tri);
    bool contained_by_this (Point p0);
    bool contained_by_circle(Point p0, double r);
    void Print()
    {
        std::cout<<"p1: "<<p1<<"p2: "<<p2<<"p3: "<<p3<<std::endl;
    }
};

#endif // TRIANGLE_H_INCLUDED
