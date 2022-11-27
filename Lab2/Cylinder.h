// "Shape inheritance", DT047G
// Emil Jons 
// Cylinder.h, 2022-11-24
// "Deklarationer för cylinder klassen"


#ifndef LAB2_CYLINDER_H
#define LAB2_CYLINDER_H

#include "Circle.h"

class Cylinder : public Circle {
public:
    Cylinder(double radius, double height, std::string color);
    double getArea() const override;
private:
    double height;
};


#endif //LAB2_CYLINDER_H
