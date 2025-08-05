#include "DvdPlayer.hpp"

DvdPlayer::DvdPlayer(const std::string& description) : m_description(description) 
{
    std::cout << m_description << " created." << std::endl;
}

DvdPlayer::~DvdPlayer() 
{
    std::cout << m_description << " destroyed." << std::endl;
}

void DvdPlayer::On() 
{
    std::cout << m_description << " turning on." << std::endl;
}

void DvdPlayer::Off() 
{
    std::cout << m_description << " turning off." << std::endl;
}

void DvdPlayer::Eject() 
{
    std::cout << m_description << " ejecting disc." << std::endl;
}

void DvdPlayer::Play(const std::string& movie) 
{
    std::cout << m_description << " playing \"" << movie << "\"." << std::endl;
}

void DvdPlayer::Stop() 
{
    std::cout << m_description << " stopping playback." << std::endl;
}

void DvdPlayer::SetSurroundAudio() 
{
    std::cout << m_description << " setting surround audio." << std::endl;
}


void DvdPlayer::SetTwoChannelAudio() 
{
    std::cout << m_description << " setting two channel audio." << std::endl;
}

std::string DvdPlayer::GetDescription() const 
{
    return m_description;
}