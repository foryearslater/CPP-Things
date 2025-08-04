/**
 * @file RefinedShapes.hpp
 * @author nichenglong
 * @brief 定义了精确的形状实现，如圆形和正方形
 * @version 0.1
 * @date 2025-08-04
 */

#pragma once
#include "Shape.hpp"

/**
 * @class Circle
 * @brief 精确抽象：表示一个圆形。
 *
 * @detail 继承自 Shape，并实现了 draw() 方法来绘制自己。
 */

class Circle : public Shape
{
public:

    Circle(float x, float y, float radius, std::shared_ptr<Renderer> renderer);

    void Draw() const override;

private:
    float m_x, m_y, m_radius; 
};

/**
 * @class Square
 * @brief 精确抽象：表示一个正方形。
 * @detail 继承自 Shape，并实现了 draw() 方法来绘制自己。
 */

class Square : public Shape
{
public:

    Square(float x, float y, float side, std::shared_ptr<Renderer> renderer);

    void Draw() const override;

private:
    float m_x, m_y, m_side;
};