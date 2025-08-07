#pragma once
#include <string>

class MusicPlayer;

/**
 * @class PlayerState
 * @brief 抽象状态: 定义了所有播放器状态必须实现的接口
 * @detail 每个具体状态类将实现这些方法, 以定义在该状态下播放器的行为
 */

class PlayerState
{
public:
    virtual ~PlayerState() = default;

    virtual void Play(MusicPlayer *player) = 0;

    virtual void Pause(MusicPlayer *player) = 0;

    virtual void Stop(MusicPlayer *player) = 0;

    virtual std::string ToString() const = 0;
};