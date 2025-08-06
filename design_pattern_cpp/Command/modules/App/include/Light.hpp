#pragma once
#include <string>
#include <iostream>

/**
 * @class Light
 * @brief 接收者：知道如何执行实际操作的对象
 */

class Light 
{
public:

    explicit Light(const std::string& location);

    ~Light();

    void On();

    void Off();

private:

    std::string m_location; 

};