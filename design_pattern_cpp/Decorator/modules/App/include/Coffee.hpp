/**
 * @file Coffee.hpp
 * @author nichenglong
 * @brief 定义了组件接口，即所有咖啡对象的基类
 * @version 0.1
 * @date 2025-08-04
 */
#pragma once
#include <string>

/**
 * @class Coffee
 * @brief 组件接口：定义了可以被装饰器动态添加功能的对象的接口
 * @detail 在我们的例子中，无论是简单的咖啡还是加了各种调料的咖啡
 */

class Coffee
{
public:
 
    virtual ~Coffee() = default;

    virtual double GetCost() const = 0;

    virtual std::string GetDescription() const = 0;
    
};