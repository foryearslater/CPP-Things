/**
 * @file CoffeeDecorator.hpp
 * @author nichenglong
 * @brief 定义了抽象装饰器（Decorator）基类
 * @version 0.1
 * @date 2025-08-04
 */
#pragma once
#include "Coffee.hpp"
#include <memory>

/**
 * 
 * @class CoffeeDecorator
 * @brief 抽象装饰器（Decorator）：持有一个指向组件（Coffee）对象的引用，并实现了与组件相同的接口
 * @detail 它的核心作用是将请求转发给被包装的组件对象，并可以在转发前后
 * @detail 执行一些额外的操作，从而“装饰”该对象
 * 
 */
class CoffeeDecorator : public Coffee
{
public:

    CoffeeDecorator(std::shared_ptr<Coffee> coffee);

    double GetCost() const override;

    std::string GetDescription() const override;

protected:
    
    std::shared_ptr<Coffee> m_coffee;

};