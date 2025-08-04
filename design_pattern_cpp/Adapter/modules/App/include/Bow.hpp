#pragma once
#include "IWeapon.hpp" 

/**
 * @class Bow
 * @brief 具体产品：表示一个弓武器。
 * @detail 实现了IWeapon接口，定义了弓的特定使用行为
 */

class Bow : public IWeapon 
{
public:

    Bow();

    ~Bow() override;

    /**
     * @brief 使用弓进行攻击
     * @param target 攻击的目标名称
     * @return 描述弓攻击结果的字符串
     */

    std::string Attack(const std::string& target) const override;

};