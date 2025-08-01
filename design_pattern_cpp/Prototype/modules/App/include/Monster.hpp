/**
 * @file Monster.hpp
 * @author nichenglong
 * @brief 定义了抽象原型怪物的基类
 * @version 0.1
 * @date 2025-08-01
 */

#pragma once
#include <string>
#include <memory> 

/**
 * @class Monster
 * @brief 抽象原型：定义了所有可克隆对象的通用接口
 * @detail 核心是 clone()方法，所有子类都必须实现这个方法来创建自身的副本
 */

class Monster
{
public:
    
    virtual ~Monster() = default;

    virtual std::unique_ptr<Monster> Clone() const = 0;

    virtual void Display() const = 0;

protected:
   
    std::string m_name;

    int m_health;

};