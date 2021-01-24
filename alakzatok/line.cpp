#include "line.h"

Line::Line(Point x1, Point x2)
{
    m=(x2.y-x1.y)/(x2.x-x1.x);
    b=x2.y-(m*x2.x);
    p0=x1;
}
void Line::rotateline(double deg)
{
    double addeg=((deg*3.14159265359)/180);
    double olddeg=atan(m);
    double newdeg=addeg+olddeg;
    m=tan(newdeg);
    b=p0.y-(m*p0.x);
}
Point Line::intersects_circle(double r, Point cp, Point excluded)
{
    double i=cp.x;
    double j=cp.y;

   /* if(m<-9999) //y-al párhuzamos kezelését még meg kell helyesen oldani negatívra(?)
    {
        double A,B,C;
        Line temp(cp,p0);
        temp.m=-temp.m;
        temp.b=p0.y-(temp.m*p0.x);
        A=(temp.m*temp.m)+1.0;
        B=(-2.0*i)-(2.0*temp.m*j)+(2.0*temp.m*temp.b);
        C=(i*i)+(j*j)+(temp.b*temp.b)-(r*r)-(2.0*temp.b*j);
        if(((B*B)-(4.0*A*C))<=0)
            throw "Nincs masodik megoldas!";
        Point sol1;
        Point sol2;
        sol1.x=(-B+sqrt((B*B)-(4.0*A*C)))/(2.0*A);
        sol2.x=(-B-sqrt((B*B)-(4.0*A*C)))/(2.0*A);
        sol1.y=temp.m*sol1.x+temp.b;
        sol2.y=temp.m*sol2.x+temp.b;
        if(sol1.x==excluded.x)
            return sol1;
        else if(sol2.x==excluded.x)
            return sol2;

    }
    else
    {*/
        double A,B,C; //valamiért ha y-al párhuzamos az egyenes és a double-hiba miatt pl. +9999999 a meredekség akkor pontos, -99999-el pontatlan
        A=(m*m)+1.0;
        B=(-2.0*i)-(2.0*m*j)+(2.0*m*b);
        C=(i*i)+(j*j)+(b*b)-(r*r)-(2.0*b*j);
        if(((B*B)-(4.0*A*C))<=0)
            throw "Nincs masodik megoldas!";
        Point sol1;
        Point sol2;
        sol1.x=(-B+sqrt((B*B)-(4.0*A*C)))/(2.0*A);
        sol2.x=(-B-sqrt((B*B)-(4.0*A*C)))/(2.0*A);
        sol1.y=m*sol1.x+b;
        sol2.y=m*sol2.x+b;
        if(sol1.x!=excluded.x&&sol1.y!=excluded.y)
            return sol1;
        else
            return sol2;
    //}

}
