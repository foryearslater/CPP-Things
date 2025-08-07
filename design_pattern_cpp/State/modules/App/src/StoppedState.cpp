#include "StoppedState.hpp"

StoppedState::StoppedState()
{
    std::cout << "StoppedState created." << std::endl;
}

StoppedState::~StoppedState()
{
    std::cout << "StoppedState destroyed." << std::endl;
}

void StoppedState::Play(MusicPlayer *player)
{
    std::cout << "Starting playback." << std::endl;
    player->SetCurrentState(player->m_playingState);
}

void StoppedState::Pause(MusicPlayer *player)
{
    std::cout << "Cannot pause when stopped. Start playing first." << std::endl;
}

void StoppedState::Stop(MusicPlayer *player)
{
    std::cout << "Already stopped. No change." << std::endl;
}

std::string StoppedState::ToString() const
{
    return "Stopped";
}