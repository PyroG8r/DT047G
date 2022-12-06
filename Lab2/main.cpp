// "Shape inheritance", DT047G
// Emil Jons
// main.cpp, 2022-11-27
// "huvudfil för programmet"

#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "RoundRectangle.h"
#include "memory"
#include "vector"

using shape_pointer = std::unique_ptr<Shape>;   //använder unique pointers för att garantera att inte kopiera pointers, samt för minneshantering
void getData(std::vector<shape_pointer>& shapeList);
void getData2(const std::vector<Shape*>& shapes);

int main() {
    std::vector<shape_pointer> shapeList;   // container för alla former
    std::vector<Shape*> shapes;

    Rectangle rectangle(2, 2, "Blue");
    Circle circle(2, "Red");
    Cylinder cylinder(2, 2, "Orange");
    Parallelepiped para(2, 4, 2, "Grey");
    RoundRectangle roundR(2, 4, 2, "Green");


    shapes.push_back(&rectangle);
    shapes.push_back(&cylinder);
    shapeList.push_back(std::make_unique<Rectangle>(rectangle));
    shapeList.push_back(std::make_unique<Circle>(circle));
    shapeList.push_back(std::make_unique<Cylinder>(cylinder));
    shapeList.push_back(std::make_unique<Parallelepiped>(para));
    shapeList.push_back(std::make_unique<RoundRectangle>(roundR));

    getData2(shapes);

    return 0;
}

void getData2(const std::vector<Shape*>& shapes){
    for(const Shape* shape : shapes){
        std::cout <<shape->getColor() << "\n";
        std::cout <<shape->getArea() << "\n";
    }
}

void getData(std::vector<shape_pointer> & shapeList){


    /*
    for(auto& sShape: shapeList){
        auto* circle_p = dynamic_cast<Circle*>(sShape.get());         //problem med att den matchar med föräldern också
        auto* rectangle_p = dynamic_cast<Rectangle*>(sShape.get());
        auto* cylinder_p = dynamic_cast<Cylinder*>(sShape.get());
        auto* rounded_p = dynamic_cast<RoundRectangle*>(sShape.get());
        auto* parallel_p = dynamic_cast<Parallelepiped*>(sShape.get());

        if (cylinder_p){
            std::cout << cylinder_p->getArea() << " " << cylinder_p->getColor() << "\n";
        }
        else if (rounded_p){
            std::cout << rounded_p->getArea() << " " << rounded_p->getColor() << "\n";
        }
        else if (parallel_p){
            std::cout << parallel_p->getArea() << " " << parallel_p->getColor() << "\n";
        }
        else if (circle_p){
            std::cout << circle_p->getArea() << " " << circle_p->getColor() << "\n";
        }
        else if (rectangle_p){
            std::cout << rectangle_p->getArea() << " " << rectangle_p->getColor() << "\n";
        }
    }*/


}