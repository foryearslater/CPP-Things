#include "PausedState.hpp"

PausedState::PausedState()
{
    std::cout << "PausedState created." << std::endl;
}

PausedState::~PausedState()
{
    std::cout << "PausedState destroyed." << std::endl;
}

void PausedState::Play(MusicPlayer *player)
{
    std::cout << "Resuming playback." << std::endl;
    player->SetCurrentState(player->m_playingState);
}

void PausedState::Pause(MusicPlayer *player)
{
    std::cout << "Already paused. No change." << std::endl;
}

void PausedState::Stop(MusicPlayer *player)
{
    std::cout << "Stopping playback from paused state." << std::endl;
    player->SetCurrentState(player->m_stoppedState);
}

std::string PausedState::ToString() const
{
    return "Paused";
}