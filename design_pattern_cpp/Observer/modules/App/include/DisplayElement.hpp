#pragma once
#include <iostream>

/**
 * @class DisplayElement
 * @brief 显示接口:定义了显示元素必须实现的操作
 * @detail 用于表示那些需要“显示”数据的观察者
 */
class DisplayElement
{
public:

    virtual ~DisplayElement() = default;

    virtual void Display() const = 0;
    
};