#pragma once
#include <vector>
#include <memory> 
#include "Command.hpp" 
#include "NoCommand.hpp" 

/**
 * @class RemoteControl
 * @brief 调用者：持有命令对象, 并在需要时触发命令的执行
 * @detail 包含多个插槽, 每个插槽可以绑定一个命令
 */

class RemoteControl 
{
public:

    RemoteControl();

    ~RemoteControl();

    void SetCommand(int slot, std::unique_ptr<Command> onCommand, std::unique_ptr<Command> offCommand);

    void OnButtonWasPressed(int slot);

    void OffButtonWasPressed(int slot);

    void UndoButtonWasPressed();

private:

    static const int NUM_SLOTS = 7; 
    std::vector<std::unique_ptr<Command>> m_onCommands; 
    std::vector<std::unique_ptr<Command>> m_offCommands; //
    
    std::unique_ptr<Command> m_undoCommand; 

};