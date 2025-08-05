#pragma once
#include <memory> 

#include "DvdPlayer.hpp"
#include "Projector.hpp"
#include "Amplifier.hpp"

/**
 * @class HomeTheaterFacade
 * @brief 外观类：为家庭影院子系统提供一个简化的接口
 * @detail 隐藏了DvdPlayer, Projector, Amplifier等组件的复杂交互
 */
class HomeTheaterFacade 
{
public:
    HomeTheaterFacade(DvdPlayer* dvdPlayer, Projector* projector, Amplifier* amplifier);

    ~HomeTheaterFacade();

    void WatchMovie(const std::string& movie);

    void EndMovie();

private:

    DvdPlayer* m_dvdPlayer;
    Projector* m_projector;
    Amplifier* m_amplifier;

};