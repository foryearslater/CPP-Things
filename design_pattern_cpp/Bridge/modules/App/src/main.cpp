#include <iostream>
#include <vector>
#include "RefinedShapes.hpp"
#include "ConcreteRenderers.hpp"

int main() 
{
    auto openGLRenderer = std::make_shared<OpenGLRenderer>();
    auto directXRenderer = std::make_shared<DirectXRenderer>();

    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Circle>(10, 20, 5.0f, openGLRenderer));

    shapes.push_back(std::make_unique<Square>(50, 60, 100.0f, directXRenderer));
    
    shapes.push_back(std::make_unique<Square>(30, 40, 25.0f, openGLRenderer));


    for (const auto& shape : shapes) 
    {
        shape->Draw();
    }

    return 0;
}