#pragma once
#include <string>
#include <iostream>

/**
 * @class GarageDoor
 * @brief 接收者:知道如何执行实际操作的对象
 * @detail GarageDoor知道如何打开、关闭、上升、下降
 */

class GarageDoor 
{
public:

    explicit GarageDoor(const std::string& location);

    ~GarageDoor();

    void Up();

    void Down();

    void Stop();

    void LightOn();

    void LightOff();

private:

    std::string m_location; 
    
};