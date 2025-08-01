/**
 * @file CharacterBuilder.hpp
 * @author nichenglong
 * @brief 定义了抽象建造者接口。
 * @version 0.1
 * @date 2025-08-01
 */
#pragma once
#include <memory>
#include "Character.hpp"

/**
 * @class CharacterBuilder
 * @brief 抽象建造者：为创建一个 Character 产品对象所需的各个部件指定抽象接口
 *
 * @detail 所有具体的建造者都必须实现这个接口
 */

class CharacterBuilder
{
public:
   

    virtual ~CharacterBuilder() = default;

    /**
     * @brief 获取最终构建好的角色产品
     * @return std::shared_ptr<Character> 指向构建完成的角色的智能指针
     */
    std::shared_ptr<Character> GetCharacter() 
    {
        return m_character;
    }

    /**
     * @brief 创建一个新的角色实例
     * @detail 在开始新一轮构建时调用
     */
    void CreateNewCharacter() 
    {
        m_character = std::make_shared<Character>();
    }

    virtual void BuildWeapon() = 0;

    virtual void BuildArmor() = 0;

    virtual void BuildSkill() = 0;

protected:

    std::shared_ptr<Character> m_character;

};