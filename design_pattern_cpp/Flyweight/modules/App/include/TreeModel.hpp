/**
 * @file TreeModel.hpp
 * @author nichenglong
 * @brief 定义了享元对象，即树的模型
 * @version 0.1
 * @date 2025-08-05
 */

#pragma once
#include <string>
#include <iostream>
#include <vector>

/**
 * @class TreeModel
 * @brief 享元:包含了可以被多个上下文共享的内部状态
 * @detail 树的模型是重量级的,且对于同一种类的树来说是相同的,适合作为享元被共享
 */
class TreeModel
{
public:
   
    TreeModel(const std::string& mesh, const std::string& texture);

    void Draw(float x, float y, float scale) const;

private:
   
    std::string m_mesh;

    std::string m_texture;

};