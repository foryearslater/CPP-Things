/**
 * @file CharacterDirector.hpp
 * @author nichenglong
 * @brief 定义了指挥者类。
 * @version 0.1
 * @date 2025-08-01
 */
#pragma once
#include "CharacterBuilder.hpp"

/**
 * @class CharacterDirector
 * @brief 指挥者：负责按照特定的步骤顺序来构建一个角色。
 *
 * @detail 它与具体的建造者解耦，
 * @detail 只依赖于抽象的 CharacterBuilder 接口。
 */

class CharacterDirector
{
public:

    /**
     * @brief 设置当前要使用的建造者。
     * @param builder 指向一个 CharacterBuilder 对象的智能指针。
     */

    void SetBuilder(std::shared_ptr<CharacterBuilder> builder);

    /**
     * @brief 获取构建完成的角色。
     * @return std::shared_ptr<Character> 指向构建完成的角色的智能指针。
     */

    std::shared_ptr<Character> GetCharacter();

    /**
     * @brief 执行构建过程。
     * @detail 按照“创建->武器->盔甲->技能”的顺序来构建一个完整的角色。
     */

    void ConstructCharacter();

private:

    std::shared_ptr<CharacterBuilder> m_builder; 

};