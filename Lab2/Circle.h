// "Shape inheritance", DT047G
// Emil Jons 
// Circle.h, 2022-11-23
// "Deklaraioner för circle klassen"


#ifndef LAB2_CIRCLE_H
#define LAB2_CIRCLE_H


#include "Shape.h"
#include <cmath>

class Circle : public Shape {
public:
    Circle(double radius, std::string color);
    double getArea() const override;
private:
    double radius;
};


#endif //LAB2_CIRCLE_H
