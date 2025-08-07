#pragma once
#include "PlayerState.hpp"
#include "MusicPlayer.hpp"

/**
 * @class StoppedState
 * @brief 具体状态：表示播放器停止的状态
 * @detail 实现了PlayerState接口，定义了在该状态下，各种操作的具体行为
 */
class StoppedState : public PlayerState
{
public:
    StoppedState();

    ~StoppedState() override;

    void Play(MusicPlayer *player) override;

    void Pause(MusicPlayer *player) override;

    void Stop(MusicPlayer *player) override;

    std::string ToString() const override;
};