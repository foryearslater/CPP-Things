#pragma once
#include <string>

/**
 * @class Command
 * @brief 抽象命令接口:定义了执行操作的接口
 * @detail 所有具体命令类都必须实现此接口
 */

class Command 
{
public:

    virtual ~Command() = default;

    virtual void Execute() = 0;
    
    virtual void Undo() = 0; 

};