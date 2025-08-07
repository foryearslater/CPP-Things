#pragma once
#include <iostream>
#include <string>

/**
 * @class SandwichBuilder
 * @brief 抽象基类：定义了制作三明治的模板方法和抽象步骤
 * @detail 模板方法MakeSandwich()定义了制作三明治的通用算法骨架
 *
 */
class SandwichBuilder
{
public:
    virtual ~SandwichBuilder() = default;

    void MakeSandwich();

protected:
    void PrepareBread() const;

    virtual void AddMainIngredient() = 0;

    virtual void AddCondiments() = 0;

    virtual bool WantsVegetables() const { return true; }

    void AddVegetables() const;

    void WrapSandwich() const;
};