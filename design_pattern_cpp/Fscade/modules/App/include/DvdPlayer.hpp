#pragma once
#include <string>
#include <iostream>
/**
 * @class DvdPlayer
 * @brief 家庭影院子系统的一个组件：DVD播放器
 * @detail 负责DVD的开关、播放、停止等具体操作
 */
class DvdPlayer 
{
public:
    
    explicit DvdPlayer(const std::string& description);

    ~DvdPlayer();

    void On();

    void Off();

    void Eject();

    void Play(const std::string& movie);

    void Stop();

    void SetSurroundAudio();

    void SetTwoChannelAudio();

    std::string GetDescription() const;

private:

    std::string m_description; 

};