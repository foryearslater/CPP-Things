/**
 * @file Renderer.hpp
 * @author nichenglong
 * @brief 定义了实现的接口，即渲染器
 * @version 0.1
 * @date 2025-08-04
 */
#pragma once

/**
 * @class Renderer
 * @brief 实现接口：定义了所有具体渲染器必须实现的底层绘制操作
 * @detail Shape 类将通过这个接口来调用实际的绘制功能，从而与具体的渲染平台解耦
 */

class Renderer
{
public:

    virtual ~Renderer() = default;

    virtual void DrawCircle(float x, float y, float radius) const = 0;

    virtual void DrawSquare(float x, float y, float side) const = 0;
    
};