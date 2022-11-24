// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-24
// "kortfattat vad filen innehåller"


#ifndef LAB2_CYLINDER_H
#define LAB2_CYLINDER_H

#include "Circle.h"

class Cylinder : Circle {
public:
    Cylinder(double radius, double height, std::string color);
    std::string getColor();
    double getArea();
private:
    double height;
};


#endif //LAB2_CYLINDER_H
