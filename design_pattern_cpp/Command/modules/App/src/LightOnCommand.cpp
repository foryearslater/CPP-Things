#include "LightOnCommand.hpp"


LightOnCommand::LightOnCommand(Light* light) : m_light(light) 
{
}


LightOnCommand::~LightOnCommand() 
{
}

void LightOnCommand::Execute() 
{
    if (m_light) 
    {
        m_light->On(); 
    }
}

void LightOnCommand::Undo() 
{
    if (m_light) 
    {
        m_light->Off(); 
    }
}