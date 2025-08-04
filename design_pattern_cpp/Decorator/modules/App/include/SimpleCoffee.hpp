/**
 * @file SimpleCoffee.hpp
 * @author nichenglong
 * @brief 定义了具体组件（ConcreteComponent），即一杯普通的咖啡
 * @version 0.1
 * @date 2025-08-04
 */

#pragma once
#include "Coffee.hpp"

/**
 * @class SimpleCoffee
 * @brief 具体组件（ConcreteComponent）：定义了一个可以被装饰的具体对象
 * @detail 这是装饰链的起点
 */
class SimpleCoffee : public Coffee
{
public:
  
    double GetCost() const override;

    std::string GetDescription() const override;
    
};