/**
 * @file Tree.hpp
 * @author nichenglong
 * @brief 定义了客户端使用的 Tree 类，它包含外部状态
 * @version 0.1
 * @date 2025-08-05
 */

#pragma once
#include "TreeModel.hpp"

#include <memory>

/**
 * @class Tree
 * @brief 客户端上下文（Client Context）：存储外部状态并持有一个享元对象的引用
 * @detail 每棵独立的树都有自己独一无二的位置和大小,这些是“外部状态”,不能被共享
 * @detail 它不直接拥有重量级的模型数据，而是通过一个指针来引用共享的 TreeModel
 */

class Tree
{
public:

    Tree(float x, float y, float scale, std::shared_ptr<TreeModel> model);

    void Draw() const;

private:

    float m_x;

    float m_y;

    float m_scale;
    
    std::shared_ptr<TreeModel> m_model;

};