#pragma once
#include <iostream>
#include <string>
#include <memory>

#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"

class FlyBehavior;
class QuackBehavior;

/**
 * @class Duck
 * @brief 上下文: 表示鸭子, 它持有飞行和叫声策略的引用, 并委托它们执行行为
 * @detail 客户端只与Duck交互, 通过设置不同的策略来改变Duck的行为
 */

class Duck
{
public:
    explicit Duck(std::unique_ptr<FlyBehavior> flyBehavior,
                  std::unique_ptr<QuackBehavior> quackBehavior,
                  const std::string &type = "Generic Duck");

    virtual ~Duck();

    void PerformFly() const;

    void PerformQuack() const;

    void SetFlyBehavior(std::unique_ptr<FlyBehavior> newFlyBehavior);

    void SetQuackBehavior(std::unique_ptr<QuackBehavior> newQuackBehavior);

    virtual void Display() const;

private:
    std::unique_ptr<FlyBehavior> m_flyBehavior;

    std::unique_ptr<QuackBehavior> m_quackBehavior;
    
    std::string m_type;
};