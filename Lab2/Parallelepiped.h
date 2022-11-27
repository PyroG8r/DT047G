// "Shape inheritance", DT047G
// Emil Jons 
// Parallelepiped.h, 2022-11-24
// "Deklarationer för parallelepiped klassen"


#ifndef LAB2_PARALLELEPIPED_H
#define LAB2_PARALLELEPIPED_H

#include "Rectangle.h"
class Parallelepiped : public Rectangle {
public:
    Parallelepiped(double width, double height, double depth, std::string color);
    double getArea() const override;
private:
    double depth;
};


#endif //LAB2_PARALLELEPIPED_H
