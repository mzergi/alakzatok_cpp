#include "point.h"
#include "shapes.h"
#include "triangle.h"
#include "line.h"
#include <iostream>
#include <math.h>

Triangle::Triangle(Point& c, Point& p)
{
    setCenter(c);
    setp0(p);
    double r=sqrt((c.x-p.x)*(c.x-p.x)+(c.y-p.y)*(c.y-p.y));
    p1=p;
    Line calcline(p, c); //AZ ELSO KOORDINATAT JEGYZI MEG
    calcline.rotateline(30);
    p2=calcline.intersects_circle(r,c,p);

    calcline.rotateline(-30);
    calcline.rotateline(-30);
    p3=calcline.intersects_circle(r,c,p);

}
std::ostream& operator<<(std::ostream& out, Triangle& tri)
{
    return out<<"p1: "<<tri.p1<<" p2: "<<tri.p2<<" p3: "<<tri.p3<<std::endl;
}
bool Triangle::contained_by_this (Point p0)
{
    double maxx, minx, miny,maxy;
    maxx=minx=p1.x;
    miny=maxy=p1.y;
    if(p2.x>maxx)
        maxx=p2.x;
    if(p2.x<minx)
        minx=p2.x;
    if(p2.y>maxy)
        maxy=p2.y;
    if(p2.y<miny)
        miny=p2.y;
    if(p3.x>maxx)
        maxx=p3.x;
    if(p3.x<minx)
        minx=p3.x;
    if(p3.y>maxy)
        maxy=p3.y;
    if(p3.y<miny)
        miny=p3.y;

    if(p0.x<maxx&&p0.x>minx&&p0.y<maxy&&p0.y>miny)
        return true;
    else
        return false;
}
bool Triangle::contained_by_circle(Point p0, double r)
{
    double u=p0.x;
    double v=p0.y;
    if((((p1.x-u)*(p1.x-u))+((p1.y-v)*(p1.y-v)))<(r*r))
        return true;
    if((((p2.x-u)*(p2.x-u))+((p2.y-v)*(p2.y-v)))<(r*r))
        return true;
    if((((p3.x-u)*(p3.x-u))+((p3.y-v)*(p3.y-v)))<(r*r))
        return true;
    return false;
}
Triangle& Triangle::operator=(const Triangle& tri)
{
    center=tri.center;
    p0=tri.p0;
    p1=tri.p1;
    p2=tri.p2;
    p3=tri.p3;
    return *this;
}
std::istream& operator>>(std::istream& in, Triangle& tri)
{
    Point cp,pnull;
    in>>cp>>pnull;
    tri.setCenter(cp);
    tri.setp0(pnull);
    Triangle tmp(cp,pnull);
    tri=tmp;
    return in;
}
