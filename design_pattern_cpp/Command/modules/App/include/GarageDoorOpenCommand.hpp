#pragma once
#include "Command.hpp"      
#include "GarageDoor.hpp"  

/**
 * @class GarageDoorOpenCommand
 * @brief 具体命令:封装了“打开车库门”的请求
 * @detail 实现了Command接口, 知道如何调用接收者GarageDoor的Up()方法
 */

class GarageDoorOpenCommand : public Command 
{
public:

    explicit GarageDoorOpenCommand(GarageDoor* garageDoor);

    ~GarageDoorOpenCommand() override;

    void Execute() override;

    void Undo() override;

private:

    GarageDoor* m_garageDoor;

};