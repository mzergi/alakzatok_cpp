#include "shapes.h"
#include <iostream>

std::istream& operator>>(std::istream& in, Shapes& shp)
{
    in>>shp.center;
    in>>shp.p0;
    return in;
}
std::ostream& operator<<(std::ostream& out, Shapes& shp)
{
    return out<<"center: "<<shp.center<<"egy pontja: "<<shp.p0<<std::endl;
}

