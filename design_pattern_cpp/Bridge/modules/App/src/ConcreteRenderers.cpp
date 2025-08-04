#include "ConcreteRenderers.hpp"

void OpenGLRenderer::DrawCircle(float x, float y, float radius) const 
{
    std::cout << "OpenGL: Drawing a circle at (" << x << ", " << y << ") with radius " << radius << "." << std::endl;
}

void OpenGLRenderer::DrawSquare(float x, float y, float side) const 
{
    std::cout << "OpenGL: Drawing a square at (" << x << ", " << y << ") with side " << side << "." << std::endl;
}


void DirectXRenderer::DrawCircle(float x, float y, float radius) const 
{
    std::cout << "DirectX: Drawing a circle at (" << x << ", " << y << ") with radius " << radius << "." << std::endl;
}

void DirectXRenderer::DrawSquare(float x, float y, float side) const 
{
    std::cout << "DirectX: Drawing a square at (" << x << ", " << y << ") with side " << side << "." << std::endl;
}