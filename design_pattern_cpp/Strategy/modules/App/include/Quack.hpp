#pragma once
#include "QuackBehavior.hpp" 

/**
 * @class Quack
 * @brief 具体叫声策略：表示正常的鸭子叫声
 * @detail 实现了QuackBehavior接口，定义了具体的叫声行为
 */
class Quack : public QuackBehavior {
public:
   
    Quack();

    ~Quack() override;

    void QuackNow() const override;
};