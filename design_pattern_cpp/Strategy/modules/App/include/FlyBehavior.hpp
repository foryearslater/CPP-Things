#pragma once
#include <iostream>

/**
 * @class FlyBehavior
 * @brief 抽象策略：定义了鸭子飞行行为的接口
 * @detail 所有具体飞行行为类都必须实现此接口
 */
class FlyBehavior
{
public:

    virtual ~FlyBehavior() = default;

    virtual void Fly() const = 0;
    
};