/**
 * @file MonsterFactory.hpp
 * @author nichenglong
 * @brief 定义了一个原型管理器，用于存储和克隆怪物原型
 * @version 0.1
 * @date 2025-08-01
 */
#pragma once
#include <map>
#include <string>
#include "Monster.hpp"

/**
 * @enum MonsterType
 * @brief 定义了可用的怪物类型枚举
 */

enum class MonsterType 
{
    SLIME,
    DRAGON
};

/**
 * @class MonsterFactory
 * @brief 原型管理器：存储一组原型对象，并提供一个接口来克隆它们
 *
 * @detail 客户端通过这个工厂，使用一个简单的标识
 * @detail 就能获取一个特定类型怪物的副本，而无需知道具体子类的名称
 */

class MonsterFactory
{
public:

    /**
     * @brief MonsterFactory 的构造函数。
     * @detail 在构造时，会创建并注册所有可用的怪物原型
     */

    MonsterFactory();

    /**
     * @brief 根据指定的类型来克隆一个怪物。
     * @param type 要克隆的怪物类型（MonsterType 枚举）。
     * @return std::unique_ptr<Monster> 指向新克隆的怪物实例
     */

    std::unique_ptr<Monster> CreateMonster(MonsterType type);

private:

    std::map<MonsterType, std::unique_ptr<Monster>> m_prototypes;

};