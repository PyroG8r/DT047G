// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#ifndef LAB2_SHAPE_H
#define LAB2_SHAPE_H


#include <string>

class Shape {
public:
    explicit Shape(std::string color);
    virtual std::string getColor();
    virtual double getArea() = 0;

private:
    std::string color;
};


#endif //LAB2_SHAPE_H
