/**
 * @file Character.hpp
 * @author nichenglong
 * @brief  角色类
 * @version 0.1
 * @date 2025-08-01
 */
#pragma once
#include <string>
#include <iostream>

/**
 * @class Character
 * @brief 具体产品：表示一个游戏角色
 *
 * @detail 这是一个复杂的对象，包含多个组成部分
 * @detail 建造者模式的目标就是为了分步、清晰地构建这样的对象
 */

class Character
{
public:

    /**
     * @brief 设置角色的武器。
     * @param weapon 武器的名称。
     */

    void SetWeapon(const std::string& weapon);

    /**
     * @brief 设置角色的盔甲。
     * @param armor 盔甲的名称。
     */

    void SetArmor(const std::string& armor);

    /**
     * @brief 设置角色的技能。
     * @param skill 技能的名称。
     */

    void SetSkill(const std::string& skill);

    /**
     * @brief 显示角色的所有配置信息。
     * @detail 用于验证角色是否被正确构建。
     */
    
    void Display() const;

private:

    std::string m_weapon;

    std::string m_armor;  

    std::string m_skill;  

};