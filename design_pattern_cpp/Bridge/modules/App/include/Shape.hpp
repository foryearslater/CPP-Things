/**
 * @file Shape.hpp
 * @author nichenglong
 * @brief 定义了抽象基类，即形状
 * @version 0.1
 * @date 2025-08-04
 */
#pragma once
#include "Renderer.hpp"
#include <memory>

/**
 * @class Shape
 * @brief 抽象：定义了形状的抽象接口，并维护一个指向实现（Renderer）的引用
 * @detail 这是桥接模式的核心，它将高层逻辑（形状）与底层实现（渲染）连接起来
 */
class Shape
{
public:

    Shape(std::shared_ptr<Renderer> renderer);

    virtual ~Shape() = default;

    virtual void Draw() const = 0;

protected:

    /**
     * @brief 指向实现部分的桥梁
     * @detail 这是一个指向 Renderer 接口的智能指针，Shape 类通过它来执行实际的绘制操作
     */

    std::shared_ptr<Renderer> m_renderer;
};