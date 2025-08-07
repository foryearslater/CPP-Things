#pragma once
#include "QuackBehavior.hpp"

/**
 * @class MuteQuack
 * @brief 具体叫声策略：表示什么声音都发不出来
 * @detail 实现了QuackBehavior接口，定义了静音行为
 */
class MuteQuack : public QuackBehavior
{
public:

    MuteQuack();

    ~MuteQuack() override;

    void QuackNow() const override;

};