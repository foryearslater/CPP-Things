/**
 * @file ConcreteRenderers.hpp
 * @author nichenglong
 * @brief 定义了具体的渲染器实现，如 OpenGL 和 DirectX。
 * @version 0.1
 * @date 2025-08-04
 */

#pragma once
#include "Renderer.hpp"
#include <iostream>

/**
 * @class OpenGLRenderer
 * @brief 具体实现：使用 OpenGL API 来进行绘制
 * @detail 实现了 Renderer 接口中定义的绘制方法
 */
class OpenGLRenderer : public Renderer
{
public:

    void DrawCircle(float x, float y, float radius) const override;

    void DrawSquare(float x, float y, float side) const override;
    
};


/**
 * @class DirectXRenderer
 * @brief 具体实现：使用 DirectX API 来进行绘制
 * @detail 实现了 Renderer 接口中定义的绘制方法
 */
class DirectXRenderer : public Renderer
{
public:

    void DrawCircle(float x, float y, float radius) const override;

    void DrawSquare(float x, float y, float side) const override;

};