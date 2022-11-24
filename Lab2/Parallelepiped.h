// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-24
// "kortfattat vad filen innehåller"


#ifndef LAB2_PARALLELEPIPED_H
#define LAB2_PARALLELEPIPED_H

#include "Rectangle.h"
class Parallelepiped : Rectangle {
public:
    Parallelepiped(double width, double height, double depth, std::string color);
    std::string getColor();
    double getArea();
private:
    double depth;
};


#endif //LAB2_PARALLELEPIPED_H
