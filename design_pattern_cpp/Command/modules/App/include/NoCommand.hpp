#pragma once
#include "Command.hpp"
#include <iostream>

/**
 * @class NoCommand
 * @brief 空对象命令：一个什么都不做的命令
 * @detail 用于处理未设置命令的插槽，避免空指针检查
 */
class NoCommand : public Command 
{
public:

    NoCommand();

    ~NoCommand() override;

    void Execute() override;

    void Undo() override;
    
};