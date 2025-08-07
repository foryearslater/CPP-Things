#include "PlayingState.hpp"

PlayingState::PlayingState()
{
    std::cout << "PlayingState created." << std::endl;
}

PlayingState::~PlayingState()
{
    std::cout << "PlayingState destroyed." << std::endl;
}

void PlayingState::Play(MusicPlayer *player)
{
    std::cout << "Already playing. No change." << std::endl;
}

void PlayingState::Pause(MusicPlayer *player)
{
    std::cout << "Pausing playback." << std::endl;

    player->SetCurrentState(player->m_pausedState);
}

void PlayingState::Stop(MusicPlayer *player)
{
    std::cout << "Stopping playback." << std::endl;
    player->SetCurrentState(player->m_stoppedState);
}

std::string PlayingState::ToString() const
{
    return "Playing";
}