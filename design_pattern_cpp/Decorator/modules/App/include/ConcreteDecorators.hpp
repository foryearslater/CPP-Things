/**
 * @file ConcreteDecorators.hpp
 * @author nichenglong
 * @brief 定义了具体的装饰器，如牛奶和糖
 * @version 0.1
 * @date 2025-08-04
 */

#pragma once
#include "CoffeeDecorator.hpp"


/**
 * @class MilkDecorator
 * @brief 具体装饰器（ConcreteDecorator）：为咖啡添加牛奶
 * @detail 继承自 CoffeeDecorator，并重写了 getCost 和 getDescription 方法，以在被包装对象的基础上增加新的状态（成本和描述）
 */

class MilkDecorator : public CoffeeDecorator
{
public:
   
    MilkDecorator(std::shared_ptr<Coffee> coffee);

    double GetCost() const override;

    std::string GetDescription() const override;
};


/**
 * @class SugarDecorator
 * @brief 具体装饰器（ConcreteDecorator）：为咖啡添加糖
 * @detail 继承自 CoffeeDecorator，并重写了 getCost 和 getDescription 方法
 */

class SugarDecorator : public CoffeeDecorator
{
public:

    SugarDecorator(std::shared_ptr<Coffee> coffee);

    double GetCost() const override;

    std::string GetDescription() const override;

};