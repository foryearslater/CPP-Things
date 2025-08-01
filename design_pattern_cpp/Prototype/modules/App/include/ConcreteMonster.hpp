/**
 * @file ConcreteMonsters.hpp
 * @author nichenglong
 * @brief 定义了具体的怪物原型，如史莱姆和龙
 * @version 0.1
 * @date 2025-08-01
 */
#pragma once
#include "Monster.hpp"
#include <iostream>

/**
 * @class Slime
 * @brief 具体原型：表示一个史莱姆怪物
 * @detail 实现了 Monster 接口，特别是clone()方法
 */

class Slime : public Monster
{
public:

    /**
     * @brief Slime 的构造函数
     * @param name 史莱姆的名字
     * @param health 史莱姆的生命值
     */

    Slime(const std::string& name, int health);
    
    /**
     * @brief 实现了克隆方法。
     * @detail 通过调用自身的拷贝构造函数来创建一个新的 Slime 实例
     * @return std::unique_ptr<Monster> 指向新创建的史莱姆副本
     */

    std::unique_ptr<Monster> Clone() const override;

    void Display() const override;

};


/**
 * @class Dragon
 * @brief 具体原型：表示一个龙怪物
 *
 * @detail 实现了 Monster 接口，并拥有一个额外的属性（火焰强度）
 */

class Dragon : public Monster
{
public:

    /**
     * @brief Dragon 的构造函数
     * @param name 龙的名字。
     * @param health 龙的生命值
     * @param fire_intensity 龙的火焰强度
     */

    Dragon(const std::string& name, int health, int fire_intensity);

    /**
     * @brief 实现了克隆方法
     * @detail 通过调用自身的拷贝构造函数来创建一个新的 Dragon 实例
     * @return std::unique_ptr<Monster> 指向新创建的龙副本
     */

    std::unique_ptr<Monster> Clone() const override;

    void Display() const override;

private:
   
    int m_fire_intensity;

};