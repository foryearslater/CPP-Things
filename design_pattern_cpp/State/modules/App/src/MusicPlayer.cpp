#include "MusicPlayer.hpp"
#include "PlayingState.hpp" 
#include "PausedState.hpp"
#include "StoppedState.hpp"

MusicPlayer::MusicPlayer()
{
    std::cout << "MusicPlayer created." << std::endl;

    m_playingState = new PlayingState();
    m_pausedState = new PausedState();
    m_stoppedState = new StoppedState();

    m_currentState = m_stoppedState;
}

MusicPlayer::~MusicPlayer()
{
    std::cout << "MusicPlayer destroyed." << std::endl;

    delete m_playingState;
    delete m_pausedState;
    delete m_stoppedState;
}

void MusicPlayer::PressPlay()
{
    std::cout << "User pressed PLAY." << std::endl;
    m_currentState->Play(this);
    std::cout << "Player is now " << m_currentState->ToString() << std::endl
              << std::endl;
}

void MusicPlayer::PressPause()
{
    std::cout << "User pressed PAUSE." << std::endl;
    m_currentState->Pause(this);
    std::cout << "Player is now " << m_currentState->ToString() << std::endl
              << std::endl;
}

void MusicPlayer::PressStop()
{
    std::cout << "User pressed STOP." << std::endl;
    m_currentState->Stop(this);
    std::cout << "Player is now " << m_currentState->ToString() << std::endl
              << std::endl;
}

void MusicPlayer::SetCurrentState(PlayerState *state)
{
    m_currentState = state;
}

PlayerState *MusicPlayer::GetCurrentState() const
{
    return m_currentState;
}