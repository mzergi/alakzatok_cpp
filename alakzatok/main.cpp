#include <iostream>
#include <fstream>
#include <cstring>
#include "shapes.h"
#include "point.h"
#include "triangle.h"
#include "line.h"
#include "square.h"


int main()
{
   try{
    Square test;
    std::cin>>test;
    std::cout<<test;
    std::ifstream myfile;
    myfile.open("shapes.txt");
    size_t siz=0;
    if(myfile.is_open())
    {
        std::string line;
        while(std::getline(myfile, line)) //GETLINE NEM PONTOS, ÁT KELL ÍRNI MAJD MÁSRA!!!!
        {
            siz++;
        }
    }
    myfile.close();
    myfile.open("shapes.txt");
    siz/=3;
    size_t i=0;
    Shapes* shapes[siz];
    Triangle tmptr;
    Square tmpsq;
    if(myfile.is_open())
    {
        std::string line;
        while(std::getline(myfile, line))
        {
            if(strcmp(line.c_str(),"tri")==0)
            {
                myfile>>tmptr;
                if(!tmptr.contained_by_circle(Point(0,0),1.0))
                shapes[i]=new Triangle(tmptr.getCenter(),tmptr.getp0());
                i++;
            }
            else if(strcmp(line.c_str(),"sqr")==0)
            {
               myfile>>tmpsq;
                if(!tmpsq.contained_by_circle(Point(0,0),1.0))
                shapes[i]=new Square(tmpsq.getCenter(),tmpsq.getp0());
                i++;
            }

        }
    }
    for(size_t j=0;j<i;j++)
        shapes[j]->Print();
    }
    catch(const char* e)
    {
        std::cout<< e <<std::endl;
    }



/*
    Point p;
    std::cout<< "ird be a szamokat: ";
    std::cin>>p;
    std::cout<<p;
    Triangle tri;
    std::cout<< "Center, egy pontja: ";
    std::cin>>tri;
    std::cout<<tri;
    Line line(Point(0,0),Point(1,1));
    line.rotateline(90);
    Square sqr;
    std::cout<<"Center, egy pontja: ";
    std::cin>>sqr;
    std::cout<<sqr;

    bool ctby=tri.contained_by_circle(Point(0,0),1);
*/
}
