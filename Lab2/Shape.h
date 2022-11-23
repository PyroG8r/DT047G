// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-11-23
// "kortfattat vad filen innehåller"


#ifndef LAB2_SHAPE_H
#define LAB2_SHAPE_H


#include <string>

class Shape {
public:
    Shape() = delete;
    virtual std::string &getColor() const;
    virtual float &getArea() const;
private:
    std::string color;
    float width;
    float height;
};


#endif //LAB2_SHAPE_H
