#pragma once
#include "Command.hpp" 
#include "Light.hpp"   

/**
 * @class LightOnCommand
 * @brief 具体命令:封装了“打开灯”的请求
 * @detail 实现了Command接口, 知道如何调用接收者Light的On()方法
 */
class LightOnCommand : public Command 
{
public:

    explicit LightOnCommand(Light* light);

    ~LightOnCommand() override;

    void Execute() override;

    void Undo() override;

private:

    Light* m_light; 

};