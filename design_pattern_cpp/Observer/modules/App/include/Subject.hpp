#pragma once
#include <vector>
#include <algorithm>

class Observer;

/**
 * @class Subject
 * @brief 抽象主题:定义了管理观察者的方法
 * @detail 所有具体主题都必须实现此接口, 以便观察者可以注册/注销并接收通知
 */
class Subject
{
public:

    virtual ~Subject() = default;

    virtual void RegisterObserver(Observer *o) = 0;

    virtual void RemoveObserver(Observer *o) = 0;

    virtual void NotifyObservers() = 0;
    
    std::vector<Observer*> m_observers;
};