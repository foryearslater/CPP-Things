#pragma once
#include <string>
#include <iostream>

#include "DvdPlayer.hpp"

/**
 * @class Amplifier
 * @brief 家庭影院子系统的一个组件：功放/放大器
 * @detail 负责音频的开关、音量控制、输入源选择等具体操作
 */
class Amplifier 
{
public:

    explicit Amplifier(const std::string& description);

    ~Amplifier();

    void On();

    void Off();

    void SetDvd(DvdPlayer* dvdPlayer); 

    void SetVolume(int volume);

    void SetSurroundSound();

    std::string GetDescription() const;

private:

    std::string m_description; 

};