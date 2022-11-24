#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "RoundRectangle.h"

int main() {
    Rectangle rectangle(2, 2, "Blue");
    std::cout << rectangle.getArea() << " " << rectangle.getColor() << "\n";
    Circle circle(2, "Red");
    std::cout << circle.getArea() << " " << circle.getColor() << "\n";
    Cylinder cylinder(2, 2, "Orange");
    std::cout << cylinder.getArea() << " " << cylinder.getColor() << "\n";
    Parallelepiped para(2, 4, 2, "Grey");
    std::cout << para.getArea() << " " << para.getColor() << "\n";
    RoundRectangle roundR(2, 4, 2, "Green");
    std::cout << roundR.getArea() << " " << roundR.getColor() << "\n";

    return 0;
}
