#include "LightOffCommand.hpp"


LightOffCommand::LightOffCommand(Light* light) : m_light(light) 
{
}

LightOffCommand::~LightOffCommand() 
{
}


void LightOffCommand::Execute() 
{
    if (m_light) 
    {
        m_light->Off();
    }
}

void LightOffCommand::Undo() 
{
    if (m_light) 
    {
        m_light->On(); 
    }
}