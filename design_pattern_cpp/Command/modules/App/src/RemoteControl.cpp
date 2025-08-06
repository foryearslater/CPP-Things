#include "RemoteControl.hpp"
#include <iostream>

RemoteControl::RemoteControl() 
{
    for (int i = 0; i < NUM_SLOTS; ++ i) 
    {
        m_onCommands.push_back(std::make_unique<NoCommand>());
        m_offCommands.push_back(std::make_unique<NoCommand>());
    }
    m_undoCommand = std::make_unique<NoCommand>(); 
    std::cout << "RemoteControl created." << std::endl;
}

RemoteControl::~RemoteControl() 
{
    std::cout << "RemoteControl destroyed." << std::endl;
}

void RemoteControl::SetCommand(int slot, std::unique_ptr<Command> onCommand, std::unique_ptr<Command> offCommand) 
{
    if (slot >= 0 && slot < NUM_SLOTS)
    {
        m_onCommands[slot] = std::move(onCommand);   
        m_offCommands[slot] = std::move(offCommand);
    } 
    else 
    {
        std::cerr << "Error: Invalid slot number " << slot << std::endl;
    }
}

void RemoteControl::OnButtonWasPressed(int slot) 
{
    if (slot >= 0 && slot < NUM_SLOTS) 
    {
        m_onCommands[slot]->Execute(); 
        m_undoCommand = std::move(m_onCommands[slot]);
        m_undoCommand = std::make_unique<NoCommand>(); 
    } 
    else 
    {
        std::cerr << "Error: Invalid slot number " << slot << std::endl;
    }
}

void RemoteControl::OffButtonWasPressed(int slot) 
{
    if (slot >= 0 && slot < NUM_SLOTS) 
    {
        m_offCommands[slot]->Execute(); 
        m_undoCommand = std::move(m_offCommands[slot]); 
    } 
    else 
    {
        std::cerr << "Error: Invalid slot number " << slot << std::endl;
    }
}

void RemoteControl::UndoButtonWasPressed() 
{
    std::cout << "--- Undo button pressed ---" << std::endl;
    m_undoCommand->Undo();
    std::cout << "--- Undo finished ---" << std::endl;
    m_undoCommand = std::make_unique<NoCommand>(); 
}