#include "RefinedShapes.hpp"

Circle::Circle(float x, float y, float radius, std::shared_ptr<Renderer> renderer)
    : Shape(renderer), m_x(x), m_y(y), m_radius(radius) {}

void Circle::Draw() const 
{
    if (m_renderer) 
    {
        m_renderer->DrawCircle(m_x, m_y, m_radius);
    }
}


Square::Square(float x, float y, float side, std::shared_ptr<Renderer> renderer)
    : Shape(renderer), m_x(x), m_y(y), m_side(side) {}

void Square::Draw() const
{
    if (m_renderer) 
    {
        m_renderer->DrawSquare(m_x, m_y, m_side);
    }
}