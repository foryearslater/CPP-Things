#pragma once
#include <iostream>
#include <memory>

class PlayerState;
class PlayingState;
class PausedState;
class StoppedState;

/**
 * @class MusicPlayer
 * @brief 上下文：表示音乐播放器，它封装了所有状态，并维护一个指向当前状态对象的引用
 * @detail 客户端只与MusicPlayer交互，无需知道其内部状态切换的复杂性
 */

class MusicPlayer
{
public:
    MusicPlayer();

    ~MusicPlayer();

    void PressPlay();

    void PressPause();

    void PressStop();

    void SetCurrentState(PlayerState *state);

    PlayerState *GetCurrentState() const;

    PlayerState *m_playingState;

    PlayerState *m_pausedState;

    PlayerState *m_stoppedState;

private:

    PlayerState *m_currentState;

};