#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "point.h"
#include <math.h>

class Line
{
    double m;
    double b;
    Point p0;
public:
    Line(Point x1, Point x2);
    void rotateline(double deg);
    Point intersects_circle(double r,Point cp,Point excluded);
};

#endif // LINE_H_INCLUDED
