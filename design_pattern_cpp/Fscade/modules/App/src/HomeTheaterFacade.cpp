#include "HomeTheaterFacade.hpp"

HomeTheaterFacade::HomeTheaterFacade(DvdPlayer* dvdPlayer, Projector* projector, Amplifier* amplifier)
    : m_dvdPlayer(dvdPlayer), m_projector(projector), m_amplifier(amplifier) 
{
    std::cout << "HomeTheaterFacade created." << std::endl;
}

HomeTheaterFacade::~HomeTheaterFacade() 
{
    std::cout << "HomeTheaterFacade destroyed." << std::endl;
}

void HomeTheaterFacade::WatchMovie(const std::string& movie) 
{
    std::cout << "\nGet ready to watch a movie..." << std::endl;
    m_projector->On(); 
    m_projector->WideScreenMode(); 
    m_amplifier->On(); 
    m_amplifier->SetDvd(m_dvdPlayer); 
    m_amplifier->SetSurroundSound(); 
    m_amplifier->SetVolume(5);
    m_dvdPlayer->On(); 
    m_dvdPlayer->Play(movie); 
}

void HomeTheaterFacade::EndMovie() 
{
    std::cout << "\nShutting down movie theater..." << std::endl;
    m_dvdPlayer->Stop(); 
    m_dvdPlayer->Eject(); 
    m_dvdPlayer->Off(); 
    m_amplifier->Off(); 
    m_projector->Off(); 
}