#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>

struct Point
{
    double x;
    double y;

    Point(): x(0), y(0){}
    Point(double x, double y): x(x), y(y){}
    friend std::istream& operator>>(std::istream& in, Point& p);
    friend std::ostream& operator<<(std::ostream& out, Point& p);
/*    Point(int x, int y) : x(x), y(y){}
    Point& operator+(Pont p);
    Point& operator-(Pont p);
    Point& operator*(Pont p); */
    void pointwrite();
};


#endif // POINT_H_INCLUDED
