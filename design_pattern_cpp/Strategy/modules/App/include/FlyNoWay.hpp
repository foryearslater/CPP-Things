#pragma once
#include "FlyBehavior.hpp"

/**
 * @class FlyNoWay
 * @brief 具体飞行策略：表示根本不能飞行
 * @detail 实现了FlyBehavior接口，定义了不能飞行的行为
 */

class FlyNoWay : public FlyBehavior
{
public:
    FlyNoWay();

    ~FlyNoWay() override;

    void Fly() const override;
};