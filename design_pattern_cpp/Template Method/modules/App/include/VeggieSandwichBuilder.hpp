#pragma once
#include "SandwichBuilder.hpp" // 继承抽象基类

/**
 * @class VeggieSandwichBuilder
 * @brief 具体类：表示素食三明治的建造者
 * @detail 实现了SandwichBuilder抽象基类中定义的抽象步骤，以制作素食三明治
 */
class VeggieSandwichBuilder : public SandwichBuilder
{
public:
    VeggieSandwichBuilder();

    ~VeggieSandwichBuilder() override;

protected:
    void AddMainIngredient() override;

    void AddCondiments() override;

    bool WantsVegetables() const override;
};