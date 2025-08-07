#pragma once
#include <iostream>

class Subject;

/**
 * @class Observer
 * @brief 抽象观察者:定义了一个接口,用于接收主题的通知
 * @detail 所有具体观察者都必须实现此接口
 */
class Observer
{
public:

    virtual ~Observer() = default;

    virtual void Update() = 0;
    
};