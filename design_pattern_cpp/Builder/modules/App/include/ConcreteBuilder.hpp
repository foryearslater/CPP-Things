/**
 * @file ConcreteBuilder.hpp
 * @author nichenglong
 * @brief 定义了具体的建造者类，如战士和法师
 * @version 0.1
 * @date 2025-08-01
 */
#pragma once
#include "CharacterBuilder.hpp"

/**
 * @class WarriorBuilder
 * @brief 具体建造者：构建一个战士角色
 *
 * @detail 实现了 CharacterBuilder 接口，为战士配置特定的武器、盔甲和技能
 */
class WarriorBuilder : public CharacterBuilder
{
public:

    /**
     * @brief 构建战士的武器：巨剑
     */

    void BuildWeapon() override;

    /**
     * @brief 构建战士的盔甲：板甲
     */

    void BuildArmor() override;

    /**
     * @brief 构建战士的技能：冲锋
     */

    void BuildSkill() override;

};


/**
 * @class MageBuilder
 * @brief 具体建造者：构建一个法师角色
 *
 * @detail 实现了 CharacterBuilder 接口，为法师配置特定的武器、盔甲和技能
 */
class MageBuilder : public CharacterBuilder
{
public:

    /**
     * @brief 构建法师的武器：法杖
     */
    
    void BuildWeapon() override;

    /**
     * @brief 构建法师的盔甲：布袍
     */

    void BuildArmor() override;

    /**
     * @brief 构建法师的技能：火球术
     */

    void BuildSkill() override;

};