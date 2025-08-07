#pragma once
#include "FlyBehavior.hpp"

/**
 * @class FlyWithWings
 * @brief 具体飞行策略：表示用翅膀飞行
 * @detail 实现了FlyBehavior接口，定义了具体飞行行为
 */

class FlyWithWings : public FlyBehavior
{
public:
    FlyWithWings();

    ~FlyWithWings() override;

    void Fly() const override;
};