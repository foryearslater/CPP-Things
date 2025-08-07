#pragma once
#include "SandwichBuilder.hpp" 

/**
 * @class ChickenSandwichBuilder
 * @brief 具体类：表示鸡肉三明治的建造者
 * @detail 实现了SandwichBuilder抽象基类中定义的抽象步骤，以制作鸡肉三明治
 */
class ChickenSandwichBuilder : public SandwichBuilder
{
public:
    ChickenSandwichBuilder();

    ~ChickenSandwichBuilder() override;

protected:
    void AddMainIngredient() override;

    void AddCondiments() override;
};