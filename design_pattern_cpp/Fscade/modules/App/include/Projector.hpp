#pragma once
#include <string>
#include <iostream>

/**
 * @class Projector
 * @brief 家庭影院子系统的一个组件：投影仪
 * @detail 负责投影仪的开关、输入模式设置等具体操作
 */
class Projector 
{
public:

    explicit Projector(const std::string& description);

    ~Projector();

    void On();

    void Off();

    void WideScreenMode();

    void TvMode();

    std::string GetDescription() const;

private:

    std::string m_description; 

};