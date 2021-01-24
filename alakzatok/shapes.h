#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED
#include "point.h"

//TÁROLÁS/TÍPUS MEGHATÁROZÁS: if(string=="triangle") array[i]=new Triangles//
class Shapes
{
protected:
    Point center; //középpont
    Point p0; // a pont ami rajta van az alakzaton
public:
    Shapes():center(0,0),p0(0,0){}
    friend std::istream& operator>>(std::istream& in, Shapes& shp);
    friend std::ostream& operator<<(std::ostream& out, Shapes& shp);
    Point& getCenter(){return this->center;}
    void setCenter(Point p){center=p;}
    Point& getp0(){return this->p0;}
    void setp0(Point p) {p0=p;};
    virtual bool contained_by_this (Point p0)=0;
    virtual bool contained_by_circle(Point p0, double r)=0;
    virtual void Print()=0;
};


#endif // SHAPES_H_INCLUDED
