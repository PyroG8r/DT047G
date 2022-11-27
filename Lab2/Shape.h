// "Shape inheritance", DT047G
// Emil Jons 
// Shape.h, 2022-11-23
// "Deklarationer för shape klassen"


#ifndef LAB2_SHAPE_H
#define LAB2_SHAPE_H

#include <string>

class Shape {
public:
    explicit Shape(std::string color);  // undviker implicit typomvandling
    virtual ~Shape() = default;
    virtual double getArea() const = 0; // pure virtual
    std::string getColor() const;

private:
    std::string color;
};

#endif //LAB2_SHAPE_H
