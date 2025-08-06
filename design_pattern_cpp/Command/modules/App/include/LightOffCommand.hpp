#pragma once
#include "Command.hpp" // 包含抽象命令接口
#include "Light.hpp"   // 包含接收者 Light

/**
 * @class LightOffCommand
 * @brief 具体命令：封装了“关闭灯”的请求
 * @detail 实现了Command接口, 知道如何调用接收者Light的Off()方法
 */
class LightOffCommand : public Command 
{
public:

    explicit LightOffCommand(Light* light);

    ~LightOffCommand() override;

    void Execute() override;

    void Undo() override;

private:

    Light* m_light;

};