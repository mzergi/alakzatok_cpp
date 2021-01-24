#include "square.h"
#include "point.h"
#include "shapes.h"
#include "line.h"
#include <iostream>
#include <math.h>

Square::Square(Point& c, Point& p)
{
    setCenter(c);
    setp0(p);
    double r=sqrt((c.x-p.x)*(c.x-p.x)+(c.y-p.y)*(c.y-p.y));
    points[0]=p;
    Line calcline(p, c); //AZ ELSO KOORDINATAT JEGYZI MEG
    calcline.rotateline(-45);
    points[1]=calcline.intersects_circle(r,c,p);

    calcline.rotateline(45);

    points[2]=calcline.intersects_circle(r,c,p);

    calcline.rotateline(45);
    points[3]=calcline.intersects_circle(r,c,p);

}
std::ostream& operator<<(std::ostream& out, Square& sqr)
{
    return out<<"p1: " <<sqr.points[0]<< "p2: "<<sqr.points[1]<<"p3: "<<sqr.points[2]<<"p4: "<<sqr.points[3]<<std::endl;
}
Square& Square::operator=(const Square& sqr)
{
    for(int i=0; i<4; i++)
    {
        this->points[i]=sqr.points[i];
    }
    return *this;
}
std::istream& operator>>(std::istream& in, Square& sqr)
{
    Point cp,pnull;
    in>>cp>>pnull;
    sqr.setCenter(cp);
    sqr.setp0(pnull);
    Square tmp(cp,pnull);
    sqr=tmp;
    return in;
}

bool Square::contained_by_this (Point p0)
{
    double maxx, minx, miny,maxy;
    maxx=minx=points[0].x;
    miny=maxy=points[0].y;
    for (int i=1; i<4; i++)
    {
        if(points[i].x>maxx)
            maxx=points[i].x;
        if(points[i].x<minx)
            minx=points[i].x;
        if(points[i].y>maxy)
            maxy=points[i].y;
        if(points[i].y<miny)
            miny=points[i].y;
    }
    if(p0.x<maxx&&p0.x>minx&&p0.y<maxy&&p0.y>miny)
        return true;
    else
        return false;
}
bool Square::contained_by_circle(Point p0, double r)
{
    double u=p0.x;
    double v=p0.y;
    for(int i=0; i<4; i++)
    {
        if((((points[i].x-u)*(points[i].x-u))+((points[i].y-v)*(points[i].y-v)))<(r*r))
            return true;
    }
    return false;
}
