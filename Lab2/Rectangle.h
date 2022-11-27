// "Shape inheritance", DT047G
// Emil Jons 
// Rectangle.h, 2022-11-23
// "Deklarationer för rectangle klassen"


#ifndef LAB2_RECTANGLE_H
#define LAB2_RECTANGLE_H


#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double width, double height, std::string color);
    double getArea() const override;
protected:
    double width;
    double height;
};


#endif //LAB2_RECTANGLE_H
