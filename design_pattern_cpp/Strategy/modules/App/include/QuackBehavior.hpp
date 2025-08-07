#pragma once
#include <iostream>

/**
 * @class QuackBehavior
 * @brief 抽象策略：定义了鸭子叫声行为的接口
 * @detail 所有具体叫声行为类都必须实现此接口
 */
class QuackBehavior
{
public:
    virtual ~QuackBehavior() = default;

    virtual void QuackNow() const = 0;
};