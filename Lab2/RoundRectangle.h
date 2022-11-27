// "Shape inheritance", DT047G
// Emil Jons 
// RoundedRectangle.h, 2022-11-24
// "Deklarationer för roundedrectangle klassen"


#ifndef LAB2_ROUNDRECTANGLE_H
#define LAB2_ROUNDRECTANGLE_H

#include "Rectangle.h"
#include <cmath>


class RoundRectangle : public Rectangle {
public:
    RoundRectangle(double width, double height, double radius, std::string color);
    double getArea() const override;
private:
    double radius;
};


#endif //LAB2_ROUNDRECTANGLE_H
