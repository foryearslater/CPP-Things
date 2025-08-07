#pragma once
#include <string>
#include <iostream>

/**
 * @class EditorMemento
 * @brief 备忘录:存储原发器（Editor）在某个时刻的内部状态
 * @detail 它是不可变的,通常只提供给原发器本身访问其内部状态的方法
 */
class EditorMemento
{
private:
    friend class Editor;

public:
    explicit EditorMemento(const std::string &text);

    ~EditorMemento();

private:
    std::string m_text;
};