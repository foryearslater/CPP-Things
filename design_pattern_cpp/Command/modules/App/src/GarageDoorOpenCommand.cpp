#include "GarageDoorOpenCommand.hpp"


GarageDoorOpenCommand::GarageDoorOpenCommand(GarageDoor* garageDoor) : m_garageDoor(garageDoor) 
{
}

GarageDoorOpenCommand::~GarageDoorOpenCommand() 
{
}

void GarageDoorOpenCommand::Execute() 
{
    if (m_garageDoor) 
    {
        m_garageDoor->Up(); 
    }
}

void GarageDoorOpenCommand::Undo() 
{
    if (m_garageDoor) 
    {
        m_garageDoor->Down(); 
    }
}