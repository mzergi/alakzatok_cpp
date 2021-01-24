#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include "shapes.h"
#include "line.h"
#include "point.h"

class Square : public Shapes
{
    Point points[4];
public:
    Square():Shapes()
    {
        for (int i=0;i<4;i++){
            points[i].x=0;
            points[i].y=0;
        }
    }
    Square(Point& c, Point& p);
    friend std::ostream& operator<<(std::ostream& out, Square& sqr);
    friend std::istream& operator>>(std::istream& in, Square& sqr);
    Square& operator=(const Square& sqr);
    bool contained_by_this (Point p0);
    bool contained_by_circle(Point p0, double r);
    void Print()
    {
        for(int i=0;i<4;i++)
        {
            std::cout<<"p"<<i<<": "<<points[i]<<std::endl;
        }
    }
};


#endif // SQUARE_H_INCLUDED
