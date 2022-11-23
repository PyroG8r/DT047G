// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#ifndef LAB2_CIRCLE_H
#define LAB2_CIRCLE_H


#include "Shape.h"

class Circle : Shape {
public:
    std::string &getColor() const;
    float &getArea() const;
private:
};


#endif //LAB2_CIRCLE_H
