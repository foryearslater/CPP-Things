#include <iostream>
#include <exception>

class Shape 
{
public:
    virtual ~Shape() {} 
    virtual void draw() 
    { 
        std::cout << "Drawing a generic shape." << std::endl; 
    }
};

class Circle : public Shape 
{
public:
    void draw() override 
    { 
        std::cout << "Drawing a circle." << std::endl; 
    }
    void roll() 
    { 
        std::cout << "The circle is rolling." << std::endl; 
    }
};

class Square : public Shape 
{
public:
    void draw() override 
    { 
       std::cout << "Drawing a square." << std::endl; 
    }
};

void process_shape(Shape* shape) 
{
    shape->draw();
    Circle* circle = dynamic_cast<Circle*>(shape);
    if (circle != nullptr) 
    {
        circle->roll(); 
    }
    else 
    {
        std::cout << "This shape is not a circle." << std::endl;
    }
}

void test2()
{
    Shape* my_circle = new Circle();
    Shape* my_square = new Square();

    process_shape(my_circle);
    std::cout << "---" << std::endl;
    process_shape(my_square); 

    delete my_circle;
    delete my_square;
}